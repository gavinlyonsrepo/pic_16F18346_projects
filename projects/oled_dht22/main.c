
#include "mcc_generated_files/mcc.h"
#include "OLED.h"
#include "dht22.h" 

uint16_t testcount = 1;

#define TESTDELAY 7000
#define INITDELAY 5000

void Setup(void);
void DisplayData(void);
void DisplayTitle(void);

/*  Main application  */
void main(void)
{
   Setup(); 
   DisplayTitle();
   while (1)
   {
            DisplayData();
            testcount++;
            LED_RC2_Toggle();
            __delay_ms(TESTDELAY);
            Oled_Clear(); 
   }
}

// Function to setup PIC
void Setup(void)
{
    SYSTEM_Initialize();
    LED_RC2_SetHigh(); 
}

//Function to Display Data to OLED
void DisplayData(void)
{  
       // adjusted %UR/Temp data
		int16_t te=0;
        int16_t hr=0;
		bool t_negative=false;
		uint8_t dht22_status=0;
        char temp[9];
        char hum[9];
        
        dht22_status = DHT22_read();
        
        // Title
        Oled_SelectPage(0);
        Oled_WriteString("DHT22 Sensor Data:");
        
        switch(dht22_status)
            {
            case CHECKSUM:
                Oled_SelectPage(1);
                Oled_WriteString("Error: 1202");
                Oled_SelectPage(3);
                Oled_WriteString("Bad Checksum");
                break;
                            
            case TIMEOUT:               
                Oled_SelectPage(1);
                Oled_WriteString("Error: 1201");
                Oled_SelectPage(3);
                Oled_WriteString("Response Timeout");
                break;
						
			case OK:
                hr=(DHT22_data[0]<<8) | DHT22_data[1]; // entire Humidity value
                te=(DHT22_data[2]<<8) | DHT22_data[3]; // entire Temperature value
				
				// check if temperature is below 0 celsius
				if (te & 0x8000) // bit 16 is 1 ?
					{
					t_negative=true;
					te &= 0x7FFF; // reset bit 16
					}
                Oled_SelectPage(2);
                Oled_WriteString("R. Humidity:");
                Oled_SelectPage(3);
                sprintf(hum, "%u.%u %%", hr/10, (hr-((hr/10)*10)));
                Oled_WriteString(hum);
                Oled_SelectPage(4); //page 1 Select pa/line 0-7 
                Oled_WriteString("Temperature:");
				Oled_SelectPage(5);
                if (t_negative)
					{
					Oled_WriteCharacter('-');
					}
                sprintf(temp, "%u.%u C", te/10, (te-((te/10)*10)));
				Oled_WriteString(temp);
                break;
            default:
                Oled_SelectPage(1);
                Oled_WriteString("Error: 1200");
                Oled_SelectPage(3);
                Oled_WriteString("unKnown");
                break;
            }
            
            // Test count display
            Oled_SelectPage(6);
            Oled_WriteString("Testcount:");
            Oled_SelectPage(7);
            sprintf(temp, "%u", testcount);
		    Oled_WriteString(temp);
}

//Function to Display Data to OLED tt start up. 
void DisplayTitle(void)
{  
    Oled_Init();
    Oled_Clear(); 
    Oled_SelectPage(0);
    Oled_WriteString("PIC 16F18346");
    Oled_SelectPage(1);
    Oled_WriteString("DHT22 on pin RC3"); 
     __delay_ms(INITDELAY);
    Oled_ClearLine(0);
    Oled_ClearLine(1);
}

/* End of File */