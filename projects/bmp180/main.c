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
#include "lcd.h" // Custom
#include "BMP180.h" // Custom
#include  <stdlib.h> // for printf

/* ----------- Defines -----------*/
#define INIT_DELAY 1000
#define DISPLAY_DELAY 5000
#define LINE_1 1
#define LINE_2 2

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
     lcd_clear(LINE_1);
     lcd_clear(LINE_2);
     char temp[16];
     float temperature;
     temperature = readTemperature();
     sprintf(temp, "Temp: %.2f C",temperature);
     lcd_send_cmd (LCD_LINE2);           
     lcd_send_string(temp);
}

void pressure_display(void)
{
    lcd_clear(LINE_1);
    lcd_clear(LINE_2);
    char press[16];
    int32_t pressure;

    pressure = readPressure();
    sprintf(press, "Press: %ld Pa", pressure);
    lcd_send_cmd (LCD_LINE1);
    lcd_send_string(press);
    lcd_send_cmd (LCD_LINE2);
    pressure = (pressure  / 100); // convert to millibar
    if (pressure <= 983) {
         lcd_send_string( "STORMY");
        }
        else if (pressure >983 && pressure <998){
         lcd_send_string( "RAINY");
        }
         else if (pressure >=998 && pressure <1012){
         lcd_send_string( "CHANGE");
        }
         else if (pressure >=1012 && pressure <1025){
         lcd_send_string( "FAIR");
        }
         else if (pressure >=1025){
         lcd_send_string( "DRY");
        }
 
}

void Setup(void)
{
    uint8_t BMPstatus = 0;
    SYSTEM_Initialize();
    __delay_ms(INIT_DELAY);
    lcd_init();
    lcd_clear(LINE_1);
    lcd_clear(LINE_2);
    LED_STATUS_SetHigh();
    BMPstatus = BMP180begin(BMP180_ULTRAHIGHRES);
    if (BMPstatus == 2)
    {
        // Failure to init sensor 
        lcd_send_cmd (LCD_LINE1);
        lcd_send_string("Error INIT 2");
        __delay_ms(DISPLAY_DELAY);
        while(1);
    }
}
/*------------  End of File ----------- */