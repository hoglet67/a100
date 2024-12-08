/*
 * File:   main.c
 * Author: dan1138
 * Target: PIC16F628A
 * Compiler: XC8 v2.45
 * IDE: MPLABX v6.15
 *
 * Created on May 3, 2024, 2:11 PM
 * 
 * Description:
 * 
 *  Uses AC162049-2 (Universal Programming Module 2)
 *  PICkit5, supplies power. (DO NOT CONNECT 9VDC TO AC162049-2)
 *  RB5 connected to LED0
 *  RB4 connected to LED1
 */

/* Define the system oscillator frequency this code will setup */
#define _XTAL_FREQ (7372800ul)

// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define BAUDRATE 115200

void InitUART()
{
	TRISB2 = 0;   					// TX Pin
	TRISB1 = 1;   					// RX Pin
	
	SPBRG = ((_XTAL_FREQ/16)/BAUDRATE) - 1;
	BRGH  = 1;                   	// Fast baudrate
	SYNC  = 0;						// Asynchronous
	SPEN  = 1;						// Enable serial port pins
	CREN  = 1;						// Enable reception
	SREN  = 0;						// No effect
	TXIE  = 0;						// Disable tx interrupts
	RCIE  = 1;						// Enable rx interrupts
	TX9   = 0;						// 8-bit transmission
	RX9   = 0;						// 8-bit reception
	TXEN  = 0;						// Reset transmitter
	TXEN  = 1;						// Enable the transmitter
}


void SendByteSerially(unsigned char Byte)  // Writes a character to the serial port
{
	while(!TXIF);  // wait for previous transmission to finish
	TXREG = Byte;
}

void SendStringSerially(const unsigned char* st)
{
	while(*st)
		SendByteSerially(*st++);
}



void main(void) 
{
    INTCON = 0;
    PORTB = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB5 = 0;
    
    
    InitUART();

    PORTBbits.RB5 = 1;
    __delay_ms(500);
    PORTBbits.RB5 = 0;
        
    __delay_ms(10000);
    
    SendStringSerially("sys reboot\r");

    PORTBbits.RB5 = 1;
    __delay_ms(250);
    PORTBbits.RB5 = 0;
    __delay_ms(250);
    PORTBbits.RB5 = 1;
    __delay_ms(250);
    PORTBbits.RB5 = 0;
    __delay_ms(250);

    while (1);
}