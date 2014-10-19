
#include "keyboard.h"	
#include "../../isr.h"
#include "../monitor/monitor.h"
#include "../../io.h"

const u8int OUTPUT_BUFFER=0x60;

static void keyboard_callback(registers_t *regs)
{
	int status;
	int scanCode;
	
	scanCode = inb(OUTPUT_BUFFER);
	monitor_write_hex(scanCode);
}

void init_keyboard()
{
    register_interrupt_handler(IRQ1, &keyboard_callback);
}
