
#include "heater.h"
#include "Dio.h"
#include "Port.h"


heater_info_holder  heater_information_1;
heater_info_holder *holder_ptr;
static Port_ConfigTypeParam Heater_Config_1;

uint16 g_heating_temperature ;



/***************************************************
 * Name: heaterConfigurations  (STATIC FUNCTION)
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Heater Configurations : It makes define the port , pin , direction and pulling mode
 * for each pin of the two motor's pin
 *
 * 2) The heater informations : heat precentage and state .
 * This information will be read from the other module's function and according to it
 * it will act
 *
 *********************************************************/



static void heaterConfigurations(void){

	Heater_Config_1.port = DioConf_HEATER_PORT_NUM;
	Heater_Config_1.pin_num = DioConf_HEATER_CHANNEL_1_NUM;
	Heater_Config_1.direction = PORT_PIN_OUT;
	Heater_Config_1.pulling = No_PULL;


	heater_information_1.mode= DEFAULT_HEATER_MODE;

#if (PMW_ENABLE == HIGH)
	heater_information_1.heat_precentage =DEFAULT_HEATER_HEAT_PRECENTAGE ;
#else
	heater_information_1.heat_precentage =FULL_HEATER_HEAT_PRECENTAGE ;
#endif

}

/***************************************************
 * Name: heaterInit
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Run the heater's Configuration function (Read its description)
 * 2) Set the directiom of  motor's pin
 * 3) assign a pointer to read from the motor's information
 
 *********************************************************/


void heaterInit(void) {

	heaterConfigurations();
	SetPortDirection(&Heater_Config_1);
	holder_ptr = &heater_information_1 ;
}


/***************************************************
 * Name: heaterAction
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Write the heater's pins acccording to its configuration (ON ,OFF)
 * 2) If is it is off , both of the pins will be in LOW state
 * 3) Puts HIGH or LOW on the heater's pin according to it direction if it is ON
  *4) Change the heating precentage 
 *********************************************************/


void heaterAction(void) {
	holder_ptr->heat_precentage = (float32)g_heating_temperature/1000.0 ;

	if (holder_ptr->mode == HEATER_OFF) {
		Dio_WriteChannel(DioConf_HEATER_ID_INDEX_1_NUM, LOW);

	} else if (holder_ptr->mode == HEATER_ON) {
		Dio_WriteChannel(DioConf_HEATER_ID_INDEX_1_NUM, HIGH);
	}
#if (PMW_ENABLE==HIGH)
		if (holder_ptr->heat_precentage >= 0
				&& holder_ptr->heat_precentage <= 100) {

			PWM_Timer0_Init(
					(holder_ptr->heat_precentage / 100.0)
							* MAX_PWM_REGISTER_NUMBER);

		} else {

			PWM_Timer0_Init(MAX_PWM_REGISTER_NUMBER);
		}

	} else {
		/*No Code*/

	}
#endif
}



#if (PMW_ENABLE == HIGH)
void heaterIncHeat(void) {
	holder_ptr->heat_precentage += HEATER_RATE_OF_INCREASING;

	if (holder_ptr->heat_precentage >= 0
			&&holder_ptr->heat_precentage <= 100) {

		PWM_Timer0_Init(
				(holder_ptr->heat_precentage / 100.0) * MAX_PWM_REGISTER_NUMBER);

	} else {

		PWM_Timer0_Init(MAX_PWM_REGISTER_NUMBER);
	}

}

void heaterDecHeat(void) {
	holder_ptr->heat_precentage -= HEATER_RATE_OF_INCREASING;

	if (holder_ptr->heat_precentage >= 0
			&&holder_ptr->heat_precentage <= 100) {
        
        holder_ptr->heat_precentage -= HEATER_RATE_OF_INCREASING;
		PWM_Timer0_Init(
				(holder_ptr->heat_precentage / 100.0) * MAX_PWM_REGISTER_NUMBER);

	} else {

		PWM_Timer0_Init(0);
	}

}



#endif



/***************************************************
 * Name: heaterStop
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Change heater's state to OFF 
 * 2) Active the off state 
 
 *********************************************************/

void heaterStop (void){
	holder_ptr->mode = HEATER_OFF ;
	heaterAction();
}

/***************************************************
 * Name: heaterRun
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Change heater's state to ON 
 * 2) Active the ON state 
 
 *********************************************************/
void heaterRun (void){
	holder_ptr->mode = HEATER_ON ;
	heaterAction();
}


