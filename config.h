/* 
 * File:   config.h
 * Author: Phil Glazzard
 *
 * Created on 12 October 2020, 10:16
 */

#ifndef CONFIG_H
#define	CONFIG_H

// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdbool.h>
#define _XTAL_FREQ 16000000
#define DIAGNOSTIC_LED PORTAbits.RA5   // pin 2
#define SCK PORTBbits.RB6   // pin 11
#define SDO PORTCbits.RC7   // pin 9
#define CS PORTCbits.RC6    // pin 8
enum status {LO, HI};
typedef unsigned char uchar;

//**********************SPI CONSTANTS***********************************************

#define normal_operation_addr 0x0C //normal operation mode hi byte
#define shut_down_data 0x00       // shutdown mode hi byte
#define normal_operation_data 0x01 //normal operation mode lo byte
#define decode_off_addr 0x09 // no BCD decoding needed hi byte
#define decode_off_data 0x00 // no BCD decoding needed lo byte
#define scan_limit_addr 0x0B // display 8 columns of leds hi byte
#define scan_limit_data 0x07 // display 8 columns of leds lo byte
#define display_intensity_addr 0x0A // minimum display intensity hi byte
#define display_intensity_data 0x00 // minimum display intensity lo byte
#define no_op_addr 0x00 // No operation address
#define no_op_data 0x00 // No operation data

#endif	/* CONFIG_H */

