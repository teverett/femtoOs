// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"
#include "i386/descriptor_tables.h"
#include "timer.h"
#include "i386/paging.h"
#include "i386/multiboot.h"
#include "fs.h"
#include "initrd.h"
#include "i386/task.h"
#include "i386/syscall.h"
#include "lib/debug.h"
#include "i386/gpf.h"

u32int initial_esp;

int main(struct multiboot *mboot_ptr, u32int initial_stack)
{
    // Initialise the screen (by clearing it)
    monitor_clear();

    monitor_write("FemtoOs Kernel starting\n");

    initial_esp = initial_stack;

    // Initialise all the ISRs and segmentation
    init_descriptor_tables();

    // enable interrupts    
    asm volatile("sti");

    // install gpf handler
    initialise_gpf_handler();

    // Initialise the PIT

    init_timer();

    debugi("Initial ESP",initial_esp );


    // Start paging.
    initialise_paging();

    // Start multitasking.
    initialise_tasking();

    // set up syscalls
    initialise_syscalls();

    debug("Switching to user mode");
    switch_to_user_mode();

   for(;;){}

  //  syscall_monitor_write("Hello, user world!\n");

    return 0;
}

