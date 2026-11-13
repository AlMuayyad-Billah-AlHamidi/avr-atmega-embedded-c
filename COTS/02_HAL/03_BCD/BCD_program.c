/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 BCD_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : BCD
*
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "BCD_private.h"
#include "BCD_interface.h"
#include "BCD_config.h"

static u8 Local_u8BCDNumbers [10] = BCD_NUMBER_ARR;

void	BCD_voidInitialDataNibble ( BCD_Type Copy_structConfig )
{
	if( Copy_structConfig.NibbleType == LOW_NIBBLE )
	{
		DIO_voidWriteLowNibble  ( Copy_structConfig.NibblePort , Local_u8BCDNumbers[ Copy_structConfig.NibbleValue ] );
	}
	
	else if( Copy_structConfig.NibbleType == HIGH_NIBBLE )
	{
		DIO_voidWriteHighNibble  ( Copy_structConfig.NibblePort , Local_u8BCDNumbers[ Copy_structConfig.NibbleValue ] );
	}
}


