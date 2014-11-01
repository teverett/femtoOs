
#include "gpf.h"
#include "../lib/debug.h"
#include "isr.h"

static void gpf_callback(registers_t *regs)
{
	debug("gpf");
	for(;;);
}

void initialise_gpf_handler(){
    register_interrupt_handler(INT0D, &gpf_callback);
}