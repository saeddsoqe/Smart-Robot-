#include "std_lib.h"
#include "registers.h"
#include "utils.h"
#include "dio.h"
//To Set Direction
void DIO_vidSetPortDirection (u8 port , u8 dir)
{
	switch (port)
	{
	case 0:
		DDRA=dir;
		break;
	case 1:
	    DDRB=dir;
	    break;
	case 2:
		DDRC=dir;
		break;
	case 3:
		DDRD=dir;
		break;
	}
}
//To Set Port
void DIO_vidWritePortValue (u8 port , u8 dir)
{
	switch (port)
	{
	case 0:
		PORTA=dir;
		break;
	case 1:
		PORTB=dir;
		break;
	case 2:
		PORTC=dir;
		break;
	case 3:
		PORTD=dir;
		break;
	}
}
//To Read From port
u8 DIO_u8ReadPortValue (u8 port , u8 pin)
{
	u8 read=0;
	switch (port)
	{
	case 0:
		read=get_bit(DDRA,pin);
		break;
	case 1:
		read=get_bit(DDRB,pin);
		break;
	case 2:
		read=get_bit(DDRC,pin);
		break;
	case 3:
		read=get_bit(DDRD,pin);
		break;
	}
	return read;
}
void DIO_vidSetPinDirection (u8 Port,u8 Pin,u8 Dir)
{
	switch (Port)
	{
	   case 0:
		   if (Dir==0)
		   {
			  clr_bit(DDRA,Pin);
		   }
		   else if(Dir==1)
		   {
			   set_bit(DDRA,Pin);
		   }
		   break;
	   case 1:
		   if (Dir==0)
		   {
			   clr_bit(DDRB,Pin);
		   }
		   else if (Dir==1)
		   {
			   set_bit(DDRB,Pin);
		   }
		   break;
	   case 2:
		   if(Dir==0)
		   {
			   clr_bit(DDRC,Pin);
		   }
		   else if (Dir==1)
		   {
			   set_bit(DDRC,Pin);
		   }
		   break;
	   case 3:
		   if (Dir==0)
		   {
			   clr_bit(DDRD,Pin);
		   }
		   else if (Dir==1)
		   {
			   set_bit(DDRD,Pin);
		   }
		   break;
	}
}
u8 DIO_u8GetPinValue (u8 Port,u8 Pin)
{
	switch(Port)
	{
	case 0:
		return get_bit(PINA,Pin);
	case 1:
		return get_bit(PINB,Pin);
	case 2:
		return get_bit(PINC,Pin);
	case 3:
		return get_bit(PIND,Pin);
	default :
	return 4;
	}
}
void DIO_vidWritePinValue (u8 Port, u8 Pin,u8 Dir )
{
	switch(Port)
	{
	case 0:
		if(Dir==0)
		{
			clr_bit(PORTA,Pin);
		}
		else if (Dir==1)
		{
			set_bit(PORTA,Pin);
		}
		break;
	case 1:
		if (Dir==0)
		{
			clr_bit(PORTB,Pin);
		}
		else if (Dir==1)
		{
			set_bit(PORTB,Pin);
		}
		break;
	case 2:
		if(Dir==0)
		{
			clr_bit(PORTC,Pin);
		}
		else if (Dir==1)
		{
			set_bit(PORTC,Pin);
		}
		break;
	case 3:
		if(Dir==0)
		{
			clr_bit(PORTD,Pin);
		}
		else if(Dir==1)
		{
			set_bit(PORTD,Pin);
		}
		break;
	}
}
