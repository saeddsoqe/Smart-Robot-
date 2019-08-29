#include "std_lib.h"
#include "utils.h"
#include "registers.h"
#include "dio.h"
#include "LED.h"
void DIO_vidLedOn (u8 port,u8 pin)
{
	DIO_vidSetPinDirection(port,pin,OP);
	DIO_vidWritePinValue(port,pin,High);
}
void DIO_vidLedOff (u8 port , u8 pin)
{
	DIO_vidSetPinDirection(port,pin,Low);
	DIO_vidWritePinValue(port,pin,Low);
}
