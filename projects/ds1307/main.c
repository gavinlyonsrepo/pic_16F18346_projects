/*
* File: main.c
* Description: ds1307 RTC project 
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created july 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "lcd.h" // custom
#include "ds1307.h" // custom 

/* Main application */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(2000);
    lcd_init();
    lcd_clear(1);
    lcd_clear(2);
    initClock();  
    writeClock();
    
    while (1)
    {
        LED_RA5_Toggle();
        readClock();
        __delay_ms(5000); 
    }
}

/* End of File */