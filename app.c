#include "std_lib.h"
#include "utils.h"
#include "dio.h"
#include "LED.h"
#include "Bluetooth.h"
#include "configeration.h"
#include "avr/delay.h"
void main (void)
{

	BluetoothIniti();
	DIO_vidSetPinDirection(A,Pin0,OP);
	DIO_vidSetPinDirection(A,Pin1,OP);
	DIO_vidSetPinDirection(A,Pin2,OP);
	DIO_vidSetPinDirection(A,Pin3,OP);
	while (1)
	{
		if(BluetoothReceive()=='F')
		{
#if(NormalSpeedMode==Enable)
			//right motor
			DIO_vidWritePinValue(A,IN1,High);
			DIO_vidWritePinValue(A,IN2,Low);
			//left motor
			DIO_vidWritePinValue(A,IN3,Low);
			DIO_vidWritePinValue(A,IN4,High);
#endif
#if(SpeedControlMode==Enable)
#endif
		}
		if(BluetoothReceive()=='B')
		{
#if(NormalSpeedMode==Enable)
			//right motor
			DIO_vidWritePinValue(A,IN1,Low);
			DIO_vidWritePinValue(A,IN2,High);
			//left motor
			DIO_vidWritePinValue(A,IN3,High);
			DIO_vidWritePinValue(A,IN4,Low);
#endif
#if(SpeedControlMode==Enable)
			if (BluetoothReceive()=='F')
			{

			}
#endif
		}
		if(BluetoothReceive()=='S')
		{
			//right motor
			DIO_vidWritePinValue(A,IN1,Low);
			DIO_vidWritePinValue(A,IN2,Low);
			//left motor
			DIO_vidWritePinValue(A,IN3,Low);
			DIO_vidWritePinValue(A,IN4,Low);
		}
		//Light system
		if(BluetoothReceive()=='W')
		{

			DIO_vidLedOn(Ledport,Led1pin);
			DIO_vidLedOn(Ledport,Led2pin);
		}
		if(BluetoothReceive()=='w')
		{
			DIO_vidLedOff(Ledport,Led1pin);
			DIO_vidLedOff(Ledport,Led2pin);
		}

		if(BluetoothReceive()=='U')
		{
			DIO_vidLedOn(Ledport,Led3pin);
			DIO_vidLedOn(Ledport,Led4pin);
		}
		if(BluetoothReceive()=='u')
		{
			DIO_vidLedOff(Ledport,Led3pin);
			DIO_vidLedOff(Ledport,Led4pin);
		}
		if((BluetoothReceive()=='W')&&(BluetoothReceive()=='U'))
		{
			DIO_vidLedOn(Ledport,Led1pin);
			DIO_vidLedOn(Ledport,Led2pin);
			DIO_vidLedOn(Ledport,Led3pin);
			DIO_vidLedOn(Ledport,Led4pin);
		}
	}
}
