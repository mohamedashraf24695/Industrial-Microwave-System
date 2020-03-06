#ifndef GPT_H
#define GPT_H

/*******************************************************************************
 *                              Included Files                               *
 *******************************************************************************/


#include "micro_config.h"
#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define PMW_TIMER0_DDR DDRB
#define PMW_TIMER0_BIT PB3
#define MAX_PWM_REGISTER_NUMBER 255
#define ONE_SECOND_TICKS   10 

#define  delay_ms_Fuction(time)  __delay_ms(time) 
#define  delay_us_Fuction(time)  __delay_us(time) 


    
/******************************************
 *           Decelerations                *
 ******************************************/


extern uint8 g_Remaining_seconds;
extern uint8 g_Remaining_minutes;
extern uint8 g_Remaining_hours;
extern uint8 stop_flag ;
extern uint8 g_Set_seconds;
extern uint8 g_Set_minutes;
extern uint8 g_Set_hours;
extern uint8 g_tick;




/*********************************************
 Functions prototypes
 *********************************************/

void PWM_Timer0_Init(uint8 set_duty_cycle);
void GptInit(void);

void timer1_init_CTC_mode(void);
void timeEstablished(void);
void timeRemaining(void);
void timeSet(uint8 input_hours , uint8 input_minutes , uint8 input_seconds) ;
void timeRest(void);
void timeStop (void);
void timeStart (void);

#endif
