#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

#define EGLAPI
#define EGLAPIENTRY __stdcall
#define EGL_NO_PLATFORM_SPECIFIC_TYPES
#include <EGL/egl.h>
#define EXPORT __declspec(dllexport) __stdcall

void initialize_gl4es(void);
void close_gl4es(void);

void __stdcall gl4es_glDisable(int);
void __stdcall gl4es_glEnable(int);
void* __stdcall gl4es_GetProcAddress(const char* name);

void __stdcall gl4es_glHint(int x, int y);
void __stdcall gl4es_glFinish(void);
int __stdcall gl4es_glGetError(void);
long __stdcall gl4es_glGetString(int x);
void __stdcall gl4es_glGetIntegerv(int x, void* out);
void __stdcall gl4es_glGetFloatv(int x, void* out);
void __stdcall gl4es_glBegin(int p);
void __stdcall gl4es_glEnd(void);
void __stdcall gl4es_glVertex3f(float x, float y, float z);
void __stdcall gl4es_glVertex3fv(float* f);
void __stdcall gl4es_glVertex4s(short x, short y, short z, short w);
void __stdcall gl4es_glVertex4fv(float* f);
void __stdcall gl4es_glColor4ub(uint8_t x, uint8_t y, uint8_t z, uint8_t w);
void __stdcall gl4es_glClear(int mask);
void __stdcall gl4es_glClearColor(float red, float green, float blue, float alpha);
void __stdcall gl4es_glViewport(float x, float y, float z, float w);
void __stdcall gl4es_glFogf(int p, float x);
void __stdcall gl4es_glFogfv(int p, float* x);
void __stdcall gl4es_glFogi(int p, int x);
void __stdcall gl4es_glGenTextures(size_t n, void* tex);
void __stdcall gl4es_glDeleteTextures(size_t n, void* tex);
void __stdcall gl4es_glBindTexture(int x, int y);
void __stdcall gl4es_glTexParameteri(int x, int y, int z);
void __stdcall gl4es_glGetTexLevelParameteriv(int target, int level, int name, void* p);
void __stdcall gl4es_glTexImage2D(int target, int level, int internalformat,
                         size_t width, size_t height, int border,
                         int format, int type, void* pixels);

void __stdcall gl4es_glTexSubImage2D(int target, int level, int xoffset, int yoffset,
                            size_t width, size_t height, int format, int type,
                            void* pixels);

void __stdcall gl4es_glGetTexImage(int target, int level, int format, int type,
                          void* pixels);

void __stdcall gl4es_glDisableClientState(int e);
void __stdcall gl4es_glEnableClientState(int e);
void __stdcall gl4es_glClearDepthf(float f); // No ClearDepth ??
void __stdcall gl4es_glClearStencil(int s);
void __stdcall gl4es_glColor4f(float r, float g, float b, float a);
void __stdcall gl4es_glColorMask(int r, int g, int b, int a);
void __stdcall gl4es_glColorPointer(int s, int type, size_t stride, void* ptr);
void __stdcall gl4es_glDrawArrays(int mode, int first, size_t count);
void __stdcall gl4es_glDrawBuffer(int mode);
void __stdcall gl4es_glDrawElements(int mode, size_t count, int type, void* ptr);
void __stdcall gl4es_glFlush(void);
void __stdcall gl4es_glLightModeli(int name, int p);
void __stdcall gl4es_glLoadIdentity(void);
void __stdcall gl4es_glLoadMatrixd(double* p);
void __stdcall gl4es_glMaterialfv(int face, int p, float* ptr);
void __stdcall gl4es_glMatrixMode(int p);
void __stdcall gl4es_glNormal3f(float x, float y, float z);
void __stdcall gl4es_glNormalPointer(int type, size_t stride, void* ptr);
void __stdcall gl4es_glPixelStorei(int name, int p);
void __stdcall gl4es_glReadBuffer(int p);
void __stdcall gl4es_glScissor(int x, int y, size_t w, size_t h);
void __stdcall gl4es_glTexCoord3fv(float* p);
void __stdcall gl4es_glTexCoord4f(float s, float t, float r, float q);
void __stdcall gl4es_glTexCoordPointer(int size, int type, size_t stride, void* ptr);
void __stdcall gl4es_glTexEnvf(int target, int name, float p);
void __stdcall gl4es_glTexEnvi(int target, int name, int p);
void __stdcall gl4es_glVertex2i(int x, int y);
void __stdcall gl4es_glVertexPointer(int size, int type, size_t stride, void* ptr);

