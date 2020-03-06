#ifndef _MOTOR_H
#define _MOTOR_H

/*********************************************
 *            H files Included               *
 *********************************************/

#include "std_types.h"

/******************************************
 *           MACROS DEF                *
 ******************************************/
#define PMW_MOTOR_MODE  LOW
#define MOTORSPEED_RATE_OF_INCREASING   10
#define DEFAULT_MOTOR_DIRECTION    0
#define DEFAULT_MOTOR_SPEED        50
#define DEFAULT_MOTOR_MODE         1
#define FULL_MOTOR_SPEED        50
/******************************************
 *           Decelerations                *
 ******************************************/

typedef enum {
	clock_wise, anti_clock_wise
} motor_direction;

typedef enum {
	MOTOR_OFF, MOTOR_ON
} motor_mode;

typedef struct {

	motor_mode mode; /*Motor is on or off*/
	motor_direction direction; /*Determine if motor is clockwise or anti-clock wise*/
	float speed_precentage; /*The speed of the motor*/

} motor_info_holder;

/******************************************
 *            Functions Prototypes                    *
 ******************************************/

void motorInit(void);
void motorAction(void); 
void motorStop(void);
void motorRun(void);

#endif
