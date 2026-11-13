/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	 Seven_Segments_Display_program.c 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : HAL
* Sw     : Seven_Segments
*
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_private.h"
#include "SSD_interface.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbers [10] = SSD_NUMBER_ARR;
static u8 Local_u8SSDCharacters [6] = SSD_CHARACTERS_ARR;
void	SSD_voidInitialDataPort ( SSD_Type Copy_structConfig )
{
	DIO_enumSetPortDirection( Copy_structConfig.DataPort , 0xFF);
}

void	SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number )
{
	
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE )
	{
		DIO_enumSetPortValue( Copy_structConfig.DataPort , Local_u8SSDNumbers[Copy_u8Number] );
	}
	
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE )
	{
		DIO_enumSetPortValue( Copy_structConfig.DataPort , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );
	}
	
}

void	SSD_voidSendCharacter   ( SSD_Type Copy_structConfig , u8 Copy_u8Character )
{
	
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE )
	{
		DIO_enumSetPortValue( Copy_structConfig.DataPort , Local_u8SSDCharacters[Copy_u8Character] );
	}
	
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE )
	{
		DIO_enumSetPortValue( Copy_structConfig.DataPort , ~( Local_u8SSDCharacters[ Copy_u8Character ] ) );
	}
	
}

void	SSD_voidEnable		    ( SSD_Type Copy_structConfig )
{
	
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE )
	{
		DIO_enumSetPinDirection ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue	    ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_LOW    );
	}
	
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE )
	{
		DIO_enumSetPinDirection ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue	    ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_HIGH   );
	}
	
}
	
void	SSD_voidDisable		    ( SSD_Type Copy_structConfig )
{
	
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE )
	{
		DIO_enumSetPinDirection ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue	    ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_HIGH   );
	}
	
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE )
	{
		DIO_enumSetPinDirection ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue	    ( Copy_structConfig.EnablePort  , Copy_structConfig.EnablePin , DIO_PIN_LOW    );
	}
	
}

