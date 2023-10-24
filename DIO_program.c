#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPortDir(u8 Copy_u8Port,u8 Copy_u8Dir)
{

	switch(	Copy_u8Port)
	{
	case A :DDRA=Copy_u8Dir;break;
	case B :DDRB=Copy_u8Dir;break;
	case C :DDRC=Copy_u8Dir;break;
	case D :DDRD=Copy_u8Dir;break;
	}

}

void DIO_voidSetPortVal(u8 Copy_u8Port,u8 Copy_u8Val)
{

	switch(	Copy_u8Port)
	{
	case A :PORTA=Copy_u8Val;break;
	case B :PORTB=Copy_u8Val;break;
	case C :PORTC=Copy_u8Val;break;
	case D :PORTD=Copy_u8Val;break;
	}

}

void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir)
{
	if(Copy_u8Pin<=7)
	{
		if(Copy_u8Dir==PIN_DIR_OUT)
		{
			switch(Copy_u8Port)
			{
			case A:SET_BIT(DDRA,Copy_u8Pin);break;
			case B:SET_BIT(DDRB,Copy_u8Pin);break;
			case C:SET_BIT(DDRC,Copy_u8Pin);break;
			case D:SET_BIT(DDRD,Copy_u8Pin);break;
			}
		}
		else if(Copy_u8Dir==PIN_DIR_IN)
		{
			switch(Copy_u8Port)
			{
			case A:CLR_BIT(DDRA,Copy_u8Pin);break;
			case B:CLR_BIT(DDRB,Copy_u8Pin);break;
			case C:CLR_BIT(DDRC,Copy_u8Pin);break;
			case D:CLR_BIT(DDRD,Copy_u8Pin);break;

			}
		}
	}
}

void DIO_voidSetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Val)
{
	if(Copy_u8Pin<=7)
	{
		if(Copy_u8Val==PIN_VAL_HIGH)
		{
			switch(Copy_u8Port)
			{
			case A:SET_BIT(PORTA,Copy_u8Pin);break;
			case B:SET_BIT(PORTB,Copy_u8Pin);break;
			case C:SET_BIT(PORTC,Copy_u8Pin);break;
			case D:SET_BIT(PORTD,Copy_u8Pin);break;
			}
		}
		else if(Copy_u8Val==PIN_VAL_LOW)
		{
			switch(Copy_u8Port)
			{
			case A:CLR_BIT(PORTA,Copy_u8Pin);break;
			case B:CLR_BIT(PORTB,Copy_u8Pin);break;
			case C:CLR_BIT(PORTC,Copy_u8Pin);break;
			case D:CLR_BIT(PORTD,Copy_u8Pin);break;

			}
		}
	}

}
u8 DIO_u8GetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Reading;
	if(Copy_u8Pin<=7)
	{
		switch(Copy_u8Port)
		{
		case A :Local_u8Reading=GET_BIT(PINA,Copy_u8Pin);break;
		case B :Local_u8Reading=GET_BIT(PINB,Copy_u8Pin);break;
		case C :Local_u8Reading=GET_BIT(PINC,Copy_u8Pin);break;
		case D :Local_u8Reading=GET_BIT(PIND,Copy_u8Pin);break;
		}
	}
	return Local_u8Reading;
}
