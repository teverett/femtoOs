//
// isr.h -- Interface and structures for high level interrupt service routines.
//          Part of this code is modified from Bran's kernel development tutorials.
//          Rewritten for JamesM's kernel development tutorials.
//

#include "types.h"

#define IRQ0 32		// timer
#define IRQ1 33		// keyboard
#define IRQ2 34		// cascade
#define IRQ3 35		// serial 2
#define IRQ4 36		// serial 1
#define IRQ5 37		// parallel 2
#define IRQ6 38		// diskette
#define IRQ7 39		// parallel 1
#define IRQ8 40		// RTC
#define IRQ9 41		// 
#define IRQ10 42	// reserved
#define IRQ11 43	// reserved
#define IRQ12 44	// reserved
#define IRQ13 45	// FPU
#define IRQ14 46	// hard disk
#define IRQ15 47	// reserved

typedef struct registers
{
    u32int ds;                  // Data segment selector
    u32int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    u32int int_no, err_code;    // Interrupt number and error code (if applicable)
    u32int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

// Enables registration of callbacks for interrupts or IRQs.
// For IRQs, to ease confusion, use the #defines above as the
// first parameter.
typedef void (*isr_t)(registers_t*);
void register_interrupt_handler(u8int n, isr_t handler);
