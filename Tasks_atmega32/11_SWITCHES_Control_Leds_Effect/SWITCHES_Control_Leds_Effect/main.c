/*
 * SWITCH_Control_Leds_Effect.c
 *
 * Created: 9/14/2024 2:47:59 PM
 * Author : Al_Moaiyad Bellah Al_Hemadi
 */ 
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LEDS_TEST_interface.h"	
		
#include "SWITCH_config.h"
#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include <util/delay.h>

int main(void)
{ 
	
    SW_Type SWITCH0 = {DIO_PORTD , DIO_PIN0 , SW_Int_PULL_UP};
	SW_Type SWITCH1 = {DIO_PORTD , DIO_PIN1 , SW_Int_PULL_UP};
	SW_Type SWITCH2 = {DIO_PORTD , DIO_PIN2 , SW_Int_PULL_UP};
	SW_Type SWITCH3 = {DIO_PORTD , DIO_PIN3 , SW_Int_PULL_UP};
	SW_Type SWITCH4 = {DIO_PORTD , DIO_PIN4 , SW_Int_PULL_UP};
	SW_Type SWITCH5 = {DIO_PORTD , DIO_PIN5 , SW_Int_PULL_UP};	
	SW_Type SWITCH6 = {DIO_PORTD , DIO_PIN6 , SW_Int_PULL_UP};
	SW_Type SWITCH7 = {DIO_PORTD , DIO_PIN7 , SW_Int_PULL_UP};	
		
	SWITCH_voidInit(SWITCH0);
	SWITCH_voidInit(SWITCH1);
	SWITCH_voidInit(SWITCH2);
	SWITCH_voidInit(SWITCH3);
	SWITCH_voidInit(SWITCH4);
	SWITCH_voidInit(SWITCH5);
	SWITCH_voidInit(SWITCH6);
	SWITCH_voidInit(SWITCH7);
	
	//DIO_voidDisablePullUp();
	
	//Define All Configuration For Leds
	LED_Type LED0 = {LED_PORTC , LED_PIN0 , ACTIVE_HIGH};
	LED_Type LED1 = {LED_PORTC , LED_PIN1 , ACTIVE_HIGH};
	LED_Type LED2 = {LED_PORTC , LED_PIN2 , ACTIVE_HIGH};
	LED_Type LED3 = {LED_PORTC , LED_PIN3 , ACTIVE_HIGH};
	LED_Type LED4 = {LED_PORTC , LED_PIN4 , ACTIVE_HIGH};
	LED_Type LED5 = {LED_PORTC , LED_PIN5 , ACTIVE_HIGH};
	LED_Type LED6 = {LED_PORTC , LED_PIN6 , ACTIVE_HIGH};
	LED_Type LED7 = {LED_PORTC , LED_PIN7 , ACTIVE_HIGH};

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
		
		
		if(SWITCH_emumGetPressed(SWITCH0) == SW_Pressed)
		{
			DIO_enumSetPortValue(DIO_PORTC , DIO_PORT_HIGH);
			_delay_ms(500);
			DIO_enumSetPortValue(DIO_PORTC , DIO_PORT_LOW);
			_delay_ms(500);
			DIO_enumSetPortValue(DIO_PORTC , DIO_PORT_HIGH);
			_delay_ms(500);
			DIO_enumSetPortValue(DIO_PORTC , DIO_PORT_LOW);
			
		}
		
		else if (SWITCH_emumGetPressed(SWITCH1) == SW_Pressed)
		{
			for(u8 i=0 ;i<=7 ;i++)
			{
				LED_voidOn(Arry_Leds[i]);
				_delay_ms(250);
				LED_voidOff(Arry_Leds[i]);
				
			}
		}
		else if (SWITCH_emumGetPressed(SWITCH2) == SW_Pressed)
		{
			for(s8 i=7 ;i>=0 ;i--)
			{
				LED_voidOn(Arry_Leds[i]);
				_delay_ms(250);
				LED_voidOff(Arry_Leds[i]);
			}
		}
		else if (SWITCH_emumGetPressed(SWITCH3) == SW_Pressed)
		{
			u8 z=7;
			u8 y=0;
			for(u8 i=0 ;i<=3 ;i++)
			{
				y=i+z;
				LED_voidOn(Arry_Leds[i]);
				LED_voidOn(Arry_Leds[y]);
				_delay_ms(250);
				
				LED_voidOff(Arry_Leds[i]);
				LED_voidOff(Arry_Leds[y]);
				
				z-=2;
			}
		}
		else if (SWITCH_emumGetPressed(SWITCH4) == SW_Pressed)
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
		else if (SWITCH_emumGetPressed(SWITCH5) == SW_Pressed)
		{
			for(u8 i=0 ;i<=7 ;i++)
			{
				
				LED_voidOn(Arry_Leds[i]);
				_delay_ms(250);
				LED_voidOff(Arry_Leds[i]);

			}
			
			for(s8 i=7 ;i>=0 ;i--)
			{
				
				LED_voidOn(Arry_Leds[i]);
				_delay_ms(250);
				LED_voidOff(Arry_Leds[i]);
			}
		}
		else if (SWITCH_emumGetPressed(SWITCH6) == SW_Pressed)
		{
			u8 z = 0;
			u8 x = 1;
			u8 y = 2;
			for(int i=0 ;i<=15 ;i++)
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
		else if (SWITCH_emumGetPressed(SWITCH7) == SW_Pressed)
		{
			u8 z=7;
			u8 y  ;
			for(u8 i=0 ;i<=3 ;i++)
			{
				y=i+z;
				LED_voidOn(Arry_Leds[i]);
				LED_voidOn(Arry_Leds[y]);
				_delay_ms(250);
				
				LED_voidOff(Arry_Leds[i]);
				LED_voidOff(Arry_Leds[y]);
				z-=2;
				
				if(i == 3)
				{
					u8 z=1;
					u8 y  ;
					for(s8 i=3 ;i>=0 ;i--)
					{
						y=i+z;
						LED_voidOn(Arry_Leds[i]);
						LED_voidOn(Arry_Leds[y]);
						_delay_ms(250);
						
						LED_voidOff(Arry_Leds[i]);
						LED_voidOff(Arry_Leds[y]);
						z+=2;
					}
				}
				
			}
		}
		else
		{
			DIO_enumSetPortValue(DIO_PORTC , DIO_PIN_LOW);

		}
    }
}

