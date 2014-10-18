
#include "mem.h"

// Copy len bytes from src to dest.
u8int* memcpy(u8int *dest, const u8int *src, u32int len)
{
    while (len--) {
         *dest++ = *src++;
    }
    return dest;
}

// Write len copies of val into dest.
u8int* memset(u8int *dest, u8int val, u32int len)
{
    while (len--) {
         *dest++ = val;
    }
    return dest;
}