#include"bit.h"
#include"STD_TYPES.h"
#include"DIO_Register.h"
void DIO_VidSetPinDirection(u8 LOC_U8Port, u8 LOC_U8Pin, u8 LOC_U8Direction)
{if(1== LOC_U8Direction)
	{switch(LOC_U8Port)
	{
		case 0:set_bit(DDRA,LOC_U8Pin);break;
		case 1:set_bit(DDRB,LOC_U8Pin);break;
		case 2:set_bit(DDRC,LOC_U8Pin);break;
		case 3:set_bit(DDRD,LOC_U8Pin);break;
	}}
	
	else if(0== LOC_U8Direction)
	{switch(LOC_U8Port)
	{
		case 0:clr_bit(DDRA,LOC_U8Pin);break;
		case 1:clr_bit(DDRB,LOC_U8Pin);break;
		case 2:clr_bit(DDRC,LOC_U8Pin);break;
		case 3:clr_bit(DDRD,LOC_U8Pin);break;
	}}
}

void DIO_VidSetPinValue(u8 LOC_U8Port, u8 LOC_U8Pin, u8 LOC_U8Value)
{
	if(1== LOC_U8Value)
	{switch(LOC_U8Port)
	{
		case 0:set_bit(PORTA ,LOC_U8Pin);break;
		case 1:set_bit(PORTB ,LOC_U8Pin);break;
		case 2:set_bit(PORTC,LOC_U8Pin);break;
		case 3:set_bit(PORTD,LOC_U8Pin);break;
	}}
	
	else if(0== LOC_U8Value)
	{switch(LOC_U8Port)
	{
		case 0:clr_bit(PORTA,LOC_U8Pin);break;
		case 1:clr_bit(PORTB,LOC_U8Pin);break;
		case 2:clr_bit(PORTC,LOC_U8Pin);break;
		case 3:clr_bit(PORTD,LOC_U8Pin);break;
	}}
}

void DIO_VidSetPortDirection(u8 LOC_U8Port, u8 LOC_U8Direction)
{
if(1== LOC_U8Direction)
	{switch(LOC_U8Port)
	{
		case 0:DDRA=255;break;
		case 1:DDRB=255;break;
		case 2:DDRC=255;break;
		case 3:DDRD=255;break;
	}}
	
	else if(0== LOC_U8Direction)
	{switch(LOC_U8Port)
	{
		case 0:DDRA=0;break;
		case 1:DDRB=0;break;
		case 2:DDRC=0;break;
		case 3:DDRD=0;break;
	}}	
}

void DIO_VidSetPortValue(u8 LOC_U8Port, u8 LOC_U8Value)
{ 

	switch(LOC_U8Port)
	{
		case 0:PORTA=LOC_U8Value;break;
		case 1:PORTB=LOC_U8Value;break;
		case 2:PORTC=LOC_U8Value;break;
		case 3:PORTD=LOC_U8Value;break;
	}}
	


void DIO_VidTogglePin(u8 LOC_U8Port, u8 LOC_U8Pin )
{
	switch(LOC_U8Port)
	{
		case 0:toogle_bit(PORTA,LOC_U8Pin);break;
		case 1:toogle_bit(PORTB,LOC_U8Pin);break;
		case 2:toogle_bit(PORTC,LOC_U8Pin);break;
		case 3:toogle_bit(PORTD,LOC_U8Pin);break;
	}
}

u8 DIO_U8GetPinValue(u8 LOC_U8Port, u8 LOC_U8Pin)
{u8 x;
switch(LOC_U8Port)
	{
		case 0:x=get_bit(PINA,LOC_U8Pin);break;
		case 1:x=get_bit(PINB,LOC_U8Pin);break;
		case 2:x=get_bit(PINC,LOC_U8Pin);break;
		case 3:x=get_bit(PIND,LOC_U8Pin);break;
	}
return x;
}
