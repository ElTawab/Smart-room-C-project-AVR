#define KPD_CONFIG_H_
#include"bit.h"
#include"STD_TYPES.h"
#include"avr/delay.h"
#include"DIO_Interface.h"
#include"KPD_Config.h""

	u8 number[4][4]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10};

u8 letter[4][4]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

u8 letter2[4][4]={'R','S','T','U','V','W','X','Y','Z','+','*','#','!',' ','&','Q'};
void KPD_Init(void)
{
	DIO_VidSetPinDirection(KPD_PORT,COL1,OUTPUT );
	DIO_VidSetPinDirection(KPD_PORT,COL2,OUTPUT );
	DIO_VidSetPinDirection(KPD_PORT,COL3,OUTPUT );
	DIO_VidSetPinDirection(KPD_PORT,COL4,OUTPUT );
	DIO_VidSetPinDirection(KPD_PORT,ROW1,INPUT );
	DIO_VidSetPinDirection(KPD_PORT,ROW2,INPUT );
	DIO_VidSetPinDirection(KPD_PORT,ROW3,INPUT );
	DIO_VidSetPinDirection(KPD_PORT,ROW4,INPUT );
	DIO_VidSetPortValue(KPD_PORT, 255);
}

u8 KPD_u8GetPressedKey(u8 mode,u8 stop)//mode to choose between letters and numbers and stop as it won't terminate unless it takes value of user or it returns initial value
{while(1)
{
	u8 LOC_u8Column;
	u8 LOC_u8Row;
	u8 LOC_u8Return='@';//an initial value not expected to be used

	for(LOC_u8Column=4;LOC_u8Column<8;LOC_u8Column++)
	{
		DIO_VidSetPinValue(KPD_PORT, LOC_u8Column, LOW);
		for(LOC_u8Row=0;LOC_u8Row<4;LOC_u8Row++)
		{
			if(!DIO_U8GetPinValue(KPD_PORT, LOC_u8Row))
			{if(0==mode)
				LOC_u8Return=number[LOC_u8Row][LOC_u8Column-4];
			else if(1==mode)
				LOC_u8Return=letter[LOC_u8Row][LOC_u8Column-4];
				while(!DIO_U8GetPinValue(KPD_PORT, LOC_u8Row))
					_delay_ms(10);

			}
		}
		DIO_VidSetPinValue(KPD_PORT, LOC_u8Column, HIGH);
	}

	if(stop ==0 )
		return LOC_u8Return;
	if(LOC_u8Return!='@')
	return LOC_u8Return;

}}
