
#ifndef _KEYPAD_H
#define _KEYPAD_H

/*******************************************************************************
 *                              Included Files                               *
 *******************************************************************************/

#include "std_types.h"


/*******************************************************************************
 *                              MACROS DEFINITION                               *
 *******************************************************************************/


#define X_1    RD0
#define X_2    RD1
#define X_3    RD2
#define X_4    RD3
#define Y_1    RB0
#define Y_2    RB1
#define Y_3    RB2


#define Keypad_Y_PORT          PORTB
#define Keypad_X_PORT          PORTD

#define Keypad_Y_PORT_Direction     TRISB   
#define Keypad_X_PORT_Direction     TRISD   
#define KEYPAD_DELAY_MS  30 


/******************************************
 *            Functions Prototypes                    *
 ******************************************/

void InitKeypad(void);
char KeyPad_getPressedKey(void);
char keypad_scanner(void) ;
#endif 