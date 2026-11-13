/*
 * Leds_Snake_Effect.c
 *
 * Created: 9/7/2024 11:31:18 PM
 * Author : MouhannadlrX
 */ 

#define F_CPU 16000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEDS_TEST_interface.h"
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
		u8 z = 0;
		u8 x = 1;
		u8 y = 2;
		for(int i=0 ;i<=50 ;i++)
		{
			
		
			LED_voidOn(Arry_Leds[z]);
			LED_voidOn(Arry_Leds[x]);
			LED_voidOn(Arry_Leds[y]);
			_delay_ms(400);
			
			LED_voidOff(Arry_Leds[z]);
			LED_voidOff(Arry_Leds[x]);
			LED_voidOff(Arry_Leds[y]);

			y++;
			x++;
			z++;
			if(y == 8){ y = 0;}
			else if(x == 8){ x = 0;}
			else if(z == 8){ z = 0;}
		}
    }
}

