/*
* File: main.c
* Description: Bmp180 pressure sensor PICproject 
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
#include "HD44780_I2C_lcd.h" // Custom
#include "BMP180.h" // Custom
#include  <stdlib.h> // for printf

/* ----------- Defines -----------*/
#define INIT_DELAY 1000
#define DISPLAY_DELAY 5000

/* -------- Function prototypes -------- */
void pressure_display(void);
void Temperature_display(void);
void Setup(void);

/* --------------  Main --------------- */
void main(void)
{
    Setup();
    while (1)
    {
        LED_STATUS_Toggle(); 
        pressure_display();
        __delay_ms(DISPLAY_DELAY);
        Temperature_display();
        __delay_ms(DISPLAY_DELAY);
    }
}
/* --------------  End of Main --------------- */


/* --------------  Function Space--------------- */
void Temperature_display(void)
{
     PCF8574_LCDClearScreen();
     char temp[16];
     float temperature;
     temperature = readTemperature();
     sprintf(temp, "Temp: %.2f C",temperature);
     
     PCF8574_LCDGOTO(1, 0);           
     PCF8574_LCDSendString(temp);
}

void pressure_display(void)
{
    PCF8574_LCDClearScreen();
    char press[16];
    char outlook[7];
    int32_t pressure;
    pressure = readPressure();
    sprintf(press, "Press: %ld Pa", pressure);
    PCF8574_LCDGOTO(1, 0); 
    PCF8574_LCDSendString(press);
    PCF8574_LCDGOTO(2, 0); 
    pressure = (pressure  / 100); // convert to millibar
    if (pressure <= 983) {
         PCF8574_LCDSendString( "STORMY");
        }
        else if (pressure >983 && pressure <998){
         PCF8574_LCDSendString( "RAINY");
        }
         else if (pressure >=998 && pressure <1012){
         PCF8574_LCDSendString( "CHANGE");
        }
         else if (pressure >=1012 && pressure <1025){
         PCF8574_LCDSendString( "FAIR");
        }
         else if (pressure >=1025){
         PCF8574_LCDSendString( "DRY");
        }
    PCF8574_LCDSendString(outlook);
}

void Setup(void)
{
    uint8_t BMPstatus = 0;
    SYSTEM_Initialize();
    __delay_ms(INIT_DELAY);
    PCF8574_LCDInit (CURSOR_ON);
    PCF8574_LCDClearScreen();
    LED_STATUS_SetHigh();
    BMPstatus = BMP180begin(BMP180_ULTRAHIGHRES);
    if (BMPstatus == 2)
    {
        // Failure to init sensor 
         PCF8574_LCDGOTO(1, 0); 
        PCF8574_LCDSendString("Error INIT 2");
        __delay_ms(DISPLAY_DELAY);
        while(1);
    }
}
/*------------  End of File ----------- */