void __stdcall gl4es_glBlendFunc(int s, int d);
void __stdcall gl4es_glPolygonOffset(float f, float u);
void __stdcall gl4es_glReadPixels(int x, int y, size_t width, size_t height, int format, int type, void* ptr);
void __stdcall gl4es_glTexCoord2f(float x, float y);
void __stdcall gl4es_glTexImage1D(int target, int level, int internalformat, size_t width, int border, int format, int type, void* ptr);
void __stdcall gl4es_glVertex2f(float x, float y);

void __stdcall gl4es_glColor3fv(float* f);
void __stdcall gl4es_glColor4fv(float* f);
void __stdcall gl4es_glColor4sv(short* v);
void __stdcall gl4es_glColor4ubv(uint8_t* v);
void __stdcall gl4es_glColor4usv(unsigned short* v);
void __stdcall gl4es_glNormal3fv(float* f);
void __stdcall gl4es_glVertex2sv(float* f);
void __stdcall gl4es_glVertex4f(float x, float y, float z, float w);

void __stdcall gl4es_glAlphaFunc(int func, float ref);
void __stdcall gl4es_glClipPlane(int p, double* ptr);
void __stdcall gl4es_glColorMaterial(int f, int mode);
void __stdcall gl4es_glCullFace(int mode);
void __stdcall gl4es_glDepthFunc(int func);
void __stdcall gl4es_glDepthMask(int b);
void __stdcall gl4es_glDepthRange(double n, double f);
void __stdcall gl4es_glFrontFace(int m);
void __stdcall gl4es_glLightModelfv(int p, float* ptr);
void __stdcall gl4es_glLightf(int l, int p, float f);
void __stdcall gl4es_glLightfv(int l, int p, float* ptr);
void __stdcall gl4es_glLineStipple(int f, unsigned short pat);
void __stdcall gl4es_glLoadMatrixf(float* ptr);
void __stdcall gl4es_glMaterialf(int face, int pname, float param);
void __stdcall gl4es_glPointSize(float f);
void __stdcall gl4es_glPolygonMode(int f, int m);
void __stdcall gl4es_glPopMatrix(void);
void __stdcall gl4es_glPushMatrix(void);
void __stdcall gl4es_glShadeModel(int mode);
void __stdcall gl4es_glStencilFunc(int m, int ref, int mask);
void __stdcall gl4es_glStencilMask(int mask);
void __stdcall gl4es_glStencilOp(int fail, int zfail, int zpass);
void __stdcall gl4es_glTexEnvfv(int target, int param, float* params);
void __stdcall gl4es_glTexGenfv(int c, int p, float* params);
void __stdcall gl4es_glTexGeni(int c, int p, int param);

/* GL1.0 calls */

void EXPORT glDisable(int x){
    gl4es_glDisable(x);
}

void EXPORT glEnable(int x){
    gl4es_glEnable(x);
}

void EXPORT glHint(int x, int y){
    gl4es_glHint(x, y);
}

void EXPORT glFinish(void){
    gl4es_glFinish();
}

int EXPORT glGetError(void){
    return gl4es_glGetError();
}

long EXPORT glGetString(int x){
    return gl4es_glGetString(x);
}

void EXPORT glGetIntegerv(int x, void* out){
    gl4es_glGetIntegerv(x, out);
}

void EXPORT glGetFloatv(int x, void* out){
    gl4es_glGetFloatv(x, out);
}

void EXPORT glBegin(int p){
    gl4es_glBegin(p);
}

void EXPORT glEnd(void){
    gl4es_glEnd();
}

void EXPORT glVertex3f(float x, float y, float z){
    gl4es_glVertex3f(x, y, z);
}

void EXPORT glVertex3fv(float* f){
    gl4es_glVertex3fv(f);
}

void EXPORT glVertex4s(short x, short y, short z, short w){
    gl4es_glVertex4s(x, y, z, w);
}

void EXPORT glVertex4fv(float* f){
    gl4es_glVertex4fv(f);
}

void EXPORT glColor4ub(uint8_t x, uint8_t y, uint8_t z, uint8_t w){
    gl4es_glColor4ub(x, y, z, w);
}

void EXPORT glClear(int mask){
    gl4es_glClear(mask);
}

void EXPORT glClearColor(float red, float green, float blue, float alpha){
    gl4es_glClearColor(red, green, blue, alpha);
}

void EXPORT glViewport(float x, float y, float z, float w){
    gl4es_glViewport(x,y,z,w);
}

void EXPORT glFogf(int p, float x){
    gl4es_glFogf(p, x);
}

