cmake_minimum_required(VERSION 3.0)
project(fakegl C CXX)

if(NOT USE_ANGLE)
    set(USE_CWGL_GLUE ON)
else()
    set(USE_CWGL_GLUE OFF)
endif()
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)

if(MSVC)
    add_compile_options(/MP)
endif()

set(angledep ${CMAKE_CURRENT_LIST_DIR}/yfrmbase)

if(USE_CWGL_GLUE)
    set(YFRM_CWGL_USE_ANGLE ON)
    set(YFRM_CWGL_USE_VULKAN ON)
    set(YFRM_BUILD_MODULE ON)
    # FIXME: It's overkill as we now have dedicated EGL decl. for this
    add_definitions(-DKHRONOS_STATIC) # FIXME: Move this to yfrmbase?
    if(COPY_TARGET)
        set(YFRM_DEBUG_COPY ${COPY_TARGET})
    endif()
    add_subdirectory(yfrmbase)
else()
    # Configure SPIR-V
    set(SPIRV_WERROR OFF CACHE BOOL "" FORCE)
    set(SPIRV-Headers_SOURCE_DIR ${angledep}/ext/cwgl/SPIRV-Headers)
    set(SKIP_GLSLANG_INSTALL OFF CACHE BOOL "" FORCE)
    set(ENABLE_GLSLANG_BINARIES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${angledep}/ext/cwgl/glslang glslang)

    # Workaround for glslang-default-resource-limits
    set(glslang-resource-limits-srcs
        ${angledep}/ext/cwgl/glslang/StandAlone/ResourceLimits.cpp
        ${angledep}/ext/cwgl/glslang/StandAlone/resource_limits_c.cpp)
    include_directories(${angledep}/ext/cwgl/glslang)
    add_library(my-glslang-default-resource-limits STATIC
        ${glslang-resource-limits-srcs})

    set(SKIP_SPIRV_TOOLS_INSTALL OFF CACHE BOOL "" FORCE)
    set(SPIRV_SKIP_EXECUTABLES ON CACHE BOOL "" FORCE)
    add_subdirectory(${angledep}/ext/cwgl/SPIRV-Tools SPIRV-Tools)

    if(YFRM_CWGL_USE_METAL OR YFRM_CWGL_EXPERIMENTAL_TRACKER)
        set(SPIRV_CROSS_CLI OFF CACHE BOOL "" FORCE)
        set(SPIRV_CROSS_SKIP_INSTALL ON CACHE BOOL "" FORCE)
        add_subdirectory(ext/cwgl/SPIRV-Cross SPIRV-Cross)
    endif()

    # Configure ANGLE
    set(ANGLE_BACKEND Vulkan)
    set(ANGLE_SPIRV_HEADERS_ROOT ${angledep}/ext/cwgl/SPIRV-Headers)
    set(ANGLE_VULKAN_HEADERS_ROOT ${angledep}/ext/cwgl/Vulkan-Headers)
    set(ANGLE_SPIRV_TOOLS_ROOT ${angledep}/ext/cwgl/SPIRV-Tools)
    set(ANGLE_VOLK_ROOT ${angledep}/ext/cwgl/volk) # Vulkan only?
    set(ANGLE_VMA_ROOT ${angledep}/ext/cwgl/VulkanMemoryAllocator) # Vulkan only?
    set(ANGLE_GLSLANG_ROOT ${angledep}/ext/cwgl/glslang)
    set(ANGLE_SPIRV_CROSS_ROOT ${angledep}/ext/cwgl/SPIRV-Cross)
    set(ANGLE_ROOT ${angledep}/ext/cwgl/angle)
    set(CHROMIUM_ZLIB_ROOT ${angledep}/ext/cwgl/chromium-zlib)

    set(ANGLE_EXCLUDE_ENTRYPOINTS ON)

    add_subdirectory(${angledep}/ext/cwgl/angle-static-cmake angle)
endif()

# Configure gl4es
set(STATICLIB ON CACHE BOOL "" FORCE)
set(NO_LOADER ON CACHE BOOL "" FORCE)
set(NOX11 ON CACHE BOOL "" FORCE)
set(NOEGL ON CACHE BOOL "" FORCE)

add_definitions(-DGL4ES_COMPILE_FOR_USE_IN_SHARED_LIB)
add_subdirectory(gl4es)
include_directories(${angledep}/ext/cwgl/angle/include)

if(USE_CWGL_GLUE)
    include_directories(yfrmbase/yuniframe/include)
    add_library(cwgl_glue SHARED
        # Glue logics(GLES)
        cwgl-glue/src/glue-s2.c
        cwgl-glue/src/glue-s3.c
        cwgl-glue/src/glue-s4.c
        cwgl-glue/src/glue-s5.c
        cwgl-glue/src/glue-s6.c
        cwgl-glue/src/glue-snone.c

        # Glue logic(EGL)
        cwgl-glue/src/glue-functbl.c
        cwgl-glue/src/glue-egl.c

        # Context
        cwgl-glue/src/glue-ctx.c
        )
    target_link_libraries(cwgl_glue PRIVATE yfrm)
    set(gles_libs cwgl_glue)
else()
    # FIXME: Do we still need this?
    include_directories(
        # VMA
        ${ANGLE_VMA_ROOT}/include
        ${ANGLE_VULKAN_HEADERS_ROOT}/include)
    set(gles_libs
        SPIRV-Tools-static
        glslang
        my-glslang-default-resource-limits
        SPIRV
        angle_static)
endif()

add_library(glu32 SHARED
    GLU32.def
    dummy.cpp)

add_library(fakeopengl32 MODULE 
    OpenGL32.def
    console.c
    fakepixelformat.c
    dll.c)

target_link_libraries(fakeopengl32
    glu32
    OPENGL32
    ${gles_libs})

if(USE_CWGL_GLUE)
    add_custom_target(__force_deploy
        ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:glu32> "${COPY_TARGET}/glu32.dll"
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:fakeopengl32> "${COPY_TARGET}/opengl32.dll"
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:yfrm> "${COPY_TARGET}/yfrm.dll"
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:cwgl_glue> "${COPY_TARGET}/cwgl_glue.dll"
        DEPENDS glu32 fakeopengl32 cwgl_glue yfrm)
else()
    add_custom_target(__force_deploy_noglue
        ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:glu32> "${COPY_TARGET}/glu32.dll"
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:yfrm> "${COPY_TARGET}/yfrm.dll"
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:fakeopengl32> "${COPY_TARGET}/opengl32.dll"
        DEPENDS glu32 fakeopengl32 yfrm)
endif()

if(COPY_TARGET)
    message(STATUS "Adding copy target to ${COPY_TARGET}")
    add_custom_command(TARGET glu32 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:glu32> "${COPY_TARGET}/glu32.dll"
        COMMENT "Installing (fake) GLU32.dll to ${COPY_TARGET}/glu32.dll")
    add_custom_command(TARGET fakeopengl32 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:fakeopengl32> "${COPY_TARGET}/opengl32.dll"
        COMMENT "Installing (fake) OPENGL32.dll to ${COPY_TARGET}/opengl32.dll")
    if(USE_CWGL_GLUE)
        add_custom_command(TARGET cwgl_glue POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:cwgl_glue> "${COPY_TARGET}/cwgl_glue.dll"
            COMMENT "Installing (fake) cwgl_glue.dll to ${COPY_TARGET}/cwgl_glue.dll")
    endif()
endif()
