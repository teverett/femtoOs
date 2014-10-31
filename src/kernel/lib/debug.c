
#include "debug.h"
#include "../monitor.h"

void _debug(const char* message, const char* file, u32int line){
	monitor_write("DEBUG ");
	monitor_write(message);
	monitor_write(" at ");
	monitor_write(file);
	monitor_write(":");
	monitor_write_dec(line);
	monitor_write("\n");
}

void _debugi(const char* message, u32int n, const char* file, u32int line){
	monitor_write("DEBUG ");
	monitor_write(message);
	monitor_write(" : ");
	monitor_write_hex(n);
	monitor_write(" at ");
	monitor_write(file);
	monitor_write(":");
	monitor_write_dec(line);
	monitor_write("\n");

}