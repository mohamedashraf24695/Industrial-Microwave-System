#include "Gpt.h"

/*
 
 Note : GPT stands for General purpose timer
 */


uint8 g_Remaining_seconds;
uint8 g_Remaining_minutes;
uint8 g_Remaining_hours;

uint8 g_Set_seconds;
uint8 g_Set_minutes;
uint8 g_Set_hours;

uint8 g_tick;
uint8 stop_flag =1 ; 



/*

void PWM_Timer0_Init(uint8 set_duty_cycle) {
    

}
*/

/***************************************************
 * Name: GptInit  
 * Parameters (in):void
 * Return value: void
 * Description:used by other modules uses General Purpose Timer 
 * to initialize the module 
 *
 *********************************************************/


void GptInit(void) {
    timer1_init_CTC_mode();
}


/***************************************************
 * Name: timer1_init_CTC_mode  
 * Parameters (in):void
 * Return value: void
 * Description: Initialize Timer 1 on PIC16f877A Registers 
 
 *********************************************************/

void timer1_init_CTC_mode(void) {
 
    TMR1IE=1 ;
    PEIE=1 ;
    GIE=1 ;
    TMR1=0 ;
    TMR1CS=0 ;
    T1CKPS0 = 0 ;
    T1CKPS1= 0 ;
    TMR1ON = 1 ;
}


/***************************************************
 * Name: timeRemaining  
 * Parameters (in):void
 * Return value: void
 * Description: Counting time by descending order 
 * 
 * 
 * Algorithm : 
 * 1)Checks till the ticks reaches to make one second. 
 * 2)if number of seconds is more than zero , then we can subtract one 
 * else we cant to avoid overflow or making negative time.
 * 3) if sec = 0 , look for minutes 
 * 4) if minutes more than zero , we will subtract one and make seconds to be 
 * 59 secs 
 * 5) if minutes = 0 , look for hours 
 * 6) if hours more than 0 , we will subtract one from hours and make min = 59 
 * and sec = 59 
   7) and repeat at every time till time equal 00:00:00 Then no action will be 
 * taken to protect code from overflow or negative or unpretected performance 

 
 *********************************************************/


void timeRemaining(void) {

    if (g_tick == ONE_SECOND_TICKS) 
    {
        g_tick = 0;
        if (g_Remaining_seconds > 0) {

            g_Remaining_seconds--;
        } else {

            if (g_Remaining_minutes > 0) {
                g_Remaining_seconds = 59;
                g_Remaining_minutes--;

            } else {
                if (g_Remaining_hours > 0) {
                    g_Remaining_seconds = 59;
                    g_Remaining_minutes = 59;
                    g_Remaining_hours--;

                } else {
                    /*No Code*/
                }

            }

        }

    }

}

/***************************************************
 * Name: timeSet  
 * Parameters (in):uint8 input_hours, uint8 input_minutes, uint8 input_seconds
 * Return value: void
 * Description: assign the values of the entered time  
 
 *********************************************************/
void timeSet(uint8 input_hours, uint8 input_minutes, uint8 input_seconds) {
    g_Set_seconds = input_seconds;
    g_Set_minutes = input_minutes;
    g_Set_hours = input_hours;

    g_Remaining_seconds = input_seconds;
    g_Remaining_minutes = input_minutes;
    g_Remaining_hours = input_hours;

}

/***************************************************
 * Name: timeRest  
 * Parameters (in):void
 * Return value: void
 * Description: zeroing all the time 
 
 *********************************************************/

void timeRest(void) {
    g_Remaining_seconds = 0;
    g_Remaining_minutes = 0;
    g_Remaining_hours = 0;
    g_tick = 0;
}
/***************************************************
 * Name: timeStop  
 * Parameters (in):void
 * Return value: void
 * Description: stop flag is a flag that used to control the 
 * increment of time ticks by processor .if stop flag is enabled , when 
 * processor go to interrupt function , it will not be able to increase 
 * value of time counting variable 
 * 
 * 
    if (TMR1IF == HIGH){
    
        if(stop_flag ==0){
        g_tick ++ ;
        timeRemaining(); 
        }
 * 
 * Purpose : to make timer counting actively starting from the point I want , 
 * not when processor doing timer interrupt
 
 *********************************************************/
void timeStop(void) {
    stop_flag = 1;
}


/***************************************************
 * Name: timeStart  
 * Parameters (in):void
 * Return value: void
 * Description: stop flag is a flag that used to control the 
 * increment of time ticks by processor .if stop flag is disabled  , when 
 * processor go to interrupt function , it will be able to increase 
 * value of time counting variable 
 * 
 * 
    if (TMR1IF == HIGH){
    
        if(stop_flag ==0){
        g_tick ++ ;
        timeRemaining(); 
        }
 * 
 * Purpose : to make timer counting actively starting from the point I want , 
 * not when processor doing timer interrupt
 *********************************************************/
void timeStart(void) {
    stop_flag = 0;
}

