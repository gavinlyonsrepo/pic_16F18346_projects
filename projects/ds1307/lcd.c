/*
* File: lcd.c
* Description: HD44780-based character LCD 16x02 I2C library main file
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created March 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "lcd.h"         
#include "mcc_generated_files/mcc.h"

void lcd_send_data (unsigned char data)
{
	unsigned char data_l, data_u;
	uint8_t data_I2C[4];

	data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
	data_u = data&0xf0;  //select upper nibble
    data_I2C[0] =data_u|DATA_BYTE_ON; //enable=1 and rs =1 1101  YYYY-X-en-X-rs
    data_I2C[1] = data_u|DATA_BYTE_OFF; //enable=0 and rs =1 1001 YYYY-X-en-X-rs
    data_I2C[2] = data_l|DATA_BYTE_ON; //enable=1 and rs =1 1101  YYYY-X-en-X-rs
    data_I2C[3] = data_l|DATA_BYTE_OFF; //enable=0 and rs =1 1001 YYYY-X-en-X-rs

    i2c_writeNBytes (SLAVE_ADDRESS_LCD, data_I2C, 4); 
}

// send command to LCD

void lcd_send_cmd (unsigned char data)
{
	unsigned char data_l, data_u;
	uint8_t data_I2C[4];

	data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
	data_u = data&0xf0;  //select upper nibble
    data_I2C[0] = data_u|CMD_BYTE_ON; // 1100 YYYY-X-en-X-rs enable=1 and rs =0
    data_I2C[1] = data_u|CMD_BYTE_OFF; // 1000 YYYY-X-en-X-rs enable=0 and rs =0
    data_I2C[2] = data_l|CMD_BYTE_ON; // 1100 YYYY-X-en-X-rs enable=1 and rs =0
    data_I2C[3] = data_l|CMD_BYTE_OFF; // 1000 YYYY-X-en-X-rs enable=0 and rs =0
	
    i2c_writeNBytes (SLAVE_ADDRESS_LCD, data_I2C, 4);  
}

void lcd_clear(uint8_t lineNo)
{
    if ( lineNo == 1){
        lcd_send_cmd (LCD_LINE1);
    }else if ( lineNo == 2){
         lcd_send_cmd (LCD_LINE2);
    }else{
        return;
    }
    
    for (uint8_t  i=0;i<16;i++)
    {
        lcd_send_data (' ');
    } 
}

// initialise LCD

void lcd_init (void)
{
    lcd_send_cmd (LCD_HOME);
    lcd_send_cmd (MODE_4BIT);
    lcd_send_cmd (DISPLAY_ON);
    //lcd_send_cmd (CURSOR_BLINK); 
    lcd_send_cmd (CLRSCR);
}

// send string to LCD
void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}