
#include "keypad.h"
#include "micro_config.h"


/*IMP.NOTE : 
 1)
 All the drivers in this project are written by me except two drivers :
 * 1) LCD driver 
 * 2) keypad driver 
 * 
 * I do some changes to them to be suitable for the project 
 * but I got them from Internet  
 * 
 * 
 * 
 2) For Keypad driver , for better design I had to use PORT and DIO
 * drivers to isolate the keypad driver from the microcontroller 
 */
 





/***************************************************
 * Name: KeyPad_getPressedKey 
 * Parameters (in):void
 * Return value: Uint8
 * Description:
 * return the key pressed by the user.
 *********************************************************/

char KeyPad_getPressedKey(void) // Get key from user
{
    char key = 'n'; // Assume no key pressed
    while (key == 'n') // Wait until a key is pressed
        key = keypad_scanner(); // Scan the keys again and again
    __delay_ms(KEYPAD_DELAY_MS);
    return key; //when key pressed then return its value
}


/***************************************************
 * Name: keypad_scanner  
 * Parameters (in):void
 * Return value: Uint8
 * Description:
 * Scan the keypad 
 * enabling rows by successive order  and reading columns to detect which 
 * key is pressed by the user 
 *********************************************************/

 char keypad_scanner(void) {

    X_1 = 0;
    X_2 = 1;
    X_3 = 1;
    X_4 = 1;
        __delay_ms(KEYPAD_DELAY_MS);

    if (Y_1 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_1 == 0) {

            return '*';
        }
    }  if (Y_2 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_2 == 0) {

            return 0;
        }
    }  if (Y_3 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_3 == 0) {

            return '#';
        }
    }

    X_1 = 1;
    X_2 = 0;
    X_3 = 1;
    X_4 = 1;
            __delay_ms(KEYPAD_DELAY_MS);

    if (Y_1 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_1 == 0) {

            return 7;
        }
    }  if (Y_2 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_2 == 0) {
            return 8;
        }
    }  if (Y_3 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_3 == 0) {
  
            return 9;
        }
    }
  
    X_1 = 1;
    X_2 = 1;
    X_3 = 0;
    X_4 = 1;
            __delay_ms(KEYPAD_DELAY_MS);

    if (Y_1 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_1 == 0) {

            return 4;
        }
    }  if (Y_2 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_2 == 0) {

            return 5;
        }
    }  if (Y_3 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_3 == 0) {

            return 6;
        }
    }

    X_1 = 1;
    X_2 = 1;
    X_3 = 1;
    X_4 = 0;
      __delay_ms(KEYPAD_DELAY_MS);
      
    if (Y_1 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_1 == 0) {
            return 1;
        }
    }  if (Y_2 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_2 == 0) {

            return 2;
        }
    }  if (Y_3 == 0) {
        __delay_ms(KEYPAD_DELAY_MS);
        while (Y_3 == 0) {
            
            return 3;
        }
    }
 
    return 'n';
}

/***************************************************
 * Name: InitKeypad  
 * Parameters (in):void
 * Return value: void
 * Description:
 * Initiate the keypad 
 * by set direction of ports configure the registers 
 * and configure PORTB to be pulled up by internal resistors 
 *********************************************************/
void InitKeypad(void) {
 
    Keypad_Y_PORT_Direction |= (1 << Y_1) | (1 << Y_2) | (1 << Y_3); //iutput
    Keypad_X_PORT_Direction &= (~(1 << X_2))& (~(1 << X_3))& (~(1 << X_4)) & (~(1 << X_1)) ; // output
    Keypad_Y_PORT &= (~(1 << Y_1))&(~(1 << Y_2))& (~(1 << Y_3));
    Keypad_X_PORT &= (~(1 << X_1))&(~(1 << X_2))& (~(1 << X_3))& (~(1 << X_4));
    
    OPTION_REG &= 0x7F; 
}
