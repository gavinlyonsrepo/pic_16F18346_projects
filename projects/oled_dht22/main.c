/*
* Project Name: OLED_DHT22
* File: DHT22.h
* Description: file to read sensor DHT22
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Created: Feb 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "OLED.h"
#include "DHT22.h"

void Setup(void);
void DisplayData(void);
void DisplayTitle(void);

float temperature;
float humidity;
char temp[10];
char hum[10];

/*  Main application  Loop */
void main(void)
{
   Setup();
   Oled_Init();
   Oled_Clear();
   DHT22_init();
   DisplayTitle(); 
   
   while (1)
   {
            DisplayData();
            LED_RC2_Toggle();
            __delay_ms(7000); // delay reads of sensor 
            Oled_Clear();
   }
}

// Function display the data from DHT22 on OLED
void DisplayData(void)
{
        uint8_t status = DHT22_read(&temperature, &humidity);
        switch (status)
        {
            case 1:
                Oled_SelectPage(0); 
                Oled_WriteString("Humidity");
                
                Oled_SelectPage(1);
                sprintf(hum, "%2.2f %%", humidity);
                Oled_WriteString(hum);
                
                Oled_SelectPage(2); 
                Oled_WriteString("Temperature");
                
                Oled_SelectPage(3); 
                sprintf(temp, "%2.2f C", temperature);
                Oled_WriteString(temp);
            break;
            
            case 2:
                Oled_SelectPage(0); 
                Oled_WriteString("Error: ");
                Oled_SelectPage(2); 
                Oled_WriteString("Checksum");
            break;
            
            case 3:
                Oled_SelectPage(0); 
                Oled_WriteString("Error: ");
                Oled_SelectPage(2); 
                Oled_WriteString("No response");
            break;
            
            default:
                Oled_SelectPage(0); 
                Oled_WriteString("Error: ");
                Oled_SelectPage(2); 
                Oled_WriteString("Unknown");
            break;
                   
        }
}

// Function to setup PIC
void Setup(void)
{
    SYSTEM_Initialize();
    LED_RC2_SetHigh(); 
}

//Function to Display Title to OLED on start up. 
void DisplayTitle(void)
{  
    Oled_SelectPage(0); 
    Oled_WriteString("PIC 16F18346");
    Oled_SelectPage(2); 
    Oled_WriteString("DHT22 on pin RC2"); 
     __delay_ms(5000); // init delay
    Oled_ClearLine(0);
    Oled_ClearLine(2);
}
/* End of File */