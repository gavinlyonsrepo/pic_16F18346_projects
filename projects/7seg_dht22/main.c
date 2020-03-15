/*
* Project Name:  7seg_Dht22
* File: main.c
* Description: DHt22 sensor data + seven segment library.
* Author: Gavin Lyons.
* Created: Mar 2020
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "stdio.h"
#include "SevenSegDisplay.h" // custom seven segment ASCII library
#include "DHT22.h" //// custom DHT22 sensor  library

float temperature= 0.0;
float humidity = 0.0;
char temp[7]= { 0 };
char hum[7] = { 0 };
const bool COMMON_C = true; //true for common_cathode(default) , false for common anode
uint8_t status = 4;

# define INIT_DELAY 2000 

void Setup(void);
void DisplayData(uint8_t);

/*Main application */
void main(void)
{
    Setup();
    __delay_ms(INIT_DELAY);
    while (1)
    {
        if (CheckSensor == true) //every 9 seconds on Timer0 callback interrupt
        {
            status = DHT22_read(&temperature, &humidity);
        }
       DisplayData(status); 
    }
}
/* ----End of Main loop------*/

/* -------- Function Space ------*/
// setup function
void Setup(void)
{
    SYSTEM_Initialize();
    // Enable the Global and Peripheral  Interrupts
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    SevenSegDisplay(COMMON_C);
    DHT22_init();
}

// Function display the data from DHT22 on OLED passed status
//1 :  data received Good result
//2 :  data received Checksum bad
//3 :  no response from sensor
//4 : unknown error, default error 
void DisplayData(uint8_t status)
{   
    switch (status)
        {
            case 1:
                if (CheckSensor == true)
                {
                    if (temperature > 0)
                        {
                           sprintf(temp, "t%2.1f", temperature);
                        }else{
                           sprintf(temp, "t%2.1f.", temperature); //negative switch on last dot LSB
                        }
                    sprintf(hum, "H%2.1f", humidity);    
                    CheckSensor = false;
                } 
                if (TempOrHum == true)
                    displayString(temp, 0x08);
                else
                    displayString(hum, 0x08);
            break;
            
            case 2:
                displayASCII('C', 0x01); //Checksum error
            break;
            
            case 3:
                displayASCII('N', 0x01); //No response error
            break; 
            
            default:
                displayASCII('U', 0x01); //Unknown error
            break;        
        }
}
/* End of File */