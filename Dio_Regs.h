
#ifndef DIO_REGS_H
#define DIO_REGS_H

/*******************************************************************************
 *                              Included Files                               *
 *******************************************************************************/


#include "std_types.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/



#ifdef PIC_MICRO_ACTIVE

/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 *)0x005)
#define DDRA_REG	(*(volatile uint8 *)0x085)
#define PINA_REG 	(*(volatile uint8 *)0x005)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 *)0x006)
#define DDRB_REG	(*(volatile uint8 *)0x086)
#define PINB_REG 	(*(volatile uint8 *)0x006)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 *)0x007)
#define DDRC_REG	(*(volatile uint8 *)0x087)
#define PINC_REG 	(*(volatile uint8 *)0x007)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 *)0x008)
#define DDRD_REG	(*(volatile uint8 *)0x088)
#define PIND_REG 	(*(volatile uint8 *)0x008)

/* Definition for PORTE Registers */
#define PORTE_REG	(*(volatile uint8 *)0x009)
#define DDRE_REG	(*(volatile uint8 *)0x089)
#define PINE_REG 	(*(volatile uint8 *)0x009)

#endif 

#ifndef PIC_MICRO_ACTIVE


/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 *)0x003B)
#define DDRA_REG	(*(volatile uint8 *)0x003A)
#define PINA_REG 	(*(volatile uint8 *)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 *)0x0038)
#define DDRB_REG	(*(volatile uint8 *)0x0037)
#define PINB_REG 	(*(volatile uint8 *)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 *)0x0035)
#define DDRC_REG	(*(volatile uint8 *)0x0034)
#define PINC_REG 	(*(volatile uint8 *)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 *)0x0032)
#define DDRD_REG	(*(volatile uint8 *)0x0031)
#define PIND_REG 	(*(volatile uint8 *)0x0030)

#endif 

#endif /* DIO_REGS_H */
