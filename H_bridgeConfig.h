#define controlregister A
#define controlregister B
#define controlregister C
#define controlregister D
// to control speed
#define PwmControlPort0 B
#define PwmControlPort1 D
#define PwmControlPort2 D
//those pins for normal control high or low
#define Input1 Pin0
#define Input2 Pin1
#define Input3 Pin2
#define Input4 Pin3
// those to control speed
//this pin for timer zero  OC0
#define PWMPin1 Pin3
//this pin for timer one  OC1B
#define PWMPin2 Pin4
//this pin for timer one  OC1A
#define PWMPin3 Pin5
//this pin for timer two  OC2
#define PWMPin4 Pin7
#define Enable 1
#define Disable 0
#define NormalMode Enable
#define SpeedMode  Disable
//choosing which timer
//please note in timer one which pin u want to work on
//enable it or disable or enable booth of them
#define Timerzero Enable
#define Timerone Diable
#define oc1B Disable
#define oc1A Diable
#define Timertwo Enable


