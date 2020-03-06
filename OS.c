#include "App.h"
#include "OS.h"



uint8 OS_State_flag = OFF_STATE;

void OS_Init(void) {

    initApp();

}

void OS_Schedular(void) {

    if (OS_State_flag == OFF_STATE) {

        if (HIGH == check_OnButton()) {

            OS_State_flag = REQUEST_TIME_STATE;
        } else {

        }
    }

    if (OS_State_flag == REQUEST_TIME_STATE) {

        requestTime();
        
        if (clear_time_flag == 1)
        {
        clear_time_flag = 0 ;
        OS_State_flag = REQUEST_TIME_STATE;
        }
        else {
           OS_State_flag = DOOR_WEIGHT_SENSORS_STATE;
        }
        
        
        
        

    }

    if (OS_State_flag == DOOR_WEIGHT_SENSORS_STATE) {

        if (HIGH == check_Door_Weight()) {

            OS_State_flag = START_BUTTON_STATE;

        }

    }

    if (OS_State_flag == START_BUTTON_STATE) {

        if (HIGH == check_StartButton()) {
            OS_State_flag = MAIN_PROCESS_STATE;
        }

    }

    if (OS_State_flag == MAIN_PROCESS_STATE) {

        displayTime();
        runHeater();

        
         if (check_CancelButton() == HIGH) {

                OS_State_flag = CANEL_FINSHING_STATE;

            }
        
        
        else if (HIGH == checkTimeOut()) {
           
                OS_State_flag = NORMAL_FINISHING_STATE;
            
        }


    }


    if (OS_State_flag == NORMAL_FINISHING_STATE) {
        turnOffHeater();
        timeIsFinished();
        OS_State_flag = REQUEST_TIME_STATE;

    }
    if (OS_State_flag == CANEL_FINSHING_STATE) {
        turnOffHeater();
        processIsCanceled();
        OS_State_flag = REQUEST_TIME_STATE;
    }
   
}
