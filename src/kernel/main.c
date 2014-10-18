
#include "monitor/monitor.h"
#include "kernel.h"
#include "gdt.h"
#include "idt.h"

void init ( void );

void main( void )
{
	init();

	asm volatile ("int $0x3");
	asm volatile ("int $0x4");

	for(;;); /* Keep the OS running */
}

void init( void )
{
	monitor_write( "FemtoOs Init Started\n");
	monitor_write("Init GDT\n");
	init_gdt();
	monitor_write("Init IDT\n");
	init_idt();
	monitor_write("Init Completed\n");	
}

