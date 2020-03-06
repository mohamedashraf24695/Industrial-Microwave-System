
#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

/* IF You Are using AVR ATMEGA16 , please remove the #define PIC_MICRO_ACTIVE 
 If you use PIC16f877a , please keep #define PIC_MICRO_ACTIVE under that comment
 directly. 
 */

#define PIC_MICRO_ACTIVE


#ifndef PIC_MICRO_ACTIVE

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif  


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif


#ifdef PIC_MICRO_ACTIVE


#include <xc.h>
#define _XTAL_FREQ 4000000

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#endif

#endif  