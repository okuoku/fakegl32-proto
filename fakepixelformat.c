#include <windows.h>
#include <string.h>

void
fill_fakepixelformat(void* out, long pfd_size){
    PIXELFORMATDESCRIPTOR pfd;

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = 0; /* don't care in wined3d */
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 8;
    pfd.cRedBits = 8;
    pfd.cRedShift = 0;
    pfd.cGreenBits = 8;
    pfd.cGreenShift = 8;
    pfd.cBlueBits = 8;
    pfd.cBlueShift = 16;
    pfd.cAlphaBits = 8;
    pfd.cAlphaShift = 24;
    pfd.cAccumBits = 0;
    pfd.cAccumRedBits = 0;
    pfd.cAccumGreenBits = 0;
    pfd.cAccumBlueBits = 0;
    pfd.cAccumAlphaBits = 0;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.cAuxBuffers = 0;
    pfd.iLayerType = 0; /* unused */
    pfd.bReserved = 0; /* unused */
    pfd.dwLayerMask = 0; /* unused */
    pfd.dwVisibleMask = 0; /* unused */
    pfd.dwDamageMask = 0; /* unused */

    memcpy(out, &pfd, pfd_size);
}
