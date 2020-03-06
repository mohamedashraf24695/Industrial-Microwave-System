#ifndef BUTTONS_SENSORS_H
#define BUTTONS_SENSORS_H

/*******************************************************************************
 *                              Included Files                               *
 *******************************************************************************/
#include "std_types.h"
/*******************************************************************************
 *                              MACROS DEFINITION                               *
 *******************************************************************************/

#define DEBOUNCE_CONSTANT_US 1

/*******************************************************************************
 *                           Functions Prototype                            *
 *******************************************************************************/

void buttons_sensorsInit(void);
uint8 readStartButton(void);
uint8 readWeightSensor(void);
uint8 readDoorSensor(void);
uint8 readCancelButton(void);
uint8 readOnButton(void);

#endif
