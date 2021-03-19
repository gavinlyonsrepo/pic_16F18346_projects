/*
* Project Name: DHt22 on OLED 128X64 SSD1306 . Graphics library
* File: main.c 
* Author: Gavin Lyons.
* Version: 1.0
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Created Sep 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/


// ************ libraries **************
#include "mcc_generated_files/mcc.h"
#include "SSD1306OLED.h"
#include "TextFonts.h"
#include "dht22.h" 

uint16_t testcount = 1;

// *********** Defines **************
#define TESTDELAY 7000
#define INITDELAY 5000

// ************ Function Headers ****************
void Setup(void);
void DisplayData(void);

// ************  Main application ***************
void main(void)
{
   Setup(); 
   while (1)
   {
       DisplayData();
       testcount++;
       if (testcount > 60000) testcount = 1;
       __delay_ms(TESTDELAY);
       SSD1306_FillBuffer(0x00);
   }
}
// ********* End OF main ****************

// *********** Function Space ************
// Function to setup PIC
void Setup(void)
{
    SYSTEM_Initialize();
    LED_RC2_SetHigh(); 
    SSD1306_Init();
    SSD1306_BITMAP(myimage);
    SSD1306_UpdateDisplay();
    __delay_ms(INITDELAY); // Display splash screen
    SSD1306_FillBuffer(0x00);
    SSD1306_UpdateDisplay(); // Clear screen
    uint8_t dht22_status_dummy=0;
    dht22_status_dummy = DHT22_read(); //dummy run as first read is always: Error 1201
    LED_RC2_SetLow(); 
    __delay_ms(500);
}

//Function to Display Data to OLED
void DisplayData(void)
{  
       // adjusted %UR/Temp data
		int16_t te=0;
        int16_t hr=0;
		bool t_negative =false;
        bool error_flag = false;
		uint8_t dht22_status=0;
        char temp[9];
        char hum[9];
        
        dht22_status = DHT22_read();
        
        // Title
        SSD1306_SetFont(UNO);
        SSD1306_Write_Text(0, 0 ,"DHT22 Sensor Data:");
        
        switch(dht22_status)
            {
            case CHECKSUM:
                SSD1306_Write_Text(0, 15, "Error: 1202");
                SSD1306_Write_Text(0, 30, "Bad Checksum");
                error_flag = true;
                break;
                            
            case TIMEOUT:               
                SSD1306_Write_Text(0 , 15, "Error: 1201");
                SSD1306_Write_Text(0,  30, "Response Timeout");
                error_flag = true;
                break;
						
			case OK:
                error_flag = false;
                hr=(DHT22_data[0]<<8) | DHT22_data[1]; // entire Humidity value
                te=(DHT22_data[2]<<8) | DHT22_data[3]; // entire Temperature value
				
				// check if temperature is below 0 celsius
				if (te & 0x8000) // bit 16 is 1 ?
					{
					t_negative=true;
					te &= 0x7FFF; // reset bit 16
					}
                SSD1306_SetFont(UNO);
                SSD1306_Write_Text(0, 8, "R. Humidity:");
                sprintf(hum, "%u.%u %%", hr/10, (hr-((hr/10)*10)));
                SSD1306_SetFont(MEGA);
                SSD1306_Write_Text(17, 17, hum);
                SSD1306_SetFont(UNO);
                SSD1306_Write_Text(0, 34, "Temperature:");
                SSD1306_SetFont(MEGA);
                if (t_negative)
					{
					SSD1306_Write(0, 42, '-');
					}
                sprintf(temp, "%u.%u C", te/10, (te-((te/10)*10)));
				
                SSD1306_Write_Text(17 , 42, temp);
                break;
            default:
                SSD1306_Write_Text(0, 15 , "Error: 1200");
                SSD1306_Write_Text(0, 30 , "unKnown");
                error_flag = true;
                break;
            }
            
            // Error flag 
           if (error_flag == true)
           {
                LED_RC2_SetHigh();
                SSD1306_Triangle( 10, 60, 25, 40, 40, 60, WHITE);
           }else
           {
                LED_RC2_SetLow();
           }
            // Test count display
            SSD1306_SetFont(PICO);
            SSD1306_Write_Text(50, 58, "TC");
            sprintf(temp, "%u", testcount);
		    SSD1306_Write_Text(60, 58, temp);
            
            SSD1306_UpdateDisplay();
}

// *******************  End of File *****************