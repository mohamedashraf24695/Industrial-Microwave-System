#include "micro_config.h"
#include "Gpt.h" 
#include "ISR.h"

void __interrupt() MyISR(void) {


    if (TMR1IF == HIGH) {

        if (stop_flag == 0) {
            g_tick++;
            timeRemaining();
        }


        TMR1IF = LOW;

    }
 
}

void interruptsInit(void) {

    TRISB |= ((1 << 0));
    GIE = 1; //Enable Global Interrupt
    PEIE = 1; //Enable the Peripheral Interrupt
    ei();

}
