#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendString(const char *ptr);
void CLCD_voidSendPosition(u8 Copy_u8X,u8 Copy_u8Y);











#endif
