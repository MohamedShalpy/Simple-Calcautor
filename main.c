#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "kpd_interface.h"
#include "CLCD_interface.h"

#include "util/delay.h"



void main(void)
{
	DIO_voidSetPortDir(D,PORT_DIR_OUT);
	DIO_voidSetPortDir(C,PORT_DIR_OUT);
	DIO_voidSetPortDir(B,PORT_DIR_OUT);
	DIO_voidSetPortDir(A,PORT_DIR_OUT);
    kpd_init();
	CLCD_voidInit();
	u8 Local_key;
	u16 arr[10];
	f32 num1;
	f32 num2;
	u8 operator;
	u16 ans=0;
	u8 div=0;
	u8 i=0;
	u8 j=0;
	while(1)
	{
		Local_key=kpd_get();
		if((Local_key==1)|(Local_key==2)|(Local_key==3)|(Local_key==5)|(Local_key==6)|(Local_key==7)|(Local_key==9)|(Local_key==10)|(Local_key==11)|(Local_key==14))
		{
			switch(Local_key)
			{
			case 1: arr[i]=7; CLCD_voidSendString("7");_delay_ms(10);break;
			case 2: arr[i]=8; CLCD_voidSendString("8");_delay_ms(10);break;
			case 3: arr[i]=9; CLCD_voidSendString("9");_delay_ms(10);break;
			case 5: arr[i]=4; CLCD_voidSendString("4");_delay_ms(10);break;
			case 6: arr[i]=5; CLCD_voidSendString("5");_delay_ms(10);break;
			case 7: arr[i]=6; CLCD_voidSendString("6");_delay_ms(10);break;
			case 9: arr[i]=1; CLCD_voidSendString("1");_delay_ms(10);break;
			case 10: arr[i]=2; CLCD_voidSendString("2");_delay_ms(10);break;
			case 11: arr[i]=3; CLCD_voidSendString("3");_delay_ms(10);break;
			case 14: arr[i]=0; CLCD_voidSendString("0");_delay_ms(10);break;
			}
			for(j=0;j<i;j++)
			{
				arr[j] *= 10;

			}
			i++;

		}
		if((Local_key==4)|(Local_key==8)|(Local_key==12)|(Local_key==16))
		{
			for(j=0;j<i;j++)
			{
				num1 += arr[j];
			}
			i=0;

			operator=Local_key;

			switch(operator)
			{
			case 4: CLCD_voidSendString("/");_delay_ms(10);break;
			case 8: CLCD_voidSendString("*");_delay_ms(10);break;
			case 12: CLCD_voidSendString("-");_delay_ms(10);break;
			case 16: CLCD_voidSendString("+");_delay_ms(10);break;

			}
		}
		if(Local_key==15)
		{
			CLCD_voidSendString("=");
			for(j=0;j<i;j++)
			{
				num2 += arr[j];
			}
			i=0;


			switch(operator)
			{
			case 4:
				if(num2 != 0)
				{
					ans= num1 / num2;
					div = (ans - (int)ans)*100;
					CLCD_voidSendNum(ans);
					CLCD_voidSendString(".");
					CLCD_voidSendNum(div);
					_delay_ms(10);
					break;
				}
				else
				{
					CLCD_voidSendString("cant div on zero");
					_delay_ms(100);
					break;
				}

			case 8:
				ans = num1 * num2;
				CLCD_voidSendNum(ans);
				_delay_ms(10);
				break;
			case 12:
				if(num1 >= num2)
				{
					ans= num1 - num2;
					CLCD_voidSendNum(ans);
					_delay_ms(10);
					break;
				}
				else
				{
					ans= num2 - num1;
					CLCD_voidSendString("-");
					CLCD_voidSendNum(ans);
					_delay_ms(10);
					break;
				}

			case 16:
				ans= num1 + num2;
				CLCD_voidSendNum(ans);
				_delay_ms(10);
				break;
			}
			num1=0;
			num2=0;
			ans=0;
			div=0;
		}
		if(Local_key==13)
		{
			CLCD_voidInit();
			num1=0;
			num2=0;
			ans=0;
			div=0;
		}
	}

}





