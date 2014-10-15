#ifndef MEM_H
#define MEM_H

#include "types.h"

u8int* kmemcpy(u8int *dest, const u8int *src, u32int len);
u8int* kmemset(u8int *dest, u8int val, u32int len);

#endif
