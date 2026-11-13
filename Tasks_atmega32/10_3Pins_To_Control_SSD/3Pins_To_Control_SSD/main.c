/*
 * 3Pins_To_Control_SSD.c
 *
 * Created: 9/11/2024 2:30:35 PM
 * Author : MouhannadlrX
 */
#define F_CPU 16000000UL 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "74HC595_private.h"
#include "74HC595_interface.h"
#include "74HC595_config.h"
#include <util/delay.h>

int main(void)
{
   SHIFT_REGISTER_Type shift_register ={DIO_PORTC,DIO_PIN0,DIO_PIN1,DIO_PIN2};
   SHIFT_REGISTER_voidSetDirection ( shift_register );   

    while (1) 
    {
		for (u8 i = 0; i<10 ;i++)
		{
			shift_register.Send_Number =i;
			SHIFT_REGISTER_voidDisplayDigit ( shift_register );
			_delay_ms(300);
		}
		
    }
}

