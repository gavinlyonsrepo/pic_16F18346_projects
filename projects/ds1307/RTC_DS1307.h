/*
* File: ds1307.h 
* Description: header file for ds1307 RTC
* Author: Gavin Lyons.
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

typedef enum{Sunday, Monday , Tuesday,Wednesday, Thursday,Friday,Saturday}DayOfWeek_e;

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

}rtc_time_read_t;


/************* Function prototypes *******************/
bool RTCDS1307_IsPresentClock(void);
char* RTCDS1307_readClock(void);
void RTCDS1307_writeClockStart(void);
void RTCDS1307_writeClock(char *str);

#endif