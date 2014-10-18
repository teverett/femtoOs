// timer.c -- Initialises the PIT, and handles clock updates.
//            Written for JamesM's kernel development tutorials.

#include "rtc.h"
#include "../../isr.h"
#include "../../monitor/monitor.h"
#include "../../io.h"

static void rtc_callback(registers_t *regs)
{
  //  switch_task();
   monitor_write(".");
//   monitor_write_dec(tick);
//   monitor_write("\n");
}

void init_rtc()
{
    register_interrupt_handler(IRQ8, &rtc_callback);
}
