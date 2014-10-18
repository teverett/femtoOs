
#include "monitor/monitor.h"
#include "kernel.h"
#include "gdt.h"
#include "idt.h"
#include "devices/timer/timer.h"
#include "devices/keyboard/keyboard.h"

void init ( void );

void main( void )
{
	monitor_write( "Starting FemtoOs\n");
	init();

	for(;;); /* Keep the OS running */
}

void init( void )
{
	monitor_write("Init GDT\n");
	init_gdt();
	monitor_write("Init IDT\n");
	init_idt();
	monitor_write("Init Timer\n");
	asm volatile("sti");
//	init_timer(50);
	monitor_write("Init Keyboard\n");
	init_keyboard();
	monitor_write("Init Completed\n");	
}

