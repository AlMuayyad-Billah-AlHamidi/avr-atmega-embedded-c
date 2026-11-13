/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 KPD_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : KPD
*
*/
#define F_CPU 1000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KPD_private.h"
#include "KPD_interface.h"
#include "KPD_config.h"

/*
  Breif : this function intialize the pin which connected to KPD as input pins
  Parameters : Nothing
  return : Nothing 
*/
void 	  KPD_voidInit		   ( void )
{
	
	/*	connect pullup for the pins of the rows			*/
	
	DIO_voidEnablePinPullUp(KPD_PORT ,  KPD_R0);
	DIO_voidEnablePinPullUp(KPD_PORT ,  KPD_R1);
	DIO_voidEnablePinPullUp(KPD_PORT ,  KPD_R2);
	DIO_voidEnablePinPullUp(KPD_PORT ,  KPD_R3);
	
	
	/*	connect the pins of the columns as output pins (HIGH)			*/
	
    DIO_enumSetPinDirection(KPD_PORT , KPD_C0 , DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(KPD_PORT , KPD_C1 , DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(KPD_PORT , KPD_C2 , DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(KPD_PORT , KPD_C3 , DIO_PIN_OUTPUT);		
																			
	DIO_enumSetPinValue(KPD_PORT , KPD_C0 , DIO_PIN_HIGH    );
	DIO_enumSetPinValue(KPD_PORT , KPD_C1 , DIO_PIN_HIGH    );
	DIO_enumSetPinValue(KPD_PORT , KPD_C2 , DIO_PIN_HIGH    );
	DIO_enumSetPinValue(KPD_PORT , KPD_C3 , DIO_PIN_HIGH    );
	
}
/*
  Breif : this function used to get the pressed button of the KPD
  Parameters : Nothing
  return : the pressed button 
*/
u8	kpd_u8GetPressed(void)
{
	u8 Loc_u8ReturnData = NOT_PRESSED;
	u8 Loc_u8GetPressed ;
	
	/* iterators */
	u8 Loc_u8Row;
	u8 Loc_u8Col;
	
	for (Loc_u8Col = 0 + KPD_COL_INT ; Loc_u8Col < KPD_COL_END + 1 ; Loc_u8Col++ )
	{
		DIO_enumSetPinValue(KPD_PORT , Loc_u8Col , DIO_PIN_LOW );
		for (Loc_u8Row = 0 + KPD_ROW_INT ; Loc_u8Row < KPD_ROW_END + 1 ; Loc_u8Row++)
		{
			 DIO_enumGitPinValue(KPD_PORT , Loc_u8Row , &Loc_u8GetPressed);
			 /*
				if the row  is high ... there is no pressed buttons
				if the row  is low  ... there is  pressed button ===> i will check on this
			 */
			 if (Loc_u8GetPressed == DIO_PIN_LOW)
			 {
					
				 _delay_ms(50); //delay for bouncing
				 DIO_enumGitPinValue(KPD_PORT , Loc_u8Row , &Loc_u8GetPressed);
				 
				 if (Loc_u8GetPressed == DIO_PIN_LOW) //to make sure that button is pressed
				 {
					 /*		#important_note#
						the button will know by the row and the column (ASCII Code)
						==>Hint1 :I already defined The ASCII Codes in 2D array at ===> "KPD_config.h"
						==>Hint2 :if there is no pressed buttons , it will returned NOT_PRESSED (0xff) and there is not any pressed button
					*/
					 
					 Loc_u8ReturnData = KPD_u8Buttons[Loc_u8Row - KPD_ROW_INT ][Loc_u8Col - KPD_COL_INT];
				 }
				 // stay here if the button is pressed # we could put delay 200ms instead of that
				 DIO_enumGitPinValue(KPD_PORT , Loc_u8Row , &Loc_u8GetPressed);
				 while( DIO_PIN_LOW == Loc_u8GetPressed) //this cond for safty instead of (Loc_u8GetPressed == DIO_PIN_LOW)
				 {
					  DIO_enumGitPinValue(KPD_PORT , Loc_u8Row , &Loc_u8GetPressed);
				 }
				 
				 break;
				 	 
			 }
			 
		}
		
		// return this column's pin to high
		DIO_enumSetPinValue(KPD_PORT , Loc_u8Col , DIO_PIN_HIGH);
		
			
	}
	
	return Loc_u8ReturnData;
}
