#ifndef _LCD_Interface_H_
#define _LCD_Interface_H_
//function to initialize LCD
void LCD_VidInit(void);
//Function to send command with input command number
void LCD_VidSendCommand(u8 u8CmdCpy);
//Function to write character
void LCD_VidWriteCharctr(u8 u8DataCpy);
void LCD_VidWriteNumber(u8 n);
void LCD_VidSetPosition(u8 u8row , u8 u8column );
void LCD_DrawChar(void);
#endif
