#ifndef STRING_H
#define STRING_H

#include "types.h"

s8int kstrcmp(s8int *str1, s8int *str2);
s8int* kstrcpy(s8int *dest, const s8int *src);
s8int* kstrcat(s8int *dest, const s8int *src);
u32int kstrlen(s8int* str);

#endif
