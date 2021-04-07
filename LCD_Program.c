#include"bit.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"LCD_Config.h"
#include"avr/delay.h"
void LCD_VidInit(void)
{DIO_VidSetPortDirection(LCD_DATA_PORT,OUTPUT);
DIO_VidSetPinDirection(LCD_CONTROL_PORT,RS,OUTPUT);
DIO_VidSetPinDirection(LCD_CONTROL_PORT,RW,OUTPUT);
DIO_VidSetPinDirection(LCD_CONTROL_PORT,EN,OUTPUT);
	_delay_ms(50);
	LCD_VidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_VidSendCommand(0b00001100);
	_delay_ms(1);
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
}

void LCD_VidSendCommand(u8 u8CmdCpy)
{//set RS to low
	DIO_VidSetPinValue(LCD_CONTROL_PORT,RS,LOW);
	//Set R/W to low
	DIO_VidSetPinValue(LCD_CONTROL_PORT,RW,LOW);
	//Load command on data port
	DIO_VidSetPortValue(LCD_DATA_PORT, u8CmdCpy);
	//Enable
	DIO_VidSetPinValue(LCD_CONTROL_PORT,EN,HIGH);
	_delay_ms(5);
	DIO_VidSetPinValue(LCD_CONTROL_PORT,EN,LOW);
	_delay_ms(10);
}

void LCD_VidWriteCharctr(u8 u8DataCpy)
{
	//set RS to low
	DIO_VidSetPinValue(LCD_CONTROL_PORT,RS,HIGH);
	//Set R/W to low
	DIO_VidSetPinValue(LCD_CONTROL_PORT,RW,LOW);
	//Load command on data port
	DIO_VidSetPortValue(LCD_DATA_PORT, u8DataCpy);
	//Enable
	DIO_VidSetPinValue(LCD_CONTROL_PORT,EN,HIGH);
	_delay_ms(5);
	DIO_VidSetPinValue(LCD_CONTROL_PORT,EN,LOW);
	_delay_ms(10);
}

void LCD_VidWriteNumber(u16 n)
{
	u16 rev=0;
	u8 check_zero=0;
	if(n%10==0)
		check_zero++;
	if (n==0)
		{
		LCD_VidWriteCharctr('0');
		return;
		}
	else
	{
	while(n>0)
	{
		rev=(rev*10)+(n%10);
				n=n/10;
		}
	u16 y=0;
		while(rev>0)
		{
		y=rev%10;
		LCD_VidWriteCharctr(y+48);
		rev=rev/10;
		}
		if (check_zero>0)
			LCD_VidWriteCharctr(0+48);
	}
}

void LCD_VidSetPosition(u8 u8row , u8 u8column )
{
	if( u8row == 0 )
	{
		LCD_VidSendCommand(128 + u8column);
	}
	else  if ( u8row == 1 )
	{
		LCD_VidSendCommand(128 + 64 + u8column);
	}
}
void LCD_DrawChar(void)
{LCD_VidSendCommand(64);
LCD_VidWriteCharctr(0b00000001);
LCD_VidWriteCharctr(0b00000001);
LCD_VidWriteCharctr(0b00000000);
LCD_VidWriteCharctr(0b00000000);
LCD_VidWriteCharctr(0b00001111);
LCD_VidWriteCharctr(0b00000000);
LCD_VidWriteCharctr(0b00000000);
LCD_VidWriteCharctr(0b00000000);
}
