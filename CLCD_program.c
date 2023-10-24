#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void CLCD_voidInit(void)
{
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	CLCD_voidSendCommand(1);
	_delay_ms(2);

}
void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*RS ->1*/
	DIO_voidSetPinVal(CTRL_PORT,RS,PIN_VAL_HIGH);
	/*RW ->0*/
	DIO_voidSetPinVal(CTRL_PORT,RW,PIN_VAL_LOW);

	/*WRITE DATA*/
	DIO_voidSetPortVal(DATA_PORT,Copy_u8Data);

	/*send enable pulse*/
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_LOW);

}
void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*RS ->0*/
	DIO_voidSetPinVal(CTRL_PORT,RS,PIN_VAL_LOW);
	/*RW ->0*/
	DIO_voidSetPinVal(CTRL_PORT,RW,PIN_VAL_LOW);
	/*WRITE COMMAND*/
	DIO_voidSetPortVal(DATA_PORT,Copy_u8Command);
	/*send enable pulse*/
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(CTRL_PORT,E,PIN_VAL_LOW);
}

void CLCD_voidSendString(const char *ptr)
{
	u8 Local_u8Iterator=0;
	while(ptr[Local_u8Iterator]!='\0')
	{
		CLCD_voidSendData(ptr[Local_u8Iterator]);
		Local_u8Iterator++;
	}
}
void CLCD_voidSendPosition(u8 Copy_u8X,u8 Copy_u8Y)
{
	u8 Local_u8Adress;
	if(Copy_u8X==0)
	{
		Local_u8Adress=Copy_u8Y;
	}
	else if(Copy_u8X==1)
	{
		Local_u8Adress=Copy_u8Y+0x40;
	}
	CLCD_voidSendCommand(Local_u8Adress+128);
}

void CLCD_voidSendNum(u16 Copy_u16Num)
{
	u8 arr[10],i=0,j;

	if(Copy_u16Num==0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(Copy_u16Num)
		{
			arr[i]=	Copy_u16Num%10 +'0';
			Copy_u16Num/=10;
			i++;
		}
	}
	for(j=i;j>0;j--)
	{
		CLCD_voidSendData(arr[j-1]);
	}
}

