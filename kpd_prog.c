#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "kpd_config..h"
#include "kpd_interface.h"



u8 kpd_get(void)
{
	u8 LocalKey=NO_PRESSED_KEY;
	u8 col_itr=0,row_itr=0;
	u8 col_array[4]={C0,C1,C2,C3};
	u8 row_array[4]={R0,R1,R2,R3};
	for(col_itr=0;col_itr<MAX_COL;col_itr++)
	{
		DIO_voidSetPinVal(KPD_PORT,col_array[col_itr],PIN_VAL_LOW);
		for(row_itr=0;row_itr<MAX_ROW;row_itr++)
		{
			if(DIO_u8GetPinVal(KPD_PORT,row_array[row_itr])==0)
			{
				LocalKey=kpd_arr[row_itr][col_itr];
				while(DIO_u8GetPinVal(KPD_PORT,row_array[row_itr])==0)
				{

				}
				return LocalKey;
			}
		}
		DIO_voidSetPinVal(KPD_PORT,col_array[col_itr],PIN_VAL_HIGH);
	}
	return LocalKey;

}
void kpd_init(void)
{
	/*row input pull up*/
	DIO_voidSetPinDir(KPD_PORT,R0,PIN_DIR_IN);
	DIO_voidSetPinDir(KPD_PORT,R1,PIN_DIR_IN);
	DIO_voidSetPinDir(KPD_PORT,R2,PIN_DIR_IN);
	DIO_voidSetPinDir(KPD_PORT,R3,PIN_DIR_IN);

	DIO_voidSetPinVal(KPD_PORT,R0,PIN_VAL_HIGH);
	DIO_voidSetPinVal(KPD_PORT,R1,PIN_VAL_HIGH);
	DIO_voidSetPinVal(KPD_PORT,R2,PIN_VAL_HIGH);
	DIO_voidSetPinVal(KPD_PORT,R3,PIN_VAL_HIGH);


	/*COL OUT HIGH*/
	DIO_voidSetPinDir(KPD_PORT,C0,PIN_DIR_OUT);
	DIO_voidSetPinDir(KPD_PORT,C1,PIN_DIR_OUT);
	DIO_voidSetPinDir(KPD_PORT,C2,PIN_DIR_OUT);
	DIO_voidSetPinDir(KPD_PORT,C3,PIN_DIR_OUT);

	DIO_voidSetPinVal(KPD_PORT,C0,PIN_VAL_HIGH);
	DIO_voidSetPinVal(KPD_PORT,C1,PIN_VAL_HIGH);
	DIO_voidSetPinVal(KPD_PORT,C2,PIN_VAL_HIGH);
	DIO_voidSetPinVal(KPD_PORT,C3,PIN_VAL_HIGH);
}

