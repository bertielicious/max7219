/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 12 October 2020, 10:19
 */

#include "config.h"
#include "configPorts.h"
#include "configOsc.h"
#include "configSPI.h"
#include "init1_max7219.h"
#include "sendSPIbyte.h"
#include "splashScreen.h"
#include <xc.h>

void main(void) 
{
    uchar data, col, row = 0;
    configPorts();
    configOsc();
    configSPI();
    init1_max7219();
     for(row = 0; row <=8; row++)
        {
         col = 0;
            CS = 0;
        //  send_no_op_spi_byte();      // write to the upper matrix
            sendSPIbyte(row, col);      // send the address (row) to write to, followed by the data at *p1
            CS = 1;
           
        }
    
    for(row = 0; row <=8; row++)
        {
        col = 1 << row;
            CS = 0;
        //  send_no_op_spi_byte();      // write to the upper matrix
            sendSPIbyte(row+1, col);      // send the address (row) to write to, followed by the data at *p1
            CS = 1;
            __delay_ms(500);
        }
  //  splashScreen();
    while(1)
    {
        DIAGNOSTIC_LED = HI;
        __delay_ms(100);
        DIAGNOSTIC_LED = LO;
        __delay_ms(100);
      /*  for(data = 0; data < 256; data++)
        {
           
            CS = 0;
        //  send_no_op_spi_byte();      // write to the upper matrix
            sendSPIbyte(data/8, data);      // send the address (row) to write to, followed by the data at *p1
            CS = 1;
            __delay_ms(500);
        }*/
    
    }
    return;
}
