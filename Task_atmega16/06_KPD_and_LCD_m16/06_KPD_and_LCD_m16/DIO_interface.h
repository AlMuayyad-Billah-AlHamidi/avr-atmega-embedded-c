/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	   DIO_interface.h 	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 
* Author : Al_Moaiyad Bellah Al_Hemadi
* Layer  : MCAL
* Sw     : DIO/GPIO
*
*/



#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

typedef enum
 {
	 DIO_NOK,
	 DIO_OK
 }DIO_ErrorStatus;

#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0

#define DIO_PORT_OUTPUT  0xff
#define DIO_PORT_INPUT   0

#define DIO_NIBBLE_OUTPUT   1
#define DIO_NIBBLE_INPUT    0

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

//
#define DIO_PUD    2

// Configuration Pin
DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8DIRECTION);
DIO_ErrorStatus DIO_enumSetPinValue    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE    );
DIO_ErrorStatus DIO_enumGitPinValue    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 *Copy_PtrData   );
DIO_ErrorStatus DIO_enumTogglePinValue (u8 Copy_u8PORT , u8 Copy_u8PIN 					    );
void			DIO_voidEnablePinPullUp(u8 Copy_u8PORT , u8 Copy_u8PIN						);


//Configuration Port
DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT , u8 Copy_u8DIRECTION   );
DIO_ErrorStatus DIO_enumSetPortValue    (u8 Copy_u8PORT , u8 Copy_u8VALUE       );
DIO_ErrorStatus DIO_enumTogglePortValue (u8 Copy_u8PORT 					    );
DIO_ErrorStatus DIO_enumGitPortValue    (u8 Copy_u8PORT , u8 *Copy_PtrData      );
void		    DIO_voidDisablePullUp   (										);

// Configuration Nibble
void DIO_voidSetLowNibbleDirection  ( u8 Copy_u8PORT , u8 Copy_u8DIRECTION );
void DIO_voidSetHighNibbleDirection ( u8 Copy_u8PORT , u8 Copy_u8DIRECTION );
void DIO_voidWriteLowNibble 		( u8 Copy_u8PORT , u8 Copy_u8Vlue  	   );
void DIO_voidWriteHighNibble		( u8 Copy_u8PORT , u8 Copy_u8Vlue      );


#endif