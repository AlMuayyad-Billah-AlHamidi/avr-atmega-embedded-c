/*
 * Led_PingPong_Effect.c
 *
 * Created: 9/7/2024 11:10:32 PM
 * Author : MouhannadlrX
 */ 

#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//#include "DIO_interface.h"

#include "LEDS_TEST_interface.h"

#include <util/delay.h>



int main(void)
{
	LED_Type LED0 = {LED_PORTA , LED_PIN0 , ACTIVE_HIGH};
	LED_Type LED1 = {LED_PORTA , LED_PIN1 , ACTIVE_HIGH};
	LED_Type LED2 = {LED_PORTA , LED_PIN2 , ACTIVE_HIGH};
	LED_Type LED3 = {LED_PORTA , LED_PIN3 , ACTIVE_HIGH};
	LED_Type LED4 = {LED_PORTA , LED_PIN4 , ACTIVE_HIGH};
	LED_Type LED5 = {LED_PORTA , LED_PIN5 , ACTIVE_HIGH};
	LED_Type LED6 = {LED_PORTA , LED_PIN6 , ACTIVE_HIGH};
	LED_Type LED7 = {LED_PORTA , LED_PIN7 , ACTIVE_HIGH};

	//Initialization Pins Output For Leds
	LED_voidInit(LED0);
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);
	LED_voidInit(LED4);
	LED_voidInit(LED5);
	LED_voidInit(LED6);
	LED_voidInit(LED7);
   
   LED_Type Arry_Leds[8] = {LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};
    while (1) 
    {
		for(u8 i=0 ;i<=7 ;i++)
		{
			
			LED_voidOn(Arry_Leds[i]);
			_delay_ms(1000);
			LED_voidOff(Arry_Leds[i]);

		}
		
		for(s8 i=7 ;i>=0 ;i--)
		{
			
			LED_voidOn(Arry_Leds[i]);
			_delay_ms(1000);
			LED_voidOff(Arry_Leds[i]);
		}
    }
}

