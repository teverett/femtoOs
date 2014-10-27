#ifndef IO_H
#define IO_H

#include "../lib/types.h"

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

#endif