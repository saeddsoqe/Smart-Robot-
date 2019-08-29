#define A 0
#define B 1
#define C 2
#define D 3
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7
#define OP 1
#define IN 0
#define High 1
#define Low 0
void DIO_vidSetPortDirection (u8 port , u8 pin);
void DIO_vidWritePortValue (u8 port , u8 pin);
u8 DIO_u8ReadPortValue (u8 port , u8 pin);
void DIO_vidSetPinDirection (u8 Port,u8 Pin,u8 Dir);
u8 DIO_u8GetPinValue (u8 Port,u8 Pin);
void DIO_vidWritePinValue (u8 Port, u8 Pin,u8 Dir);
