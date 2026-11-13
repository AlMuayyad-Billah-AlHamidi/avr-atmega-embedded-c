/*
 * Two_Leds_Diverg_Or_Converg.c
 *
 * Created: 9/7/2024 4:57:01 PM
 * Author : MouhannadlrX
 */ 
#define F_CPU 16000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEDS_TEST_interface.h"

#define  Shift_Mode  LED_MODE_DiVERGING
#include <util/delay.h>


int main(void)
{
	//Define All Configuration For Leds
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
	
	/* Replace with your application code */
	while (1)
	{
			
				
				if( Shift_Mode == LED_MODE_DiVERGING )
				{
					u8 z=1;
					u8 y  ;
					for(u8 i=4 ;i<=7 ;i++)
					{
						y=i-z;
						LED_voidOn(Arry_Leds[i]);
						LED_voidOn(Arry_Leds[y]);
						_delay_ms(250);
						
						LED_voidOff(Arry_Leds[i]);
						LED_voidOff(Arry_Leds[y]);
						z+=2;
					}
					
				}
				
				else if( Shift_Mode == LED_MODE_CONVERGING )
				{
					u8 z=7;
					u8 y=0;
					for(u8 i=0 ;i<=3 ;i++)
					{
						 y=i+z;
						LED_voidOn(Arry_Leds[i]);
						LED_voidOn(Arry_Leds[y]);
						_delay_ms(500);
						
						LED_voidOff(Arry_Leds[i]);
						LED_voidOff(Arry_Leds[y]);
				
						z-=2;
					}
				}
		
			
	}
		
}

