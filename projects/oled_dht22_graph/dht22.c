/*
* Project Name: OLED_DHT22
* File: dht22.c
* Description: dht22 sensor library src file
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* CreatedL Feb 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "dht22.h"

// wait for logic level transition (high->LOW or low->HIGH)
void DHT22_expect(uint8_t level)
	{
	// Timer 1 used for timeout
    TMR1IF=0; 	// reset interrupt flag
    TMR1=0; 	// reset counter
    
	// line is HIGH, wait for low
	if(level==LOW) 
		{
		while(DHT22_IN && !TMR1IF); // exit if line is low or Timer1 has overflowed
		}
	// line is LOW, wait for high
	else 
		{
		while(!DHT22_IN && !TMR1IF); // exit if line is high or Timer1 has overflowed
		}
	} // \DHT22_expect


// start sequence, return TIMEOUT if a timeout occured
uint8_t DHT22_start(void)
	{
    DHT22_PIN_DIR=OUTPUT;   // pin as output
    DHT22_OUT(LOW);         // line to low logic level
    __delay_ms(20);         // wait at least 18mS
    DHT22_PIN_DIR=INPUT;    // pin as input
    
    // now line will be pulled up by the pull-up resistor
    // and this condition could be last about 40us
    // so now  wait the line for low logic level
    DHT22_expect(LOW);
    if (TMR1IF) return TIMEOUT;
	
    // now line will be low for about 80uS...
    DHT22_expect(HIGH); // wait for transition low->high
    if (TMR1IF) return TIMEOUT;
    // ...and then high for another 80uS
    DHT22_expect(LOW); // wait for transition high->low
    if (TMR1IF) return TIMEOUT;
	
    // return ok if no timeout occurred
	return OK;
    } // \DHT22_start

// read from the line and put data in the buffer
uint8_t DHT22_read(void)
    {
    uint8_t bitmask = 0x80;
    uint8_t t1value=0;
	uint8_t start=0;
	
    // send start signal
	start=DHT22_start();
	// if start not ok, return same value returned from start function
	if (start != OK)
		{
		return start;
		}
    
    // start is ok, I can read the 5 bytes returned by sensor
    for(uint8_t i=0; i<5; i++)
        {  
        // bitmask is used for place a "1" in the right place in the bytes 
        // of the buffer array
        bitmask=0x80;
        
        // reset current field byte
        DHT22_data[i]=0;
	
        // here i receive the 8 bit of the current field (from MSB to LSB)
        for(uint8_t j=0; j<8; j++)
            {
            // every bit has a low logic level that last about 50uS (I'm not interested in measuring it)
            // then an high level is the bit value depending on its duration
            // if high level is about 26/28 uS, bit is 0
            // if high level is about 70uS, bit is 1
            // I measure the high level duration using Timer1
            DHT22_expect(HIGH);  // wait low->high transition (about 50uS)
            // Timer1 will be resetted by DTH22_expect function, so I'll be able to compute transition time
            DHT22_expect(LOW); // wait high->low transition and measure time
            t1value=TMR1;
            // if high level is greater than 50uS i can assume is a 1 bit
            // then I add a bit to the current byte
            if(t1value>50) 
                {
                DHT22_data[i] = DHT22_data[i] | bitmask;
                }
            // now I can rotate the mask 1 bit to right, ready for the next bit
            bitmask >>= 1;
            }
        }
  
    // checksum must be equal to less significant 8 bit of the sum of 4 bytes received
    uint8_t checksum = DHT22_data[0] + DHT22_data[1] + DHT22_data[2] + DHT22_data[3];
    if(checksum!=DHT22_data[4]) 
        {
        return CHECKSUM; // bad checksum, exit from the funcion with a bad checksum return value
        }
        
    return OK; // checksum ok and no timeout
} // \DHT22_read