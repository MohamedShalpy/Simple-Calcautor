/***********************************************************************/
/***********************************************************************/
/********************SWC: DIO***********************************/
/********************Layer :MCAL******************************************/
/********************Author: Yousef Ahmad*****************************************/
/********************Date :8 sep 2023*********************************/
/********************Ver:01*************************************/
/***********************************************************************/




#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


void DIO_voidSetPortDir(u8 Copy_u8Port,u8 Copy_u8Dir);

void DIO_voidSetPortVal(u8 Copy_u8Port,u8 Copy_u8Val);

void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir);

void DIO_voidSetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Val);


u8 DIO_u8GetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin);





#define A        1
#define B        2
#define C        3
#define D        4

#define PIN_DIR_IN    0
#define PIN_DIR_OUT   1

#define PIN_VAL_HIGH  1
#define PIN_VAL_LOW  0

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7

#define PORT_DIR_OUT    0XFF
#define PORT_DIR_IN     0X00

#define PORT_VAL_HIGH   0XFF
#define PORT_VAL_LOW    0X00





#endif
