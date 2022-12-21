#define EXPORT __declspec(dllexport) __stdcall 

#define dummyGLUAPIs(x) \
	x(gluUnProject) \
	x(gluBeginCurve) \
	x(gluBeginPolygon) \
	x(gluBeginSurface) \
	x(gluBeginTrim) \
	x(gluBuild1DMipmaps) \
	x(gluBuild2DMipmaps) \
	x(gluCylinder) \
	x(gluDeleteNurbsRenderer) \
	x(gluDeleteQuadric) \
	x(gluDeleteTess) \
	x(gluDisk) \
	x(gluEndCurve) \
	x(gluEndPolygon) \
	x(gluEndSurface) \
	x(gluEndTrim) \
	x(gluErrorString) \
	x(gluErrorUnicodeStringEXT) \
	x(gluGetNurbsProperty) \
	x(gluGetString) \
	x(gluGetTessProperty) \
	x(gluLoadSamplingMatrices) \
	x(gluLookAt) \
	x(gluNewNurbsRenderer) \
	x(gluNewQuadric) \
	x(gluNewTess) \
	x(gluNextContour) \
	x(gluNurbsCallback) \
	x(gluNurbsCurve) \
	x(gluNurbsProperty) \
	x(gluNurbsSurface) \
	x(gluOrtho2D) \
	x(gluPartialDisk) \
	x(gluPerspective) \
	x(gluPickMatrix) \
	x(gluProject) \
	x(gluPwlCurve) \
	x(gluQuadricCallback) \
	x(gluQuadricDrawStyle) \
	x(gluQuadricNormals) \
	x(gluQuadricOrientation) \
	x(gluQuadricTexture) \
	x(gluScaleImage) \
	x(gluSphere) \
	x(gluTessBeginContour) \
	x(gluTessBeginPolygon) \
	x(gluTessCallback) \
	x(gluTessEndContour) \
	x(gluTessEndPolygon) \
	x(gluTessNormal) \
	x(gluTessProperty) \
	x(gluTessVertex)

#define adddummy(name) \
    void EXPORT name(void){}

extern "C" {

dummyGLUAPIs(adddummy)

}
