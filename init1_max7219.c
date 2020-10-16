#include "config.h"
#include "sendSPIbyte.h"
void init1_max7219(void)
{
 CS = 0;
 sendSPIbyte (normal_operation_addr,shut_down_data);//leave shutdown mode and enter normal operation
 CS = 1;

 CS = 0;
 sendSPIbyte (display_intensity_addr,display_intensity_data);// minimum display intensity 1/32
 CS = 1;

 CS = 0;
 sendSPIbyte (decode_off_addr,decode_off_data); // decode mode off
 CS = 1;

 CS = 0;
sendSPIbyte (scan_limit_addr,scan_limit_data); // scan limit = 8 digits multiplexed
 CS = 1; // LOAD is high

 CS = 0;
sendSPIbyte (normal_operation_addr,normal_operation_data);//leave shutdown mode and enter normal                                                         //operation
 CS = 1;
}
