
#ifndef LED_H
#define LED_H

/*******************************************************************************
 *                              Included Files                               *
 *******************************************************************************/


#include "std_types.h"


/*******************************************************************************
 *                           Functions Prototype                            *
 *******************************************************************************/

void ledsInit(void);
void writeONLamp(uint8 LEVEL);
void writeHeaterLamp(uint8 LEVEL);
#endif

