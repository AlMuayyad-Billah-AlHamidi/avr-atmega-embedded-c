/*
 * 3_Switches_with_Interrupts.c
 *
 * Created: 10/9/2024 2:52:29 PM
 * Author : Al_Moaiyad Bellah Al_Hemadi
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "LEDS_TEST_interface.h"
#include "SWITCH_interface.h"


void ISR_INT0(void);
void ISR_INT1(void);
void ISR_INT2(void);

LED_Type LED0 = {DIO_PORTA , DIO_PIN0 , ACTIVE_HIGH};
LED_Type LED1 = {DIO_PORTA , DIO_PIN1 , ACTIVE_HIGH};
LED_Type LED2 = {DIO_PORTA , DIO_PIN2 , ACTIVE_HIGH};
	
int main(void)
{
	

	LED_voidInit(LED0);
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	
	SW_Type SW0 = {DIO_PORTD , DIO_PIN2 , SW_Ext_PULL_DOWN };
	SW_Type SW1 = {DIO_PORTD , DIO_PIN3 , SW_Ext_PULL_DOWN };
	SW_Type SW2 = {DIO_PORTB , DIO_PIN2 , SW_Ext_PULL_DOWN };	
	SWITCH_voidInit(SW0);
	SWITCH_voidInit(SW1);
	SWITCH_voidInit(SW2);
	
	EXTI_voidInit ();
	EXTI_voidSetSignalLatch (EXTI_RISING_EDGE , EXTI_LINE1 );
	EXTI_voidSetSignalLatch (EXTI_RISING_EDGE , EXTI_LINE2 );
	
	EXTI_u8EnableInterrput  ( EXTI_LINE0 );
	EXTI_u8EnableInterrput  ( EXTI_LINE1 );
	EXTI_u8EnableInterrput  ( EXTI_LINE2 );
	
	/* Global interrupt enable */
	SET_BIT(SREG_REG , GLOBAL_INTERRUPT_ENABLE_PIN );
	
	EXTI_voidSetCallBack(ISR_INT0 , EXTI_LINE0);
	EXTI_voidSetCallBack(ISR_INT1 , EXTI_LINE1);
	EXTI_voidSetCallBack(ISR_INT2 , EXTI_LINE2);
	while(1)
    {
		
    }
}


void ISR_INT0(void)
{
	LED_voidOn(LED0);
}

void ISR_INT1(void)
{
	LED_voidOn(LED1);
}
void ISR_INT2(void)
{
	LED_voidOn(LED2);
}