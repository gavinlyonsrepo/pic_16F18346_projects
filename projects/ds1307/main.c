/*
 * File: main.c
 * Description: ds1307 RTC project clock alarm
 * Author: Gavin Lyons.
 * Complier: xc8 v2.10 compiler
 * PIC: PIC16F18346
 * IDE:  MPLAB X 6.00
 * Created: July 2020
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
 */

/* -------- libraries -------- */
#include "mcc_generated_files/mcc.h"
#include <ctype.h> // for "is digit" macro

// User Custom
#include "HD44780_I2C_lcd.h" 
#include "RTC_DS1307.h" 
#include "Keypad_green_4x4.h"

/*---------------- Globals---------*/

//alarm
char alarmTime[4] = {0};
bool alarmOn = false;

// Display
bool LCDBackLight = true;
bool DisplayOnOff = true;
uint8_t ClockDisplayCounter=0; //counter incremented by Timer0 overflow.
bool ReadTimeFlag = true;      //flag toggled by Timer0 overflow.

/* ----------- Defines -----------*/
#define INIT_DELAY 1000
#define MSG_SHOW_DELAY 2000

/* -------- Function prototypes -------- */
void Setup(void);
void RTCNotRunErrMsg(void);
void SetTimeDate(void);
void SetAlarm(void);
void BackLight(void);
void DisplayOff(void);
void SetAlarmText(char *);
void ScanKeyPad(void);
void BuzzerTest(void);

/* --------- Main Loop ---------- */
void main(void) {
    Setup();
    char* timeBuf;
    while (1) {

        // ReadTimeFlag controlled by timer0 interrupt
        if (ReadTimeFlag == true) {
            timeBuf = RTCDS1307_readClock();
            SetAlarmText(timeBuf);
            LED_RA5_Toggle();
            ReadTimeFlag = false;
        }
        ScanKeyPad();
    }
} /* ---------END OF Main ---------- */

/* --------- Function Space ---------- */

// Turns Display on and off
void DisplayOff(void)
{
        DisplayOnOff = !DisplayOnOff;
        PCF8574_LCDDisplayON(DisplayOnOff); 
}

// Deals with the key returned by scan of keypad
void ScanKeyPad(void) {
    char KeyPressed = 'n';
    KeyPressed = KeypadGetKey(); // Scan for key

    switch (KeyPressed) {
        case 'A': SetAlarm();  // Set alarm
            break; 
        case 'B': alarmOn = false; //unset alarm
            break;
        case 'C': BuzzerTest(); //test alarm
            break;
        case 'D': SetTimeDate(); //set the date time
            break;
        case 'E': BackLight(); //turn backlight on and off
            break;
        case 'F': PCF8574_LCDResetScreen(LCDCursorTypeOn); // reset LCD
            break;
        case '0':
        {
            BUZZER_RA2_SetLow();  // stop active alarm. also "un-sets" alarm
            alarmOn = false;
        }
            break;
        case '1': DisplayOff();
            break;
        default:
            break;

    }
}

void BuzzerTest(void) {
    BUZZER_RA2_SetHigh();
    __delay_ms(MSG_SHOW_DELAY);
    BUZZER_RA2_SetLow();
}

// Function to display, sound and clear alarm
// passed a pointer to timebuffer HHMM
void SetAlarmText(char* timeBuf) {
    char AlarmPrintBuffer[6] = {0};
    uint8_t count = 0; 
    if (alarmOn == true) {
        PCF8574_LCDGOTO(LCDLineNumberTwo, 10);
        PCF8574_LCDPrintCustomChar(0); // Print bell custom char 
        sprintf(AlarmPrintBuffer, "%c%c:%c%c", alarmTime[0], alarmTime[1], alarmTime[2], alarmTime[3]);
        PCF8574_LCDSendString(AlarmPrintBuffer);
        PCF8574_LCDGOTO(LCDLineNumberTwo, 9);
        for(uint8_t index = 0; index < 4; index++){
            if(timeBuf[index] == alarmTime[index]) count++;
        }
        if (count ==4)  BUZZER_RA2_SetHigh(); //alarm on 
     } else {
        PCF8574_LCDGOTO(LCDLineNumberTwo, 10);
        for (uint8_t blankSpace = 0; blankSpace < 6; blankSpace++) {
            PCF8574_LCDSendChar(' ');
        }
        PCF8574_LCDGOTO(LCDLineNumberTwo, 8);
    }
}

