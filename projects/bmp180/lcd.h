/*
* File: lcd.h
* Description: HD44780-based character LCD 16x02 I2C library header file
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include <stdint.h>

#ifndef LCD_H
#define LCD_H

/* ************* Data ********************/

#define SLAVE_ADDRESS_LCD 0x27 //I2C  address for LCD

/************** Command Byte Codes ******/
// See  http://www.dinceraydin.com/lcd/commands.html for HD44780 CMDs


#define LCD_LINE1 0x80
#define LCD_LINE2 0xC0
#define LCD_HOME  0x02
#define CLRSCR 0x01
#define DISPLAY_ON 0x0C
#define DISPLAY_OFF 0x08
#define CURSOR_ON 0x0A
#define CURSOR_OFF 0x08
#define CURSOR_BLINK 0x0F
#define CURSOR_INC 0x06
#define MODE_8BIT 0x38
#define MODE_4BIT 0x28

/**** Codes for I2C byte******/
// Byte = DATA-X-en-X-rs (en=enable rs = reg select)
#define DATA_BYTE_ON 0x0D //enable=1 and rs =1 1101  YYYY-X-en-X-rs
#define DATA_BYTE_OFF 0x09 // enable=0 and rs =1 1001 YYYY-X-en-X-rs
#define CMD_BYTE_ON 0x0C  // enable=1 and rs =0 1100 YYYY-X-en-X-rs 
#define CMD_BYTE_OFF 0x08 // enable=0 and rs =0 1000 YYYY-X-en-X-rs 

/************* Function prototypes *******************/
void lcd_send_cmd (unsigned char data);
void lcd_send_data (unsigned char data);
void lcd_clear (uint8_t lineNo);
void lcd_init (void);
void lcd_send_string (char *str);

#endif