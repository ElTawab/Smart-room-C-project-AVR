#include"bit.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"avr/delay.h"
#include "ADC_Register.h"
#include "ADC_Config.h"
void ADC_VidInit(void)
{
	clr_bit(ADMUX,REFS1);
	set_bit(ADMUX,REFS0);
	clr_bit(ADMUX,ADLAR);
	
	set_bit(ADCSRA,ADATE);
	set_bit(ADCSRA,ADPS2);
	clr_bit(ADCSRA,ADPS0);
	set_bit(ADCSRA,ADPS1);
	set_bit(ADCSRA,ADEN);
	
}

u16 ADC_U16ReadChannel(char channel)
{ADMUX=ADMUX&0b11100000;
	switch (channel)
	{
		case 7:set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);break;
		case 6:set_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);break;
		case 5:set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX2);break;
		case 4:set_bit(ADMUX,MUX2);break;
		case 3:set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);break;
		case 2:set_bit(ADMUX,MUX1);break;
		case 1:set_bit(ADMUX,MUX0);break;
		default:break;
	}
	
	set_bit(ADCSRA,ADSC);
   while(!get_bit(ADCSRA,ADIF));

   return ADC;
}
void ADCINT_VidInit(void)
{
	clr_bit(ADMUX,REFS1);
	set_bit(ADMUX,REFS0);
	clr_bit(ADMUX,ADLAR);
	set_bit(ADCSRA,ADIE);
	set_bit(ADCSRA,ADATE);
	set_bit(ADCSRA,ADPS2);
	clr_bit(ADCSRA,ADPS0);
	set_bit(ADCSRA,ADPS1);
	set_bit(ADCSRA,ADEN);

}

u16 ADCINT_U16ReadChannel(char channel)
{set_bit(ADCSRA,ADIE);
	ADMUX=ADMUX&0b11100000;
	switch (channel)
	{
		case 7:set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);break;
		case 6:set_bit(ADMUX,MUX1);
		set_bit(ADMUX,MUX2);break;
		case 5:set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX2);break;
		case 4:set_bit(ADMUX,MUX2);break;
		case 3:set_bit(ADMUX,MUX0);
		set_bit(ADMUX,MUX1);
		break;
		case 2:set_bit(ADMUX,MUX1);break;
		case 1:set_bit(ADMUX,MUX0);break;
		default:break;
	}

	set_bit(ADCSRA,ADSC);
  while(!get_bit(ADCSRA,ADIF));
   return ADC;
}

static void (*pcallback) (void)=0;
void SetCallBack(void (*pfuc)(void))
{
	pcallback=pfuc;
}

void __vector_16(void)

{
	if(pcallback != 0)
	pcallback();
}