void EXPORT glFogfv(int p, float* x){
    gl4es_glFogfv(p, x);
}

void EXPORT glFogi(int p, int x){
    gl4es_glFogi(p, x);
}

void EXPORT glGenTextures(size_t n, void* tex){
    gl4es_glGenTextures(n, tex);
}

void EXPORT glDeleteTextures(size_t n, void* tex){
    gl4es_glDeleteTextures(n, tex);
}

void EXPORT glBindTexture(int x, int y){
    gl4es_glBindTexture(x, y);
}

void EXPORT glTexParameteri(int x, int y, int z){
    gl4es_glTexParameteri(x, y, z);
}

void EXPORT glGetTexLevelParameteriv(int target, int level, int name, void* p){
    gl4es_glGetTexLevelParameteriv(target, level, name, p);
}

void EXPORT glTexImage2D(int target, int level, int internalformat,
                         size_t width, size_t height, int border,
                         int format, int type, void* pixels){
    gl4es_glTexImage2D(target, level, internalformat,
                       width, height, border, 
                       format, type, pixels);
}

void EXPORT glTexSubImage2D(int target, int level, int xoffset, int yoffset,
                            size_t width, size_t height, int format, int type,
                            void* pixels){
    gl4es_glTexSubImage2D(target, level, xoffset, yoffset,
                          width, height, format, type, pixels);
}

void EXPORT glGetTexImage(int target, int level, int format, int type,
                          void* pixels){
    gl4es_glGetTexImage(target, level, format, type, pixels);
}

/* gl_context in wine */

void EXPORT glDisableClientState(int e){
    gl4es_glDisableClientState(e);
}

void EXPORT glEnableClientState(int e){
    gl4es_glEnableClientState(e);
}

void EXPORT glClearDepth(double f){
    gl4es_glClearDepthf(f);
}

void EXPORT glClearStencil(int s){
    gl4es_glClearStencil(s);
}

void EXPORT glColor4f(float r, float g, float b, float a){
    gl4es_glColor4f(r, g, b, a);
}

void EXPORT glColorMask(int r, int g, int b, int a){
    gl4es_glColorMask(r, g, b, a);
}

void EXPORT glColorPointer(int s, int type, size_t stride, void* ptr){
    gl4es_glColorPointer(s, type, stride, ptr);
}

void EXPORT glDrawArrays(int mode, int first, size_t count){
    gl4es_glDrawArrays(mode, first, count);
}

void EXPORT glDrawBuffer(int mode){
    gl4es_glDrawBuffer(mode);
}

void EXPORT glDrawElements(int mode, size_t count, int type, void* ptr){
    gl4es_glDrawElements(mode, count, type, ptr);
}

void EXPORT glFlush(void){
    gl4es_glFlush();
}

void EXPORT glLightModeli(int name, int p){
    gl4es_glLightModeli(name, p);
}

void EXPORT glLoadIdentity(void){
    gl4es_glLoadIdentity();
}

void EXPORT glLoadMatrixd(double* p){
    gl4es_glLoadMatrixd(p);
}

void EXPORT glMaterialfv(int face, int p, float* ptr){
    gl4es_glMaterialfv(face, p, ptr);
}

void EXPORT glMatrixMode(int p){
    gl4es_glMatrixMode(p);
}

void EXPORT glNormal3f(float x, float y, float z){
    gl4es_glNormal3f(x, y, z);
}

void EXPORT glNormalPointer(int type, size_t stride, void* ptr){
    gl4es_glNormalPointer(type, stride, ptr);
}

void EXPORT glPixelStorei(int name, int p){
    gl4es_glPixelStorei(name, p);
}

void EXPORT glReadBuffer(int p){
    gl4es_glReadBuffer(p);
}

void EXPORT glScissor(int x, int y, size_t w, size_t h){
    gl4es_glScissor(x, y, w, h);
}

void EXPORT glTexCoord3fv(float* p){
    gl4es_glTexCoord3fv(p);
}

void EXPORT glTexCoord4f(float s, float t, float r, float q){
    gl4es_glTexCoord4f(s, t, r, q);
}

void EXPORT glTexCoordPointer(int size, int type, size_t stride, void* ptr){
    gl4es_glTexCoordPointer(size, type, stride, ptr);
}

void EXPORT glTexEnvf(int target, int name, float p){
    gl4es_glTexEnvf(target, name, p);
}

void EXPORT glTexEnvi(int target, int name, int p){
    gl4es_glTexEnvi(target, name, p);
}

