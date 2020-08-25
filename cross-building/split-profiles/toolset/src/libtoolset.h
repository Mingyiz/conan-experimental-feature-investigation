#ifndef _LIBTOOLSET_H_
#define _LIBTOOLSET_H_
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif


#ifdef WIN32
  #define LIBTOOLSET_EXPORT __declspec(dllexport)
#else
  #define LIBTOOLSET_EXPORT
#endif



typedef struct toolset_info_t 
{
  const char* version;
  const char* os;
  const char* arch;
  const char* build_type;
  bool        shared;
} toolset_info_t;

LIBTOOLSET_EXPORT toolset_info_t toolset_info();
LIBTOOLSET_EXPORT void print_info();



 
#ifdef __cplusplus
}
#endif

#endif // !_LIBTOOLSET_H_ 