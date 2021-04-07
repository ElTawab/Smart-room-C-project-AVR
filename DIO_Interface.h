#ifndef _DIO_Interface_H_
#define _DIO_Interface_H_


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW  0

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3



// set direction of a pin as input "0" or output "1" 
void DIO_VidSetPinDirection(u8 LOC_U8Port, u8 LOC_U8Pin, u8 LOC_U8Direction);

// set the value of a pin in a specific port
void DIO_VidSetPinValue(u8 LOC_U8Port, u8 LOC_U8Pin, u8 LOC_U8Value);

// change the value of a pin from zero to one and vice versa
void DIO_VidTogglePin(u8 LOC_U8Port, u8 LOC_U8Pin );

// get the value of a pin
u8 DIO_U8GetPinValue(u8 LOC_U8Port, u8 LOC_U8Pin);

// set direction of a port as input "0" or output "1" 
void DIO_VidSetPortDirection(u8 LOC_U8Port, u8 LOC_U8Direction);

// set the value of a pin in a specific port
void DIO_VidSetPortValue(u8 LOC_U8Port, u8 LOC_U8Value);
#endif