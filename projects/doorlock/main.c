/*
 * File: main.c
 * Description: Door lock project 
 * Author: Gavin Lyons.
 * Complier: xc8 v2.10 compiler
 * PIC: PIC16F18346
 * IDE:  MPLAB X 6.00
 * Created: July 2020
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
 */


// Section : Includes 
#include "mcc_generated_files/mcc.h"
#include <ctype.h> // for "is digit" macro
#include <string.h> 

// User Custom
#include "HD44780_I2C_lcd.h" 
#include "Keypad_green_4x4.h"

// Section : Globals
char guessWord[7];
char passWord[7];
bool doorIsLocked = true;

/* Section  defines */
#define MAX_DUTY_CYCLE 30 // Servo 10 % Start locked position 
#define MIN_DUTY_CYCLE 15 // Servo 5 % unlocked position
#define LCD_INIT_DELAY 100 
#define LCD_DISPLAY_DELAY 2000
#define EEAddr    0x0000      // EEPROM starting address

// Section : Function prototypes 
void Setup(void);
void LCDRedraw(void);
void DoorLock(void);
void DoorUnlock(void);
void WrongGuess(void);
void RightGuess(void);
void ChangePassword(void);


// Section : Main
void main(void) {
    SYSTEM_Initialize();
    Setup();
    // Set to 1 for hardcode password at runtime for testing
#if 0
    strncpy(passWord, "123456", 7);
#endif
    
    // Get password from EEPROM
    uint8_t i = 0;
    for (i = 0; i < 6; i++) {
        passWord[i] = DATAEE_ReadByte(i + 0xF000);
    }

    char myKey = 'n';
    while (1) {
        myKey = KeypadGetKey();
        if (isdigit(myKey)) { // if numerical Add  to string 
            PCF8574_LCDSendData(myKey);
            strncat(guessWord, &myKey, 1); 
        }
        if (myKey == 'D') // D pressed , check password
        {
            if (strcmp(guessWord, passWord) == 0) {
                RightGuess(); // unlock door
            } else {
                WrongGuess(); // lock door
            }
        }
        if (myKey == 'B') // B pressed ,change password
        {
            ChangePassword();
        }
    }
} // END OF Main

// Section:  function Space

// Function to setup PIC

void Setup(void) {
    LED_RA5_SetHigh();

    __delay_ms(LCD_INIT_DELAY);
    PCF8574_LCDInit(LCDCursorTypeOn, 2, 16, 0x27);
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Password Entry");
    __delay_ms(LCD_DISPLAY_DELAY);

    DoorLock();
    LCDRedraw();
    LED_RA5_SetLow();
}

//Function to draw or redraw code entry prompt

void LCDRedraw(void) {
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Code 6 digits:");
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
}

//Function to lock the door 

void DoorLock(void) {
    PWM5_LoadDutyValue(MIN_DUTY_CYCLE); //lock safe
    guessWord[0] = '\0';
    doorIsLocked = true;
}

//Function to handle wrong user guess at password

void WrongGuess(void) {
    PCF8574_LCDSendString(" Wrong");
    __delay_ms(LCD_DISPLAY_DELAY);
    LCDRedraw();
    guessWord[0] = '\0';
}

//Function to handle correct user guess at password

void RightGuess(void) {
    char myKey = 'n';
    PCF8574_LCDSendString(" Right");

    PWM5_LoadDutyValue(MAX_DUTY_CYCLE); //unlock
    doorIsLocked = false;
    LED_RA5_SetHigh();
    __delay_ms(LCD_DISPLAY_DELAY);

    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Press C to lock");
    __delay_ms(LCD_DISPLAY_DELAY);

    while (doorIsLocked == false) {
        myKey = KeypadGetKey();

        if (myKey == 'C') {
            DoorLock();
        }
    }

    LCDRedraw();
    LED_RA5_SetLow();
}

// Function to change password keyword

void ChangePassword(void) {
    LED_RA5_SetHigh();
    char myKeyPress = 'n';
    char changeCode[5] = "3344";
    char guessCode[5];
    uint8_t i = 0;

    // 1. Prompt for Password change code
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("Change Code");
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);

    while (i<10) {
        i = 3;
        myKeyPress = KeypadGetKey(); // Scan for key
        if (isdigit(myKeyPress)) {
            PCF8574_LCDSendData(myKeyPress);
            strncat(guessCode, &myKeyPress, 1); // Add char to string 
        }
        if (myKeyPress == 'D') // Was D pressed? 
        {
            if (strcmp(guessCode, changeCode) == 0) {
                i =11;
            } else {
                LED_RA5_SetLow();
                LCDRedraw();
                return;
            }
        }

    }
    // 2. Read in new password
    myKeyPress = 'n';
    PCF8574_LCDClearScreen();
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("New Password");
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    i = 0;
    while (i < 6) {
        myKeyPress = KeypadGetKey(); // Scan for key
        if (isdigit(myKeyPress)) {
            PCF8574_LCDSendData(myKeyPress);
            DATAEE_WriteByte(i + 0xF000, myKeyPress);
            i++;
        }
    }

    // 3 read new password from memory
    for (i = 0; i < 6; i++) {
        passWord[i] = DATAEE_ReadByte(i + 0xF000);
    }

    LED_RA5_SetLow();
    LCDRedraw();

} //end of function

/* End of File */