void BackLight(void) {
    LCDBackLight = !LCDBackLight;
    PCF8574_LCDBackLightSet(LCDBackLight);
}

// Function for user to set alarm time
void SetAlarm(void) {
    uint8_t userDataInputLength = 0; // 4 long
    char userDataPosIndex = 0;
    char keyPressed = 'n';
    LED_RA5_SetHigh();
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("HHMM - Set Alarm");
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    while (userDataInputLength < 4) {
        keyPressed = KeypadGetKey();
        
        if (isdigit(keyPressed)) {
            alarmTime[userDataPosIndex] = keyPressed;
            userDataPosIndex++;
            userDataInputLength++;
            PCF8574_LCDSendData(keyPressed);
        }
    }
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Alarm Set! ");
    PCF8574_LCDPrintCustomChar(0); // Print bell custom char 
    alarmOn = true;
    __delay_ms(MSG_SHOW_DELAY);
    LED_RA5_SetLow();
}


void RTCNotRunErrMsg(void) {
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("RTC not Present");
    __delay_ms(5000);
}

// System Setup, called once at start
void Setup(void) {

    SYSTEM_Initialize();
    BUZZER_RA2_SetLow();
    LED_RA5_SetHigh();
    __delay_ms(INIT_DELAY);
    PCF8574_LCDInit(LCDCursorTypeOn, 2, 16, 0x27);
    PCF8574_LCDClearScreen();
    
    if (RTCDS1307_IsPresentClock()) {
        RTCNotRunErrMsg();
        while (1);
    }

    //Set to hard-code program datetime at power up 20-07-09-Fri-18-56-00
    //For debug  & only testing 
    //#define HARDCODE_TIME
    #ifdef HARDCODE_TIME
            RTCDS1307_writeClockStart(void);
    #endif

    // Data to save custom char to LCD CG_RAM
    // Custom char used for bell + clock icon 
    uint8_t bellChar[8] = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
    uint8_t clockChar[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
    PCF8574_LCDCreateCustomChar(0, bellChar);
    PCF8574_LCDCreateCustomChar(1, clockChar);

    LED_RA5_SetLow();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
}

//Function to set the time date based on keypad entry

void SetTimeDate(void) {
    TMR0_StopTimer(); //stop timer
    uint8_t userDataInputLength = 0; // 11 long
    char userDataPosIndex = 0;
    char setTimeDate[12];
    char keyPressed = 'n';

    LED_RA5_SetHigh();
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("YYMMDDWHHMM ");
    PCF8574_LCDPrintCustomChar(1); // Print clock custom char
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    while (userDataInputLength < 11) {
        keyPressed = KeypadGetKey();

        if (isdigit(keyPressed)) {
            setTimeDate[userDataPosIndex] = keyPressed;
            userDataPosIndex++;
            userDataInputLength++;
            PCF8574_LCDSendData(keyPressed);
        }
    }
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Date time set");
    PCF8574_LCDPrintCustomChar(1); // Print clock custom char
    RTCDS1307_writeClock(setTimeDate);
    __delay_ms(MSG_SHOW_DELAY);
    TMR0_StartTimer();
    LED_RA5_SetLow();

}


// Timer0 interupt code called ever (1 second / 120) Seconds
void TMR0_ISR(void)
{
    // clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
    // ---------- Glyons custom code------------
    //counter incremented by Timer0 overflow. 
        ClockDisplayCounter++;
        if(ClockDisplayCounter==120)
        { 
          // This is executed once a second
          ClockDisplayCounter=0; // reset the  counter
          ReadTimeFlag = true; //toggle the flag
        } 
}
/* End of File */
