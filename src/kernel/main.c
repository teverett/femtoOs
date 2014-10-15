
#include "monitor/monitor.h"

void main( void )
{
    char *str = "Hello from FemtoOs";
//	clear();
	monitor_write(str);

  for(;;); /* Keep the OS running */
}
