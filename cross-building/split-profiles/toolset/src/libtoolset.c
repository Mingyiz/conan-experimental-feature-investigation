#include "libtoolset.h"
#include <stdio.h>

#define VERSION "1.0.0"
#ifdef _MSC_VER
    #define OS  "Windows"
    
    #ifdef NDEBUG
        #define BUILD_TYPE "Release"
    #else
        #define BUILD_TYPE  "Debug"
    #endif
    
    
    #ifdef _WIN64
        #define ARCH "x86_64"
    #else ifdef _WIN32
        #define ARCH "x86"
    #endif
    
#endif


LIBTOOLSET_EXPORT toolset_info_t toolset_info()
{
    static const toolset_info_t info = { VERSION, OS, ARCH, BUILD_TYPE, BUILD_SHARED_LIBS };
    return info;
}

LIBTOOLSET_EXPORT void print_info()
{
    printf("toolset build information\n");
    printf("version: %s\n", VERSION);
    printf("os: %s\n", OS);
    printf("arch: %s\n", ARCH);
    printf("build_type: %s\n", BUILD_TYPE);
    printf("shared lib: %s\n", (BUILD_SHARED_LIBS ? "Yes": "No"));
}
