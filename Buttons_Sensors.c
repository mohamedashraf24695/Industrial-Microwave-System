#include "Buttons_Sensors.h"
#include "Port.h"
#include "Dio.h" 

/*A structure to put all the configuration to be used 
 * by functions 
 */

static Port_ConfigTypeParam Start_Button_Config;
static Port_ConfigTypeParam Cancel_Button_Config;
static Port_ConfigTypeParam On_Button_Config;
static Port_ConfigTypeParam Weight_Sensor_Config;
static Port_ConfigTypeParam Door_Sensor_Config;

/***************************************************
 * Name: buttonConfigurations  (STATIC FUNCTION)
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Buttons Configurations : It makes define the port , pin , direction and pulling mode
 * for each pin 
 
 *********************************************************/


static void buttonConfigurations(void) {

	Start_Button_Config.port = DioConf_START_BUTTON_PORT_NUM;
	Start_Button_Config.pin_num = DioConf_START_BUTTON_CHANNEL_NUM;
	Start_Button_Config.direction = PORT_PIN_IN;
	Start_Button_Config.pulling = Pull_Up;

	Weight_Sensor_Config.port = DioConf_WEIGHT_SENSOR_PORT_NUM;
	Weight_Sensor_Config.pin_num = DioConf_WEIGHT_SENSOR_CHANNEL_NUM;
	Weight_Sensor_Config.direction = PORT_PIN_IN;
	Weight_Sensor_Config.pulling = Pull_Down;

	Door_Sensor_Config.port = DioConf_DOOR_SENSOR_PORT_NUM;
	Door_Sensor_Config.pin_num = DioConf_DOOR_SENSOR_CHANNEL_NUM;
	Door_Sensor_Config.direction = PORT_PIN_IN;
	Door_Sensor_Config.pulling = Pull_Down;

	Cancel_Button_Config.port = DioConf_CANCEL_BUTTON_PORT_NUM;
	Cancel_Button_Config.pin_num = DioConf_CANCEL_BUTTON_CHANNEL_NUM ;
	Cancel_Button_Config.direction = PORT_PIN_IN;
	Cancel_Button_Config.pulling = Pull_Up;

On_Button_Config.port = DioConf_CANCEL_BUTTON_PORT_NUM;
	On_Button_Config.pin_num = DioConf_CANCEL_BUTTON_CHANNEL_NUM ;
	On_Button_Config.direction = PORT_PIN_IN;
	On_Button_Config.pulling = Pull_Up;

}

/***************************************************
 * Name: buttons_sensorsInit
 * Parameters (in):void
 * Return value: void
 * Description:
 * 1) Run the buttons and sensor's configuration function (Read its description)
 * 2) Set the directions of pins
 *********************************************************/

void buttons_sensorsInit(void) {
	buttonConfigurations();
	SetPortDirection(&Start_Button_Config);
	SetPortDirection(&Weight_Sensor_Config);
	SetPortDirection(&Door_Sensor_Config);
	SetPortDirection(&Cancel_Button_Config);
SetPortDirection(&On_Button_Config);

}

/***************************************************
 * Name: Read_sensor_button
 * Parameters (in):Port_ConfigTypeParam * (pointer to structure), char  
 * Return value: char
 * Description: Takes pointer to structure and the DIO Index of one button or sensor 
 * and return is the button is pressed / sensor is reading  or not 
 *********************************************************/


static uint8 Read_sensor_button(Port_ConfigTypeParam *Config_ptr,
		uint8 INDEX_ID) {
	uint8 state = LOW;
	uint8 DioReading = Dio_ReadChannel(INDEX_ID);

	if (DioReading == HIGH) {

		if (Config_ptr->pulling == Pull_Down) {
			state = HIGH;
		} else if (Config_ptr->pulling == Pull_Up) {
			state = LOW;
		}

	}

	else if (DioReading == LOW) {
		if (Config_ptr->pulling == Pull_Down) {
			state = LOW;
		} else if (Config_ptr->pulling == Pull_Up) {
			state = HIGH;
		}

	}

	else {
		/*NO CODE*/
	}
	return state;
}

/***************************************************
 * Name: readStartButton
 * Parameters (in):void
 * Return value: char
 * Description: return the state of the start button
 *********************************************************/

uint8 readStartButton(void) {
	uint8 state;
	state = Read_sensor_button(&Start_Button_Config,
	DioConf_START_BUTTON_ID_INDEX);
	return state;
}

/***************************************************
 * Name: readWeightSensor
 * Parameters (in):void
 * Return value: char
 * Description: return the state of the weight sensor
 *********************************************************/
uint8 readWeightSensor(void) {
	uint8 state;
	state = Read_sensor_button(&Weight_Sensor_Config,
	DioConf_WEIGHT_SENSOR_ID_INDEX);
	return state;
}
/***************************************************
 * Name: readDoorSensor
 * Parameters (in):void
 * Return value: char
 * Description: return the state of the door sensor
 *********************************************************/

uint8 readDoorSensor(void) {
	uint8 state;
	state = Read_sensor_button(&Door_Sensor_Config,
	DioConf_DOOR_SENSOR_ID_INDEX);
	return state;
}

/***************************************************
 * Name: readCancelButton
 * Parameters (in):void
 * Return value: char
 * Description: return the state of the cancel button
 *********************************************************/


uint8 readCancelButton(void) {
	uint8 state;
	state = Read_sensor_button(&Cancel_Button_Config,
			DioConf_CANCEL_BUTTON_ID_INDEX);
	return state;
}

/***************************************************
 * Name: readOnButton
 * Parameters (in):void
 * Return value: char
 * Description: return the state of the on button
 *********************************************************/
uint8 readOnButton(void) {
	uint8 state;
	state = Read_sensor_button(&On_Button_Config,
			DioConf_ON_BUTTON_ID_INDEX);
	return state;
}



