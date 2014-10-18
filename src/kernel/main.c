
#include "monitor/monitor.h"
#include "kernel.h"
#include "gdt.h"

void init ( void );

void main( void )
{
	init();
	for(;;); /* Keep the OS running */
}

void init( void )
{
	monitor_write( "FemtoOs Init Started\n");
	monitor_write("Init GDT\n");
	init_gdt();
	monitor_write("Init Completed\n");	
}

