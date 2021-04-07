#ifndef _LCD_CONFIG_H_
#define LCD_CONFIG_H_

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

#define LCD_DATA_PORT PORTC
#define LCD_CONTROL_PORT PORTA

#define RS PIN0
#define RW PIN1
#define EN  PIN2


#define LCD_Clear  0x01  //REPLACE ALL characters as space
#define LCD_Home  0x02  //return cursor to first character in first line
#define LCD_EntryMode  0x06 //shift cursor from left to right to read/write
#define LCD_DisplayOff  0x08  //turn display off
#define LCD_DisplayOn  0x0C  //display on/cursor off/don't blink character
#define LCD_FunctionReset  0x30  //reset the LCD
#define LCD_FunctionSet8bit  0x38  //8-bit data,2 line display,5x7 font
#define LCD_SetCursor  0x80  //set cursor position

#endif
