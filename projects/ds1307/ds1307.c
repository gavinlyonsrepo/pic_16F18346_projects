/*
* File: ds1307.c
* Description: source file for ds1307 RTC library
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Development board: Microchip Curiosity Board
* Created July 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "ds1307.h"  
#include "lcd.h"
#include "Keypad.h"
#include "mcc_generated_files/mcc.h"

void writeClockStart()
{
        rtc_data.secH = 0;
        rtc_data.secH = 0;
        rtc_data.minL = 6;
        rtc_data.minH = 5;
        rtc_data.hourL = 8;
        rtc_data.hourH = 1;
        rtc_data.day = 5;
        rtc_data.dateL = 9;
        rtc_data.dateH = 0;
        rtc_data.monthL = 7;
        rtc_data.monthH = 0;
        rtc_data.yearL = 0;
        rtc_data.yearH = 2;
     
    memcpy(rtc_buff,&rtc_data,sizeof(rtc_data));
    uint8_t data_I2C[8];
    data_I2C[0] = 0x00;
    data_I2C[1] = rtc_buff[0];
    data_I2C[2] = rtc_buff[1];
    data_I2C[3] = rtc_buff[2];
    data_I2C[4] = rtc_buff[3];
    data_I2C[5] = rtc_buff[4];
    data_I2C[6] = rtc_buff[5];
    data_I2C[7] = rtc_buff[6];
    i2c_writeNBytes (RTC_ADDR, data_I2C, 8);
}

void writeClock(char *str)
{
        rtc_data.secH = 0;
        rtc_data.secH = 0;
        rtc_data.minL = str[10];
        rtc_data.minH = str[9];
        rtc_data.hourL = str[8];
        rtc_data.hourH = str[7];
        rtc_data.day = str[6];
        rtc_data.dateL = str[5];
        rtc_data.dateH = str[4];
        rtc_data.monthL = str[3];
        rtc_data.monthH = str[2];
        rtc_data.yearL = str[1];
        rtc_data.yearH = str[0];
     
    memcpy(rtc_buff,&rtc_data,sizeof(rtc_data));
    uint8_t data_I2C[8];
    data_I2C[0] = 0x00;
    data_I2C[1] = rtc_buff[0];
    data_I2C[2] = rtc_buff[1];
    data_I2C[3] = rtc_buff[2];
    data_I2C[4] = rtc_buff[3];
    data_I2C[5] = rtc_buff[4];
    data_I2C[6] = rtc_buff[5];
    data_I2C[7] = rtc_buff[6];
    i2c_writeNBytes (RTC_ADDR, data_I2C, 8);
}

void readClock(void)
{
        i2c_writeNBytes (RTC_ADDR, Ds1307SecondRegAddress, 1); // 0x00
        i2c_readNBytes (RTC_ADDR, rtc_buff, 7); 
        char nameday[4];
        memcpy(&rtc_data,rtc_buff,sizeof(rtc_data));
        
        lcd_send_cmd (LCD_LINE1);
        switch (rtc_data.day )
         {
            case 1: strcpy(nameday, "Sun"); break;
            case 2: strcpy(nameday, "Mon"); break;
            case 3: strcpy(nameday, "Tue"); break;
            case 4: strcpy(nameday, "Wed"); break;
            case 5: strcpy(nameday, "Thu"); break;
            case 6: strcpy(nameday, "Fri"); break;
            case 7: strcpy(nameday, "Sat"); break;
        }
        sprintf(print_buffer,"20%d%d/%d%d/%d%d %s",
                rtc_data.yearH,
                rtc_data.yearL,
                rtc_data.monthH,
                rtc_data.monthL,
                rtc_data.dateH,
                rtc_data.dateL,
                nameday
                );
        lcd_send_string(print_buffer);

        lcd_send_cmd (LCD_LINE2);
        sprintf(print_buffer,"%d%d:%d%d:%d%d",
                rtc_data.hourH,
                rtc_data.hourL,
                rtc_data.minH,
                rtc_data.minL,
                rtc_data.secH,
                rtc_data.secL
                );
        lcd_send_string(print_buffer);
}

void initClock(void)
{
    uint8_t data_I2C[2];
    data_I2C[0] = Ds1307ControlRegAddress ; //0x07
    data_I2C[1] = Ds1307SecondRegAddress; //0x00
    i2c_writeNBytes (RTC_ADDR, data_I2C, 2); 
}