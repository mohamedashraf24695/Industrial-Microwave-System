# IndustrialMicrowave System

Designed to work mainly on PIC16f877a and simulated by PICsim 0.7
Can easily work on any micro-controller,I built the project as layers to make the project Independent as possible on the micro-controller.
Mcal layer contains Dio , Port and timer drivers. 
Hal layer contains buttons and sensors , leds , motor , heater , lcd and keypad driver.
Application layer and OS to control the flow of the project.

# The Operations of the microwave.
* The microwave started in off mode , so user have to turn it on.
* After turning on , user have to set timer and to be sure that there is a food in it and the door is locked well
* To start cooking, user have to press start.
* If user didn’t lock the door or there is no food in microwave, the heater and the timer will not be activated.
* If user entered non-time numbers, like to a number more than 59 in seconds or minutes, it will be a message on the LCD to user have to re-enter the time in right formula.
* If user while entering a number wanted to clear the time to enter a correct number, he can do that by press clear timer input.
* After starting the system, heater, motor and heater lamp will be turned on and the timer will count till zero.
* After finishing , a message will appear to the user to inform him that food is cooked and let him to start another operation.
* User can also cancel the process before it is finished.

The demo is here: https://www.youtube.com/watch?v=hM3MGen5sT4 

# Algorithm of the project 
![Algorithm of the project](https://github.com/mohamedashraf24695/Industrial-Microwave-System-/blob/master/Algo.png)

# Software design 
![Software design](https://github.com/mohamedashraf24695/Industrial-Microwave-System-/blob/master/des.png)

# Hardware setup on PICsim 0.7
![The Microwave as hardware](https://github.com/mohamedashraf24695/Industrial-Microwave-System-/blob/master/Microwave%20system%20-%20Copy.png)
