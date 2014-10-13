
#include "video.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define SCREEN_MAX_CHAR 1920
#define SCREEN_MAX_MEM 3840

#define BLACK          0x00
#define BLUE           0x01
#define GREEN          0x02
#define CYAN           0x03
#define RED            0x04
#define MAGENTA        0x05
#define BROWN          0x06
#define LIGHT_GRAY     0x07
#define DARK_GRAY      0x08
#define BRIGHT_BLUE    0x09
#define BRIGHT_GREEN   0x0A
#define BRIGHT_CYAN    0x0B
#define BRIGHT_RED     0x0C
#define BRIGHT_MAGENTA 0x0D
#define BRIGHT_YELLOW  0x0E
#define BRIGHT_WHITE   0x0F

char *vidaddress = (char*)0xb8000; 	//video mem begins here.

void clear()
{
  	char *vidptr = vidaddress;
	unsigned int i = 0;
	unsigned int j = 0;
	//clear all
	while(j < 80 * 25 * 2) {
		//blank character
		vidptr[j] = ' ';
		vidptr[j+1] = BRIGHT_YELLOW; 		
		j = j + 2;
	}
}

void showstring(char* message)
{
  	char *vidptr = vidaddress;
	unsigned int i = 0;
	unsigned int j = 0;
	while(message[j] != '\0') {
		vidptr[i] = message[j];
		vidptr[i+1] = BRIGHT_YELLOW;
		++j;
		i = i + 2;
	}
}