void EXPORT glVertex2i(int x, int y){
    gl4es_glVertex2i(x, y);
}

void EXPORT glVertexPointer(int size, int type, size_t stride, void* ptr){
    gl4es_glVertexPointer(size, type, stride, ptr);
}

/* util in wine */

void EXPORT glBlendFunc(int s, int d){
    gl4es_glBlendFunc(s, d);
}

void EXPORT glPolygonOffset(float f, float u){
    gl4es_glPolygonOffset(f, u);
}

void EXPORT glReadPixels(int x, int y, size_t width, size_t height, int format, int type, void* ptr){
    gl4es_glReadPixels(x, y, width, height, format, type, ptr);
}

void EXPORT glTexCoord2f(float x, float y){
    /* Not found in MS reference ..? */
    gl4es_glTexCoord2f(x, y);
}

void EXPORT glTexImage1D(int target, int level, int internalformat, size_t width, int border, int format, int type, void* ptr){
    gl4es_glTexImage1D(target, level, internalformat, width, border, format, type, ptr);
}

void EXPORT glVertex2f(float x, float y){
    gl4es_glVertex2f(x, y);
}

/* more adapter in wine */

void EXPORT glColor3fv(float* f){
    gl4es_glColor3fv(f);
}

void EXPORT glColor4fv(float* f){
    gl4es_glColor4fv(f);
}

void EXPORT glColor4sv(short* v){
    gl4es_glColor4sv(v);
}

void EXPORT glColor4ubv(uint8_t* v){
    gl4es_glColor4ubv(v);
}

void EXPORT glColor4usv(unsigned short* v){
    gl4es_glColor4usv(v);
}

void EXPORT glNormal3fv(float* f){
    gl4es_glNormal3fv(f);
}

void EXPORT glVertex2sv(float* f){
    gl4es_glVertex2sv(f);
}

void EXPORT glVertex4f(float x, float y, float z, float w){
    gl4es_glVertex4f(x, y, z, w);
}

/* state in wine */

void EXPORT glAlphaFunc(int func, float ref){
    gl4es_glAlphaFunc(func, ref);
}

void EXPORT glClipPlane(int p, double* ptr){
    gl4es_glClipPlane(p, ptr);
}

void EXPORT glColorMaterial(int f, int mode){
    gl4es_glColorMaterial(f, mode);
}

void EXPORT glCullFace(int mode){
    gl4es_glCullFace(mode);
}

void EXPORT glDepthFunc(int func){
    gl4es_glDepthFunc(func);
}

void EXPORT glDepthMask(int b){
    gl4es_glDepthMask(b);
}

void EXPORT glDepthRange(double n, double f){
    gl4es_glDepthRange(n, f);
}

void EXPORT glFrontFace(int m){
    gl4es_glFrontFace(m);
}

void EXPORT glLightModelfv(int p, float* ptr){
    gl4es_glLightModelfv(p, ptr);
}

void EXPORT glLightf(int l, int p, float f){
    gl4es_glLightf(l, p, f);
}

void EXPORT glLightfv(int l, int p, float* ptr){
    gl4es_glLightfv(l, p, ptr);
}
void EXPORT glLineStipple(int f, unsigned short pat){
    gl4es_glLineStipple(f, pat);
}

void EXPORT glLoadMatrixf(float* ptr){
    gl4es_glLoadMatrixf(ptr);
}

void EXPORT glMaterialf(int face, int pname, float param){
    gl4es_glMaterialf(face, pname, param);
}

void EXPORT glPointSize(float f){
    gl4es_glPointSize(f);
}

void EXPORT glPolygonMode(int f, int m){
    gl4es_glPolygonMode(f, m);
}

void EXPORT glPopMatrix(void){
    gl4es_glPopMatrix();
}

void EXPORT glPushMatrix(void){
    gl4es_glPushMatrix();
}

void EXPORT glShadeModel(int mode){
    gl4es_glShadeModel(mode);
}

void EXPORT glStencilFunc(int m, int ref, int mask){
    gl4es_glStencilFunc(m, ref, mask);
}

void EXPORT glStencilMask(int mask){
    gl4es_glStencilMask(mask);
}

void EXPORT glStencilOp(int fail, int zfail, int zpass){
    gl4es_glStencilOp(fail, zfail, zpass);
}

void EXPORT glTexEnvfv(int target, int param, float* params){
    gl4es_glTexEnvfv(target, param, params);
}

void EXPORT glTexGenfv(int c, int p, float* params){
    gl4es_glTexGenfv(c, p, params);
}

