
#include "gpf.h"
#include "../lib/debug.h"
#include "isr.h"
#include "../lib/assert.h"
#include "../monitor.h"

static void gpf_callback(registers_t *regs){
    u32int faulting_address;
    asm volatile("mov %%cr2, %0" : "=r" (faulting_address));
    // Output an error message.
    monitor_write("GPF! ( ");
    monitor_write(") at 0x");
    monitor_write_hex(faulting_address);
    monitor_write(" - EIP: ");
    monitor_write_hex(regs->eip);
    monitor_write("\n");
    PANIC("gpf");
}

void initialise_gpf_handler(){
    register_interrupt_handler(INT0D, &gpf_callback);
}