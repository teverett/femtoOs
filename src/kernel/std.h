#ifndef STD_H
#define STD_H

#include "types.h"

// Copy len bytes from src to dest.
void memcpy(u8int *dest, const u8int *src, u32int len);
void memset(u8int *dest, u8int val, u32int len);
int strcmp(char *str1, char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

#endif
