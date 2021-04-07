#ifndef _DIO_Register_H_
#define _DIO_Register_H_


#define DDRA  *((volatile u8*) 0x3A )
#define PINA *((volatile u8*) 0x39)
#define PORTA *((volatile u8*) 0x3B)

#define DDRB  *((volatile u8*) 0x37 )
#define PINB *((volatile u8*) 0x36)
#define PORTB *((volatile u8*) 0x38)

#define DDRC  *((volatile u8*) 0x34 )
#define PINC *((volatile u8*) 0x33)
#define PORTC *((volatile u8*) 0x35)

#define DDRD  *((volatile u8*) 0x31 )
#define PIND *((volatile u8*) 0x30)
#define PORTD *((volatile u8*) 0x32)
#endif