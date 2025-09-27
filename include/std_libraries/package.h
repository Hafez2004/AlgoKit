// Include standard C libraries

#ifndef PACKAGE_H
#define PACKAGE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CHAR_ sizeof(char)
#define _UCHAR_ sizeof(unsigned char)
#define _SHORT_ sizeof(short)
#define _USHORT_ sizeof(unsigned short)
#define _INT_ sizeof(int)
#define _UINT_ sizeof(unsigned int)
#define _LONG_ sizeof(long)
#define _ULONG_ sizeof(unsigned long)
#define _LLONG_ sizeof(long long)
#define _ULLONG_ sizeof(unsigned long long)
#define _FLOAT_ sizeof(float)
#define _DOUBLE_ sizeof(double)
#define _LDOUBLE_ sizeof(long double)

#define PTR(val, type)  (&(type){val})

typedef enum{
    _char_,
    _short_,
    _int_,
    _float_,
    _double_,
    _long_,
    _long_double_
}dataType;


#ifdef __cplusplus
}
#endif
#endif //PACKAGE_H