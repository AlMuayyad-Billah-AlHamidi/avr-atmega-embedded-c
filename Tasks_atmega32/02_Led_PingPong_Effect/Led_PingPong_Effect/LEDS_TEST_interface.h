/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   LED_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : LED
*
*/



#ifndef _LEDS_TEST_INTERFACE_H_
#define _LEDS_TEST_INTERFACE_H_

//Port Defines
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3


//Pin Defines
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

// Type Of Active
#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0

// Type Of Shift
#define LED_SHIFT_LEFT  0
#define LED_SHIFT_RIGHT 1

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_Type;

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Action_State;
}LED_Action;
 
 void LED_voidInit(LED_Type LED_Configuration);
 void LED_voidOn(LED_Type LED_Configuration);
 void LED_voidOff(LED_Type LED_Configuration);
 void LED_voidToggle(LED_Type LED_Configuration);
 
 void  LED_voidShiftEvery_250ms  ( LED_Action LED_Mode);
 
#endif