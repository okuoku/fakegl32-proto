#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

#define EGLAPI
#define EGLAPIENTRY __stdcall
#define EGL_NO_PLATFORM_SPECIFIC_TYPES
#include <EGL/egl.h>
#define EXPORT __declspec(dllexport) __stdcall

void __stdcall gl4es_glDisable(int);
void __stdcall gl4es_glEnable(int);
void* __stdcall gl4es_GetProcAddress(const char* name);


/* GL1.0 calls */

void EXPORT glDisable(int x){
    gl4es_glDisable(x);
}

void EXPORT glEnable(int x){
    gl4es_glEnable(x);
}

/* WGL: Context */
typedef struct __tag__glrc {
    uintptr_t hDC;
    EGLDisplay disp;
    EGLSurface surf;
    EGLContext ctx;
}glrc;
static glrc* current_context;
static int initialized = 0;


static void
ensure_glinit(void){
    if(! initialized){
        initialized = 1;
    }
}

uintptr_t EXPORT wglCreateContext(uintptr_t hdc){
    EGLint ver0, ver1;
    EGLConfig cfg;
    EGLint numcfg;
    EGLint attr[] = {
        EGL_BUFFER_SIZE, 0,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 0,
        EGL_COLOR_BUFFER_TYPE, EGL_RGB_BUFFER,
        EGL_DEPTH_SIZE, EGL_DONT_CARE,
        EGL_LEVEL, 0,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_SAMPLE_BUFFERS, 0,
        EGL_SAMPLES, 0,
        EGL_STENCIL_SIZE, 0,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_TRANSPARENT_TYPE, EGL_NONE,
        EGL_TRANSPARENT_RED_VALUE, EGL_DONT_CARE,
        EGL_TRANSPARENT_GREEN_VALUE, EGL_DONT_CARE,
        EGL_TRANSPARENT_BLUE_VALUE, EGL_DONT_CARE,
        EGL_CONFIG_CAVEAT, EGL_DONT_CARE,
        EGL_CONFIG_ID, EGL_DONT_CARE,
        EGL_MAX_SWAP_INTERVAL, EGL_DONT_CARE,
        EGL_MIN_SWAP_INTERVAL, EGL_DONT_CARE,
        EGL_NATIVE_RENDERABLE, EGL_DONT_CARE,
        EGL_NATIVE_VISUAL_TYPE, EGL_DONT_CARE,
        EGL_NONE
    };
    EGLint ctxattr[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,  /* ES2 */
        EGL_NONE
    };
    glrc* r = malloc(sizeof(glrc));
    r->hDC = hdc;
    r->disp = eglGetDisplay(hdc);
    eglInitialize(r->disp, &ver0, &ver1);
    eglBindAPI(EGL_OPENGL_ES_API);
    eglChooseConfig(r->disp, attr, &cfg, 1, &numcfg);
    r->surf = eglCreateWindowSurface(r->disp, cfg, hdc, attr);
    r->ctx = eglCreateContext(r->disp, cfg, NULL, ctxattr);

    return (uintptr_t)r;
}

int EXPORT wglMakeCurrent(uintptr_t hdc, uintptr_t ptr){
    glrc* r;
    r = (glrc*)ptr;
    if(ptr){
        /* FIXME: Check hdc compatibility */
        current_context = r;
        eglMakeCurrent(r->disp, r->surf, r->surf, r->ctx);
    }else{
        /* FIXME: Uncurrent EGL here */
        current_context = NULL;
    }
    return 1;
}

uintptr_t EXPORT wglGetCurrentDC(void){
    if(current_context){
        return (uintptr_t)current_context->hDC;
    }else{
        return 0;
    }
}

uintptr_t EXPORT wglGetCurrentContext(void){
    return (uintptr_t)current_context;
}

int EXPORT wglDeleteContext(uintptr_t ptr){
    /* FIXME: Check if its bound to other thread */
    current_context = NULL;
    if(ptr){
        free((void*)ptr);
    }
    return 1;
}




/* WGL: Loader */
uintptr_t EXPORT wglGetProcAddress(const char* name){
    void* p;
    ensure_glinit();
    p = gl4es_GetProcAddress(name);
    printf("GL4ES GetProcAddress(%s) = %p\n",name,p);
    return (uintptr_t)p;
}

/* WGL: Share lists */
int EXPORT wglShareLists(uintptr_t p1, uintptr_t p2){
    printf("UNIMPL: wglShareLists\n");
    return 1;
}

/* WGL: Pixel formats */
/* FIXME: Fake implementation just satisfies wined3d(require 32bit ARGB) */
int EXPORT wglChoosePixelFormat(uintptr_t hdc, uintptr_t p){
    printf("FAKE: wglChoosePixelFormat\n");
    return 1;
}

int EXPORT wglDescribePixelFormat(void){
    printf("DUMMY: wglDescribePixelFormat (did nothing)\n");
    return 0;
}

int EXPORT wglSetPixelFormat(void){
    printf("DUMMY: wglSetPixelFormat (did nothing)\n");
    return 0;
}



