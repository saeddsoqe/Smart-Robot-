#include "std_lib.h"
#include "utils.h"
#include "registers.h"
#include "dio.h"
#include "H_bridge.h"
#include "H_bridgeConfig.h"

void H_bridgeIniti (void)
{
#if(NormalMode==Enable)
	//Please note this initialization for only one h-bridge
	//and we use timer zero and timer 1A feel free to choose any timer
	//for left motor
	DIO_vidSetPinDirection(controlregister,Input1,High);
	DIO_vidSetPinDirection(controlregister,Input2,High);
	//for right motor
	DIO_vidSetPinDirection(controlregister,Input3,High);
	DIO_vidSetPinDirection(controlregister,Input4,High);
#endif
#if(SpeedMode==Enable)
	//for left motor
	DIO_vidSetPinDirection(controlregister,Input1,High);
	DIO_vidSetPinDirection(controlregister,Input2,High);
	//for right motor
	DIO_vidSetPinDirection(controlregister,Input3,High);
	DIO_vidSetPinDirection(controlregister,Input4,High);
	//for timer zero
#if(Timerzero==Enable)
	TCCR0=0b01111101;
	DIO_vidSetPinDirection(PwmControlPort0,PWMPin1,High);
#endif
#if(Timerone==Enable)
#if(oc1B==Enable)
	// we will add the initialization soon
	DIO_vidSetPinDirection(PwmControlPort1,PWMPin2,High);
#endif
#if(oc1A==Enable)
	DIO_vidSetPinDirection(PwmControlPort1,PWMPin3,High);
#endif
#endif
#if(Timertwo==Enable)
	TCCR2=0b01111101;
	DIO_vidSetPinDirection(PwmControlPort2,PWMPin4,High);
#endif

#endif
}

void Forword_Moving (u8 speed)
{
#if (NormalMode==Enable)
	//right motor
	DIO_vidWritePinValue(controlregister,Input1,High);
	DIO_vidWritePinValue(controlregister,Input2,Low);
	//left motor
	DIO_vidWritePinValue(controlregister,Input2,Low);
	DIO_vidWritePinValue(controlregister,Input4,High);
#endif
#if(SpeedMode==Enable)
	//right motor
	DIO_vidWritePinValue(controlregister,Input1,High);
	DIO_vidWritePinValue(controlregister,Input2,Low);
	//left motor
	DIO_vidWritePinValue(controlregister,Input2,Low);
	DIO_vidWritePinValue(controlregister,Input4,High);
	SpeedValue(speed);
#endif
}

void Backword_Moving (u8 speed)
{
#if (NormalMode==Enable)
	//right motor
	DIO_vidWritePinValue(controlregister,Input1,High);
	DIO_vidWritePinValue(controlregister,Input2,Low);
	//left motor
	DIO_vidWritePinValue(controlregister,Input2,Low);
	DIO_vidWritePinValue(controlregister,Input4,High);
#endif
#if(SpeedMode==Enable)
	//right motor
	DIO_vidWritePinValue(controlregister,Input1,Low);
	DIO_vidWritePinValue(controlregister,Input2,High);
	//left motor
	DIO_vidWritePinValue(controlregister,Input2,High);
	DIO_vidWritePinValue(controlregister,Input4,Low);
	SpeedValue(speed);
#endif

}

void SpeedValue (u8 speed)
{
#if(Timerzero==Enable)
	u8 DutyCycle;
	speed=100-speed;
	if ((speed>0)&&(speed<=99))
	{
		DutyCycle=(speed*256)/100;
	}
	//this the duty cycle in this case its 25% of the 256 of the register
	OCR0=DutyCycle;
	DIO_vidWritePinValue(PwmControlPort0,Input1,High);
#endif
#if(Timertwo==Enable)
	u8 DutyCycle;
	speed=100-speed;
	if ((speed>0)&&(speed<=99))
	{
		DutyCycle=(speed*256)/100;
	}
	//this the duty cycle in this case its 25% of the 256 of the register
	OCR2=DutyCycle;
	DIO_vidWritePinValue(PwmControlPort2,Input4,High);
#endif
	//for timer one it will come soon

}





