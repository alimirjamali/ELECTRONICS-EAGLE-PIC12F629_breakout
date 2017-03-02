/*
 * File:   PIC12F629.c
 * Author: Ali Mirjamali
 *
 * Created on 28 February 2017, 21:59
 * This code creates a simple fading effect on LEDs connected to PIN 6 & 7
 */

#include <xc.h>

#define _XTAL_FREQ 4000000	// oscillator frequency (Using PIC12F629 internal clock)

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is GP3)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// Pausing for few cycles. I preferred this rather the __delay_ms function
void pause (int loops)
{
	for (int i=0;i<loops;i++);
}

void main(void)
{
	TRISIO = 0b00001000;	// All pins are output 
	GPIO = 0b00000000;		// All pins are low
	CMCON = 0b00000111;		// All pins are digital
	while(1)
	{
		for (int i=0;i<100;i++) 
		{
			GP0=1;
			GP1=0;
			pause(i<<3);
			GP0=0;
			GP1=1;
			pause((100-i)<<3);
		}
		for (int i=100;i>0;i--) 
		{
			GP0=1;
			GP1=0;
			pause(i<<3);
			GP0=0;
			GP1=1;
			pause((100-i)<<3);
		}
		__delay_ms(4000);
	}
	return;
}

