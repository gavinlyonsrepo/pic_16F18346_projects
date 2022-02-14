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

/* -------- libraries -------- */
#include "mcc_generated_files/mcc.h"
#include <ctype.h> // for is digit function
#include "HD44780_I2C_lcd.h" // custom
#include "ds1307.h" // custom 
#include "Keypad.h" // custom

/*---------------- Globals---------*/
char mykey = 'n';


/* ----------- Defines -----------*/
#define INIT_DELAY 1000
#define MSG_SHOW_DELAY 2000
#//define HARDCODE_TIME  //Comment in to hard-code program datetime at power up

/* -------- Function prototypes -------- */
void ErrorMessage(void); //TODO
void GetTimeDate(void);
void Setup(void);

/* --------- Main Loop ---------- */
void main(void) {

    Setup();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (1) {
        mykey = GetKey(); // Scan for key
        // __delay_ms(500);
        if (mykey == 'D') // Was D pressed? 
        {
            GetTimeDate(); // setdatetime
        }
    }
}

// TODO, not working 

void ErrorMessage(void) {
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(1, 0);
    PCF8574_LCDSendString("Error Read Clock");
}

//System Setup

void Setup(void) {
    SYSTEM_Initialize();
    LED_RA5_SetHigh();
    __delay_ms(INIT_DELAY);
    PCF8574_LCDInit(CURSOR_ON);
    PCF8574_LCDClearScreen();
    LED_RA5_SetLow();
    //initClock();  
#ifdef HARDCODE_TIME 
    writeClockStart();
#endif
}

//Function to set the time date based on keypad entry

void GetTimeDate(void) {
    TMR0_StopTimer(); //stop timer
    uint8_t i = 0;
    char z = 0;
    char settime[12];

    LED_RA5_SetHigh();
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(1, 0);
    PCF8574_LCDSendString("YYMMDDWHHMM");
    PCF8574_LCDGOTO(2, 0);
    while (i < 11) {
        mykey = GetKey();

        if (isdigit(mykey)) {
            settime[z] = mykey;
            z++;
            i++;
            PCF8574_LCDSendData(mykey);
        }
    }
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(1, 0);
    PCF8574_LCDSendString("Date time set");
    writeClock(settime);
    __delay_ms(MSG_SHOW_DELAY);
    TMR0_StartTimer();
    LED_RA5_SetLow();
}

/* End of File */