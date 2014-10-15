
#include "monitor/monitor.h"
#include "kernel.h"

void main( void )
{
	monitor_write( "Hello from FemtoOs\n");
	monitor_write( "tge\n");

	char* hello = "Hello from ";
	char* osname = "FemtoOs";
	char* cr = "\n";

	char* str = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	kstrcpy(str, hello);
	kstrcat(str, osname);
	kstrcat(str, cr);

	monitor_write(str);

	for(;;); /* Keep the OS running */
}
