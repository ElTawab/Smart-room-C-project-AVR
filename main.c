//Smart Room AVR Project
#include "STD_TYPES.h"
#include "bit.h"
#define F_CPU 8000000UL
#include"avr/io.h"
#include"avr/delay.h"
#include "DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Interface.h"
#include"KPD_Interface.h"
#include"KPD_Config.h"
#include "EXIT_Register.h"
#include "EXIT_Interface.h"
#include "EXIT_Config.h"
#include "GIE_Register.h"
#include "GIE_Interface.h"
#include"ADC_Interface.h"
#include"ADC_Config.h"
#include"Smart_Room_Config.h"
//ISR for Analog to digital conversion interrupt if the temperature of the room increases more than a certain number
void warning_temp(void)
{  set_bit(ADCSRA , ADIE); //Enable the ADC interrupt
	u16 ADC_Reading;//Variable to save the reading of LM35
					u16 tempp;//variable to calculate the temperature value
					u8 warning [7]={'W','A','R','N','I','N','G'};
						ADC_Reading=ADC_U16ReadChannel(ADC3);//Read the analog value from channel 3
						ADC_Reading=(ADC_Reading*5000UL)/1024;
						tempp=ADC_Reading/10;//To calculate the temperature value
						LCD_VidSetPosition(0,3);
						if(tempp>34)//The certain value
						{
							for(u8 i=0;i<7;i++)
								LCD_VidWriteCharctr(warning[i]);//preview warning on LCD
							DIO_VidSetPinValue(BUZZ_PORT,BUZZ_PIN , HIGH);//Activate the buzzer for sound warning of danger
									DIO_VidTogglePin(LED_PORT , LED_PIN );//Toogle red led
									_delay_ms(500);
									LCD_VidSendCommand(LCD_Clear);
									DIO_VidSetPinValue(MOTOR_PORT , MOTOR_CW , HIGH);
									DIO_VidSetPinValue(MOTOR_PORT , MOTOR_ACW , HIGH);
									//stop motor instantly
						}
						else
							{clr_bit(ADCSRA,ADIE);//to exit the ISR in case the temperature didn't rise and there's no danger
							DIO_VidSetPinValue(BUZZ_PORT,BUZZ_PIN , LOW);
							DIO_VidSetPinValue(LED_PORT,LED_PIN , LOW);//Stop the buzzer and turn off the led;
							}
}


