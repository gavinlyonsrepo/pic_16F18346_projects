/*
* File: SevenSegDisplay.h
* Description: src file for Seven Segment ASCII Display  library, PIC
* Author: Gavin Lyons.
 * URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "SevenSegDisplay.h"
#include "SevenSegDisplayFont.h"

void SevenSegDisplay(bool common) 
{
  SER_SetDigitalOutput();
  SCLK_SetDigitalOutput();
  RCLK_SetDigitalOutput();
  _commonCathode = common;
  displayString("    ", 0x08); //clear display
}

void displaySeg(uint8_t value, uint8_t digits) 
{ 
   if (_commonCathode == false) 
   {
     value = (value ^ COMMON_ANODE_MASK); // If common anode flip all bits.
     digits = (digits ^ COMMON_ANODE_MASK);
   }
   RCLK_SetLow();
   DataDisplay(digits); // digit control
   DataDisplay(value); // value
   RCLK_SetHigh(); 
}

void displayASCII(uint8_t ascii, uint8_t digits) {
  displaySeg(SevenSeg[ascii - ASCII_OFFSET], digits);
}

void displayASCIIwDot(uint8_t ascii, uint8_t digits) { 
    // add  0x40 to turn on decimal point/dot in 7 seg
  displaySeg(SevenSeg[ascii - ASCII_OFFSET] + DOT_MASK_DEC, digits);
}

void displayHex(uint8_t hex, uint8_t digits) 
{
    uint8_t hexchar = 0;
    if (hex <= 9)
    {
        displaySeg(SevenSeg[hex + HEX_OFFSET], digits);
        // 16 is offset in reduced ASCII table for 0 
    }else if ((hex >= 10) && (hex <=15))
    {
        // Calculate offset in reduced ASCII table for ABCDEF
        switch(hex) 
        {
         case 10: hexchar = 'A'; break;
         case 11: hexchar = 'B'; break;
         case 12: hexchar = 'C'; break;
         case 13: hexchar = 'D'; break;
         case 14: hexchar = 'E'; break;
         case 15: hexchar = 'F'; break;
        }
        displaySeg(SevenSeg[hexchar - ASCII_OFFSET], digits);
    }
    
}

void displayString(const char* str, uint8_t startPos)
{
   char c;
   while (c = (*str++)) {
        if (*str == '.') {
            displayASCIIwDot(c, startPos);
            str++;
        }  else {
            displayASCII(c, startPos);
        }
          startPos = (startPos>>1);//Bitshifting by one to right /2 to change position of bit set position
   }
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SCLK_SetHigh();
    __delay_us(SHIFT_DELAY);
    SCLK_SetLow();
    __delay_us(SHIFT_DELAY);
}

/* DataDisplay:
 * This function will send the data to serial line 74HC9595
 */
void DataDisplay(unsigned int data){
    for (uint8_t i=0 ; i<8 ; i++){
       // bit shift and bit mask data. MSB
        SER_LAT = (data >>(7-i)) & 0x01;
        sclock(); //enable data storage clock
    }
  
}