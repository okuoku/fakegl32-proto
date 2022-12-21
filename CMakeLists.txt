cmake_minimum_required(VERSION 3.0)
project(fakegl C CXX)

if(MSVC)
    add_compile_options(/MP)
endif()

set(angledep ${CMAKE_CURRENT_LIST_DIR}/yfrmbase)

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

add_subdirectory(${angledep}/ext/cwgl/angle-static-cmake angle)

# Configure gl4es
set(STATICLIB ON CACHE BOOL "" FORCE)
set(NO_LOADER ON CACHE BOOL "" FORCE)
set(NOX11 ON CACHE BOOL "" FORCE)
set(NOEGL ON CACHE BOOL "" FORCE)

add_definitions(-DGL4ES_COMPILE_FOR_USE_IN_SHARED_LIB)
add_subdirectory(gl4es)
include_directories(${angledep}/ext/cwgl/angle/include
    # VMA
    ${ANGLE_VMA_ROOT}/include
    ${ANGLE_VULKAN_HEADERS_ROOT}/include)

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
    SPIRV-Tools-static
    glslang
    my-glslang-default-resource-limits
    SPIRV
    angle_static)

