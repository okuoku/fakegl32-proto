/* FIXME: HACK */
#define VK_PLATFORM_H_
#define VKAPI_ATTR
#define VKAPI_CALL /* It seems ANGLE built with cdecl */
#define VKAPI_PTR 
#include <stdint.h>
/* ~HACK */

#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

