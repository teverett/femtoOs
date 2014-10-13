
#include "video.h"

void clear()
{
  	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;
	//clear all
	while(j < 80 * 25 * 2) {
		//blank character
		vidptr[j] = ' ';
		//attribute-byte: light grey on black screen	
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}
}

void showstring(char* message)
{
  	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;
	while(message[j] != '\0') {
		vidptr[i] = message[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
}
