
#include "string.h"


int kstrcmp(char *str1, char *str2)
{
 	for(; *str1 == *str2; ++str1, ++str2)
        if(*str1 == 0)
            return 0;
    return *(unsigned char *)str1 < *(unsigned char *)str2 ? -1 : 1;
}

char* kstrcpy(char *dest, const char *src)
{
 	unsigned i;
  	for (i=0; src[i] != '\0'; ++i)
    	dest[i] = src[i];
  	dest[i] = '\0';
  	return dest;
}

char* kstrcat(char *dest, const char *src)
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