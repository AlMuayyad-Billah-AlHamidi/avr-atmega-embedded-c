/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 SWITCH_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : SWITCH
*
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWITCH_private.h"
#include "SWITCH_interface.h"
#include "SWITCH_config.h"

void 	  SWITCH_voidInit ( SW_Type Copy_structConfig )
{
	DIO_enumSetPinDirection( Copy_structConfig.PORT ,Copy_structConfig.PIN ,DIO_PIN_INPUT);
	
	/* if sw is internal pull up */
	if (Copy_structConfig.Pull_State == SW_Int_PULL_UP)
	{
		DIO_enumSetPinValue( Copy_structConfig.PORT ,Copy_structConfig.PIN ,DIO_PIN_HIGH);
	}
}

SW_Status SWITCH_emumGetPressed(SW_Type Copy_structConfig)
{
	SW_Status LOC_enumStatus = SW_NotPressed;
	u8 Local_u8PinValue = 0;
	DIO_enumGitPinValue ( Copy_structConfig.PORT , Copy_structConfig.PIN , &Local_u8PinValue  );

	if( Copy_structConfig.Pull_State == SW_Ext_PULL_DOWN)
	{
		if(Local_u8PinValue == 1)
		{
			LOC_enumStatus = SW_Pressed;
		}
		else
		{
			LOC_enumStatus = SW_NotPressed;
		}
		
	}
	
	if( (Copy_structConfig.Pull_State == SW_Int_PULL_UP) || (Copy_structConfig.Pull_State == SW_Ext_PULL_UP) )
	{
		if(Local_u8PinValue == 0)
		{
			LOC_enumStatus = SW_Pressed;
		}
		else
		{
			LOC_enumStatus = SW_NotPressed;
		}
		
	}
	
	return LOC_enumStatus;
}