void EXPORT glTexGeni(int c, int p, int param){
    gl4es_glTexGeni(c, p, param);
}



/* WGL: Context */
typedef struct __tag__glrc {
    uintptr_t hDC;
    EGLDisplay disp;
    EGLSurface surf;
    EGLContext ctx;
}glrc;
static glrc* current_context;
static EGLContext global_egl_context = 0;
static int initialized = 0;


void initconsole(void);
void set_getprocaddress(void* func); /* gl4es */

static uintptr_t __stdcall
my_getprocaddress(const char* name){
    void* p;
    p = eglGetProcAddress(name);
    return (uintptr_t)p;
}

static void
ensure_glinit(void){
    initconsole();
    if(! initialized){
        set_getprocaddress(my_getprocaddress);
        initialize_gl4es();
        initialized = 1;
    }
}

uintptr_t __stdcall WindowFromDC(uintptr_t dc);

uintptr_t EXPORT wglCreateContext(uintptr_t hdc){
    uintptr_t hwnd;
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
        EGL_DEPTH_SIZE, 24,
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
    EGLint wndattr[] = {
        // https://github.com/google/angle/blob/main/extensions/EGL_ANGLE_surface_orientation.txt
        0x33a8, 2,
        EGL_NONE
    };
    EGLint ctxattr[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,  /* ES2 */
        EGL_NONE
    };

    glrc* r = malloc(sizeof(glrc));
    r->hDC = hdc;
    hwnd = WindowFromDC(hdc);
    // FIXME: Perhaps we have to instantiate display with hDC instead
    r->disp = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    //r->disp = eglGetDisplay(hdc);
    if(! global_egl_context){
        eglInitialize(r->disp, &ver0, &ver1);
        eglBindAPI(EGL_OPENGL_ES_API);
    }
    eglChooseConfig(r->disp, attr, &cfg, 1, &numcfg);
    // FIXME: Choose EGL_RENDER_BUFFER: EGL_BACK_BUFFER (but it's default)
    //        And maybe EGL_SWAP_INTERVAL_ANGLE??
    r->surf = eglCreateWindowSurface(r->disp, cfg, hwnd, &wndattr);

    // FIXME: gl4es can only hold a context at once
    if(! global_egl_context){
        global_egl_context = eglCreateContext(r->disp, cfg, NULL, ctxattr);
    }
    r->ctx = global_egl_context;

    // FIXME: Make it current immediately so we can resolve
    //        APIs now
    eglMakeCurrent(r->disp, r->surf, r->surf, r->ctx);

    if(initialized){
        close_gl4es();
        initialized = 0;
    }

    ensure_glinit();

    return (uintptr_t)r;
}

int EXPORT wglMakeCurrent(uintptr_t hdc, uintptr_t ptr){
    glrc* r;
    r = (glrc*)ptr;
    if(ptr){
        /* FIXME: Check hdc compatibility */
        current_context = r;
        if(hdc != r->hDC){
            printf("ERR: wrong hDC %lx vs. %lx\n",hdc,r->hDC);
        }
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

void fill_fakepixelformat(void* out, long pfd_size);

int EXPORT wglDescribePixelFormat(uintptr_t hdc, int idx, int bytes, void* ptr){
    printf("DUMMY: wglDescribePixelFormat (filled fixed value)\n");
    fill_fakepixelformat(ptr, bytes);
    return 1; /* Max idx */
}

int EXPORT wglSetPixelFormat(uintptr_t hdc, int fmt, uintptr_t p){
    printf("DUMMY: wglSetPixelFormat (did nothing)\n");
    // Returning zero leads corrupting EBX register...
    return 1;
}

int EXPORT wglGetPixelFormat(uintptr_t hdc, int fmt, uintptr_t p){
    printf("DUMMY: wglGetPixelFormat (did nothing)\n");
    // Returning zero leads corrupting EBX register...
    return 1;
}

int EXPORT wglSwapBuffers(uintptr_t hdc){
    if(current_context){
        printf("DUMMY: wglSwapBuffers\n");
        printf("SWAP: %lx:%lx:%lx / %lx:%lx:%lx\n", 
               (long)eglGetCurrentContext(),
               (long)eglGetCurrentDisplay(),
               (long)eglGetCurrentSurface(EGL_DRAW),
               (long)current_context->ctx,
               (long)current_context->disp,
               (long)current_context->surf);
        eglSwapBuffers(current_context->disp, current_context->surf);
    }else{
        printf("DUMMY: wglSwapBuffers (did nothing)\n");
    }
    return 1;
}

