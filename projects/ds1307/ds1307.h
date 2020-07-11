/*
* File: ds1307.h 
* Description: header file for ds1307 RTC
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Development board: Microchip Curiosity Board
* Created July 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifndef DS1307_H
#define DS1307_H

/* ************* Data ********************/

#define RTC_ADDR    0x68 //I2C/TWI device address, coded into the device

#define Ds1307SecondRegAddress   0x00   // Address to access Ds1307 SEC register
#define Ds1307DateRegAddress    0x04   // Address to access Ds1307 DATE register
#define Ds1307ControlRegAddress  0x07   // Address to access Ds1307 CONTROL register

typedef struct{
    
    uint8_t secL:4;
    uint8_t secH:3;
    uint8_t hold_clock:1;
    
    uint8_t minL:4;
    uint8_t minH:3;
    uint8_t rfu1:1;
    
    uint8_t hourL:4;
    uint8_t hourH:2;
    uint8_t hour_mode:1;
    uint8_t rfu2:1;
    
    uint8_t day:3;
    uint8_t rfu3:5;
    
    uint8_t dateL:4;
    uint8_t dateH:2;
    uint8_t rfu4:2;
    
    uint8_t monthL:4;
    uint8_t monthH:1;
    uint8_t rfu5:3;
    
    uint8_t yearL:4;
    uint8_t yearH:4;

}rtc_time_read;

uint8_t rtc_buff[7] = {0};
rtc_time_read rtc_data;
char print_buffer[256] = {0};

/************* Function prototypes *******************/
void initClock(void);
void readClock(void);
void writeClockStart(void);
void writeClock(char *str);

#endif