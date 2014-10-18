
#include "monitor/monitor.h"
#include "kernel.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

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
	monitor_write("Init IDT\n");
	init_idt();
	monitor_write("Init Timer\n");
	asm volatile("sti");
	init_timer(50);
	monitor_write("Init Completed\n");	
}