int main (void)
{
	ADCINT_VidInit();//Initialization ADC
    GIE_VidEnable();//Enable the global interrupt
    SetCallBack(&warning_temp);//calling the ISR in main
	DIO_VidSetPinDirection(LED_PORT , LED_PIN , OUTPUT);
	DIO_VidSetPinDirection(MOTOR_PORT , MOTOR_CW , OUTPUT);
	DIO_VidSetPinDirection(MOTOR_PORT , MOTOR_ACW , OUTPUT);
	DIO_VidSetPinDirection(BUZZ_PORT , BUZZ_PIN , OUTPUT);//setting pins direction
LCD_VidInit();//LCD Initialization

KPD_Init();//KPD Initialization
const u8  name [4]={'A','B','C','D'};//The standard username
const u8  pass[4]={1,2,3,4};//The standard password
u8 username[4]={0,0,0,0};
u8 password[4]= {0,0,0,0};
u8 counter1=0;//counter to check if password and username are correct
		u8 i=0;//counter to login times
		while(i<3)//
		{LCD_VidSendCommand( LCD_Clear);
		LCD_VidWriteCharctr('P');
		LCD_VidWriteCharctr('l');
		LCD_VidWriteCharctr('e');
		LCD_VidWriteCharctr('a');
		LCD_VidWriteCharctr('s');
		LCD_VidWriteCharctr('e');
		LCD_VidWriteCharctr(' ');
		LCD_VidWriteCharctr('E');
		LCD_VidWriteCharctr('n');
		LCD_VidWriteCharctr('t');
		LCD_VidWriteCharctr('e');
		LCD_VidWriteCharctr('r');
		LCD_VidWriteCharctr(' ');
		LCD_VidSetPosition(1,0);
		LCD_VidWriteCharctr('U');
		LCD_VidWriteCharctr('s');
		LCD_VidWriteCharctr('e');
		LCD_VidWriteCharctr('r');
		LCD_VidWriteCharctr('n');
		LCD_VidWriteCharctr('a');
		LCD_VidWriteCharctr('m');
		LCD_VidWriteCharctr('e');
		 _delay_ms(500);
		LCD_VidSendCommand( LCD_Clear);
		for(u8 i=0;i<4;i++)
		 {
			username[i]=KPD_u8GetPressedKey(1,1);
				LCD_VidWriteCharctr(username[i]);

		 }//The user enter username by KPD
		for(u8 i=0;i<4;i++)
		{if ( (username[i] == name[i]))
			counter1++;}

				if(counter1!=4)
				{counter1=0;
				i++;
					continue;}
				else if(counter1==4)
					counter1=0;//check if the username right character by character if it's true it will preceeds to password otherwise it will count one more count and return to enter username again
		_delay_ms(500);
		LCD_VidSendCommand( LCD_Clear);
		LCD_VidWriteCharctr('P');
				LCD_VidWriteCharctr('l');
				LCD_VidWriteCharctr('e');
				LCD_VidWriteCharctr('a');
				LCD_VidWriteCharctr('s');
				LCD_VidWriteCharctr('e');
				LCD_VidWriteCharctr(' ');
				LCD_VidWriteCharctr('E');
				LCD_VidWriteCharctr('n');
				LCD_VidWriteCharctr('t');
				LCD_VidWriteCharctr('e');
				LCD_VidWriteCharctr('r');
				LCD_VidWriteCharctr(' ');
				LCD_VidSetPosition(1,0);
				LCD_VidWriteCharctr('P');
				LCD_VidWriteCharctr('A');
				LCD_VidWriteCharctr('S');
				LCD_VidWriteCharctr('S');
				LCD_VidWriteCharctr('W');
				LCD_VidWriteCharctr('O');
				LCD_VidWriteCharctr('R');
				LCD_VidWriteCharctr('D');
				 _delay_ms(500);
				LCD_VidSendCommand( LCD_Clear);

				for(u8 i=0;i<4;i++)
						 {
					     password[i]=KPD_u8GetPressedKey(0,1);
					     				LCD_VidWriteCharctr('*');
						 }//The user enter password by KPD
				_delay_ms(500);
				LCD_VidSendCommand( LCD_Clear);

		for(u8 i=0;i<4;i++)
		{
			if ( (pass[i] == password[i]) )
		counter1++;
		}
		if(counter1!=4)
			{
			counter1=0;
			i++;
			continue;
			}//check if the password right character by character if it's true it will preceeds to menu otherwise it will count one more count and return to enter username again
	break;}
	if(i==3)//which means number of login tries are over
	{
		LCD_VidSendCommand(LCD_Clear);
		u8 LF[12]={'L','O','G','I','N',' ','F','A','I','L','E','D'};
		for (u8 i = 0 ; i <12 ; i++)
		{
		LCD_VidWriteCharctr(LF[i]);
		}//display login failed on LCD
		while(1)
		{
		DIO_VidSetPinValue(BUZZ_PORT,BUZZ_PIN , HIGH);//Activate buzzer
		DIO_VidTogglePin(LED_PORT , LED_PIN );//Toogle red led
		_delay_ms(500);
		LCD_VidSendCommand(LCD_Clear);
		}
	}
	DIO_VidSetPinValue(MOTOR_PORT , MOTOR_CW , HIGH);
				DIO_VidSetPinValue(MOTOR_PORT , MOTOR_ACW , LOW);
//If login granted turn on motor to rotate clock wise


	while (1)
	{ u16 ADC_Reading;
	u16 tempp;
	ADC_Reading=ADCINT_U16ReadChannel(ADC3);
	ADC_Reading=(ADC_Reading*5000UL)/1024;
	tempp=ADC_Reading/10;//Read the temperature of room every iteration to check it didn't exceed the certain value
		u8 temp[6]={'1','.','T','E','M','P' };
				LCD_VidSetPosition(0,0);
				for (u8 i = 0 ; i < 6 ; i++)
				{

					LCD_VidWriteCharctr(temp[i]);

				}
				u8 ldr[5]={'2','.','L','D','R'};
				LCD_VidSetPosition(0,10);

				for (u8 i = 0 ; i < 5 ; i++)
						{

							LCD_VidWriteCharctr(ldr[i]);

						}
				u8 dc[4]={'3','.','D','C'};
				LCD_VidSetPosition(1,0);
				for (u8 i = 0 ; i < 4 ; i++)
						{

							LCD_VidWriteCharctr(dc[i]);

						}
				u8 exit[6]={'4','.','E','X','I','T'};
				LCD_VidSetPosition(1,9);
				for (u8 i = 0 ; i < 6 ; i++)
						{

							LCD_VidWriteCharctr(exit[i]);

						}
				u8 wrong [11]={'W','r','o','n','g',' ','e','n','t','r','y'};
switch(KPD_u8GetPressedKey(0,1))//switch case for the user to choose the function
{
case 1:LCD_VidSendCommand( LCD_Clear);//finction 1 to show the temperature of room using LM35

      u8 temperature[12]={'T','E','M','P','E','R','A','T','U','R','E',':'};

      		while(1)
      		{u16 ADC_Reading;
      			ADC_Reading=ADCINT_U16ReadChannel(ADC3);
      								ADC_Reading=(ADC_Reading * 5000UL)/1024;
      								tempp=ADC_Reading/10;
      								LCD_VidSetPosition(0,0);
      								      	for ( u8 i = 0 ; i < 12 ; i++)
      								      	{
      								      		LCD_VidWriteCharctr(temperature[i]);
      								      	}
      	 LCD_VidSetPosition(0 , 12 );
 		 LCD_VidWriteNumber(tempp);//preview the temperature at the instant
 		 _delay_ms(100);
      		if(KPD_u8GetPressedKey(0,0)==16)//16 is the back  key in keypad
      		break;}
      	LCD_VidSendCommand( LCD_Clear);
break;
case 2://Preview the room is dark or light by LDR
	{u16 ADC_Reading1 = 0;//For the reading of light intensity
while(1)
	{
	LCD_VidSendCommand( LCD_Clear);
	u16 ADC_Reading1 = 0;
       DIO_VidSetPinDirection(PORTD,PIN5,OUTPUT);
       ADC_Reading1=ADCINT_U16ReadChannel(ADC4);//reading with enable interrupt as if the temperature exceeds the critical value

		if( ADC_Reading1>10)//in case the room is dark
			{
			DIO_VidSetPinValue(PORTD,PIN5,HIGH);//Turn on led
			u8 dark[4]={'D','A','R','K'};//write dark on LCD
			for(u8 i=0;i<4;i++)
			{
				LCD_VidWriteCharctr(dark[i]);
			}
			if(KPD_u8GetPressedKey(0,0)==16)//back button
            break ;
			}
		else//The room is inlighten
		{
			DIO_VidSetPinValue(PORTD,PIN5,LOW);//Turn off the led
			u8 light[5]={'L','I','G','H','T'};//write Light on LCD
			for(u8 i=0;i<5;i++)
						{
							LCD_VidWriteCharctr(light[i]);
						}
			if(KPD_u8GetPressedKey(0,0)==16)//back button
			            break ;
	}
		_delay_ms(500);
}

	LCD_VidSendCommand( LCD_Clear);
	break ;}
case 3:LCD_VidSendCommand( LCD_Clear);//motor control
       u8 x=1;
       while(x)
       {
    	   ADC_Reading=ADCINT_U16ReadChannel(ADC3);
    	   	ADC_Reading=(ADC_Reading*5000UL)/1024;
    	   	tempp=ADC_Reading/10;//to make sure if temperature reaches critical cas interrupt hppaens
       u8 CW[4]={ '1' , '.' , 'C' , 'W' };
       u8 ACW[5]={'2','.', 'A' , 'C' , 'W'};
       u8 stop[6]={ '3' , '.' , 'S' , 'T' , 'O' , 'P'};
       LCD_VidSetPosition(0,0);
       for ( u8 i = 0 ; i < 4 ; i++)
       {
    	   LCD_VidWriteCharctr(CW[i]);
       }
       LCD_VidSetPosition(0,11);
       for ( u8 i = 0 ; i < 5 ; i++)
             {
          	   LCD_VidWriteCharctr(ACW[i]);
             }
       LCD_VidSetPosition(1,0);
       for ( u8 i = 0 ; i < 6 ; i++)
             {
          	   LCD_VidWriteCharctr(stop[i]);
             }
       switch(KPD_u8GetPressedKey(0,1))//another switch case to choose how the motor work
       {
       case 1:DIO_VidSetPinValue(MOTOR_PORT , MOTOR_CW , HIGH);//In this case the motor will rotate clockwise
		DIO_VidSetPinValue(MOTOR_PORT , MOTOR_ACW , LOW);
		break ;
       case 2: DIO_VidSetPinValue(MOTOR_PORT , MOTOR_CW , LOW);//The motor will rotate anticlockwise
		DIO_VidSetPinValue(MOTOR_PORT , MOTOR_ACW , HIGH);
		break ;
       case 3:DIO_VidSetPinValue(MOTOR_PORT , MOTOR_CW , HIGH);//The motor will stop
		DIO_VidSetPinValue(MOTOR_PORT , MOTOR_ACW , HIGH);
		break ;
       case 16 : x=0 ;//back button in case to return to menu
       break ;
       default://wrong entry case
    	   LCD_VidSendCommand( LCD_Clear);
    	         LCD_VidSetPosition(0,3);
    	   	for (u8 i = 0 ; i < 11 ; i++)
    	   		{LCD_VidWriteCharctr(wrong[i]);
    	   		}
    	   	_delay_ms(2000);
    	   	LCD_VidSendCommand( LCD_Clear );
    	   continue;


       }
       }
       LCD_VidSendCommand( LCD_Clear);
       break;
case 4:LCD_VidSendCommand( LCD_Clear);//If the user choose this case it will terminate the program and shut down everu thing
DIO_VidSetPortValue(PORTA , LOW);
DIO_VidSetPortValue(PORTB , LOW);
DIO_VidSetPortValue(PORTC , LOW);
DIO_VidSetPortValue(PORTD , LOW);
LCD_VidSendCommand(LCD_Clear);
return 0;
break;
default:LCD_VidSendCommand( LCD_Clear);//wrong entry if user pressed wrong key
      LCD_VidSetPosition(0,3);
	for (u8 i = 0 ; i < 11 ; i++)
		{LCD_VidWriteCharctr(wrong[i]);
		}
	_delay_ms(2000);
	LCD_VidSendCommand( LCD_Clear );
continue;

}
	}
}


