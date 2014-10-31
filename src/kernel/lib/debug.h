#ifndef DEBUG_H
#define DEBUG_H

#include "types.h"

#define debug(message) _debug(message, __FILE__, __LINE__)
#define debugi(message, num) _debugi(message, num, __FILE__, __LINE__)

void _debug(const char* message, const char* file, u32int line);
void _debugi(const char* message, u32int n, const char* file, u32int line);

#endif