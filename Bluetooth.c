#include "std_lib.h"
#include "utils.h"
#include "registers.h"
#include "dio.h"
#include "Bluetooth.h"

void BluetoothIniti (void)
{
	set_bit(UCSRB,Receiver);
	set_bit(UCSRB,Transmitter);
	UCSRC=0b10000110;
	UBRRL=MyBaudRate;
	UBRRH=(MyBaudRate>>8);
	DIO_vidSetPinDirection(UARTPort,RX,IN);
	DIO_vidSetPinDirection(UARTPort,TX,OP);
}

void BluetoothTransmit (u8 data)
{
	while(get_bit(UCSRA,DataRegisterEmptyFlag)==0);
	// register of receiving or transmitting data (data Register)
	UDR=data;
}

u8 BluetoothReceive (void)
{
	while (get_bit(UCSRA,ReceiveCompleteFlag)==0);
	return UDR;
}
