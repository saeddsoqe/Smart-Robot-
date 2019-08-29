// the internal frequency of the AVR
#define Fosc 12000000
// this is the Baud Rate of (speed of transmission
#define BaudeRate 9600
//we find this equation in table page num 141 u=in data sheet
#define MyBaudRate (Fosc/16/BaudeRate-1)
//receive pin in Port D
#define RX Pin0
//transmit pin in port D
#define TX Pin1
#define Enable 1
#define Disable 0
#define Transmitter 3
#define Receiver 4
#define UARTPort D
#define DataRegisterEmptyFlag 5
#define ReceiveCompleteFlag 7
void BluetoothIniti ();
void BluetoothTransmit (u8 data);
u8 BluetoothReceive (void);

