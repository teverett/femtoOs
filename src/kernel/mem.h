
#ifndef MEM_H
#define MEM_H

#include "types.h"

void memset(u8int *dest, u8int val, u32int len);
void memcpy(u8int *dest, const u8int *src, u32int len);

#endif