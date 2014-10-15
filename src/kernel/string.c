
#include "string.h"

s8int kstrcmp(s8int *str1, s8int *str2)
{
  for(; *str1 == *str2; ++str1, ++str2)
    if(*str1 == 0)
        return 0;
  return *(u8int *)str1 < *(u8int *)str2 ? -1 : 1;
}

s8int* kstrcpy(s8int *dest, const s8int *src)
{
  u32int i;
    for (i=0; src[i] != '\0'; ++i)
      dest[i] = src[i];
  dest[i] = '\0';
  return dest;
}

s8int* kstrcat(s8int *dest, const s8int *src)
{
	while(*dest)
    dest++;
 
  while(*src)
  {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
  return dest;
}

u32int kstrlen(s8int* str)
{
  u32int c = 0;
 
  while(*(str+c))
    c++;
 
  return c;
}