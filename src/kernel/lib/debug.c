
#include "debug.h"
#include "../monitor.h"

void debug(const char* message){
	monitor_write(message);
}