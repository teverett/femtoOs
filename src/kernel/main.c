
#include "monitor/monitor.h"
#include "kernel.h"

void main( void )
{
	monitor_write( "Hello from FemtoOs\n");
	monitor_write( "tge\n");


	for(;;); /* Keep the OS running */
}
