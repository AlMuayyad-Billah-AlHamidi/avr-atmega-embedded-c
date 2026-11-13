/*
 * Led_Task.c
 *
 * Created: 9/1/2024 10:54:21 PM
 * Author : MouhannadlrX
 */ 
#define F_CPU 1000000UL 

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
	
	//Initialization For Leds 
	LED_voidInit(LED0);
    LED_voidInit(LED1);
	LED_voidInit(LED2);
	 
	u8 counter = 1;	
    while (1) 
    {
		
		
		if(counter % 1 == 0)
		{
			LED_voidToggle(LED0);
		}
		
		if(counter % 2 == 0)
		{
			LED_voidToggle(LED1);
		}
		
		if(counter % 3 == 0)
		{
			LED_voidToggle(LED2);
		}
		
		counter ++;
		_delay_ms(10000);
		
    }
	return 0;
}

