/*
* Project Name: ERM19264_UC1609_T
* File: ERM19264_UC1609_T.cpp
* Description: ERM19264 LCD driven by UC1609C controller source file text only version
* Author: Gavin Lyons.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_proj
*/

#include "ERM19264_UC1609_T.h"
#include "mcc_generated_files/mcc.h"


// Desc: begin Method initialise LCD 
// Sets pinmodes and SPI setup
// Param1: VBiasPOT default = 0x49 , range 0x00 to 0xFE
void LCDbegin (uint8_t VbiasPOT) 
{ 
  _VbiasPOT  = VbiasPOT;
  LCDinit();
}

// Desc: Called from LCDbegin carries out Power on sequence and register init
void LCDinit()
 {
  __delay_ms(UC1609_INIT_DELAY2); //3mS delay, datasheet
  CD_RA1_SetHigh(); 
  CS_RA0_SetHigh();
  LCDReset();

  CS_RA0_SetLow();

  send_command(UC1609_TEMP_COMP_REG, UC1609_TEMP_COMP_SET); 
  send_command(UC1609_ADDRESS_CONTROL, UC1609_ADDRESS_SET); 
  send_command(UC1609_FRAMERATE_REG, UC1609_FRAMERATE_SET);
  send_command(UC1609_BIAS_RATIO, UC1609_BIAS_RATIO_SET);  
  send_command(UC1609_POWER_CONTROL,  UC1609_PC_SET); 
  __delay_ms(UC1609_INIT_DELAY);
  
  send_command(UC1609_GN_PM, 0);
  send_command(UC1609_GN_PM, _VbiasPOT); //  changed by user
  
  send_command(UC1609_DISPLAY_ON, 0x01); // turn on display
  send_command(UC1609_LCD_CONTROL, UC1609_ROTATION_NORMAL); // rotate to normal 
  
  CS_RA0_SetHigh();
}


// Desc: Sends a command to the display
// Param1: the command
// Param2: the values to change
void send_command (uint8_t command, uint8_t value) 
{
  CD_RA1_SetLow();
  send_data(command | value);
  CD_RA1_SetHigh();
}

// Desc: Resets LCD in a five wire setup called at start 
// and  should also be called in a controlled power down setting
void LCDReset () 
{
  RST_RA5_SetLow();
  __delay_ms(UC1609_RESET_DELAY); // Datasheet says  3uS
  RST_RA5_SetHigh();
  __delay_ms(UC1609_RESET_DELAY2); // DataSheet says 5mS
}

// Desc: turns in display
// Param1: bits 1  on , 0 off
void LCDEnable (uint8_t bits) 
{
 CS_RA0_SetLow();
  send_command(UC1609_DISPLAY_ON, bits);
 CS_RA0_SetHigh();
}


// Desc: Scroll the displayed image up by SL rows. 
//The valid SL value is between 0 (for no
//scrolling) and (64). 
//Setting SL outside of this range causes undefined effect on the displayed
//image.
// Param1: bits 0-64 line number y-axis
void LCDscroll (uint8_t bits) 
{
 CS_RA0_SetLow();
  send_command(UC1609_SCROLL, bits);
 CS_RA0_SetHigh();
}

// Desc: Rotates the display 
// Set LC[2:1] for COM (row) mirror (MY), SEG (column) mirror (MX).
// Param1: 4 possible values 000 010 100 110 (defined)
// If Mx is changed the buffer must BE updated
void LCDrotate(uint8_t rotatevalue) 
{
 CS_RA0_SetLow();
  switch (rotatevalue)
  {
      case 0: rotatevalue = 0; break;
      case 0x02: rotatevalue = UC1609_ROTATION_FLIP_ONE; break;
      case 0x04: rotatevalue = UC1609_ROTATION_NORMAL; break;
      case 0x06: rotatevalue = UC1609_ROTATION_FLIP_TWO; break;
      default:  rotatevalue = UC1609_ROTATION_NORMAL; break;
  }
  send_command(UC1609_LCD_CONTROL, rotatevalue);
 CS_RA0_SetHigh();
}

// Desc: invert the display
// Param1: bits, 1 invert , 0 normal
void invertDisplay (uint8_t bits) 
{
 CS_RA0_SetLow();
  send_command(UC1609_INVERSE_DISPLAY, bits);
 CS_RA0_SetHigh();
}

// Desc: turns on all Pixels
// Param1: bits Set DC[1] to force all SEG drivers to output ON signals
// 1 all on ,  0 all off
void LCD_allpixelsOn(uint8_t bits) 
{
 CS_RA0_SetLow();
  send_command(UC1609_ALL_PIXEL_ON, bits);
 CS_RA0_SetHigh();
}

// Desc: Fill the screen NOT the buffer with a datapattern 
// Param1: datapattern can be set to zero to clear screen (not buffer) range 0x00 to 0ff
// Param2: optional delay in microseconds can be set to zero normally.
void LCDFillScreen(uint8_t dataPattern) 
{
 CS_RA0_SetLow();
  uint16_t numofbytes = LCD_WIDTH * (LCD_HEIGHT /8); // width * height
  for (uint16_t i = 0; i < numofbytes; i++) 
  {
    send_data(dataPattern);
  }
CS_RA0_SetHigh();
}

// Desc: Fill the chosen page(1-8)  with a datapattern 
// Param1: datapattern can be set to 0 to FF (not buffer)
void LCDFillPage(uint8_t dataPattern) 
{
 CS_RA0_SetLow();
  uint16_t numofbytes = ((LCD_WIDTH * (LCD_HEIGHT /8))/8); // (width * height/8)/8 = 192 bytes
  for (uint16_t i = 0; i < numofbytes; i++) 
  {
      send_data(dataPattern);
  }
 CS_RA0_SetHigh();
}

//Desc: Draw a bitmap in PROGMEM to the screen
//Param1: x offset 0-192
//Param2: y offset 0-64
//Param3: width 0-192
//Param4 height 0-64
//Param5 the bitmap
void LCDBitmap(int16_t x, int16_t y, uint8_t w, uint8_t h, const uint8_t* data) 
{
 CS_RA0_SetLow();

  uint8_t tx, ty; 
  uint16_t offset = 0; 
  uint8_t column = (x < 0) ? 0 : x;
  uint8_t page = (y < 0) ? 0 : y >>3;

  for (ty = 0; ty < h; ty = ty + 8) 
  {
        if (y + ty < 0 || y + ty >= LCD_HEIGHT) {continue;}
        send_command(UC1609_SET_COLADD_LSB, (column & 0x0F)); 
        send_command(UC1609_SET_COLADD_MSB, (column & 0xF0) >> 4);
        send_command(UC1609_SET_PAGEADD, page++); 

        for (tx = 0; tx < w; tx++) 
        {
              if (x + tx < 0 || x + tx >= LCD_WIDTH) {continue;}
              offset = (w * (ty >> 3)) + tx; 
              send_data(data[offset]);
        }
  }
CS_RA0_SetHigh();
}


// Desc: used in software SPI mode to shift out data
// Param1: bit order LSB or MSB set to MSBFIRST for UC1609C
// Param2: the byte to go
// Other if using high freq MCU the delay define can be increased. 
void CustomshiftOut(uint8_t value)
{
    uint8_t i;
    for (i = 0; i < 8; i++)  
    {
            // LSBFIRST // digitalWrite(_LCD_DIN, !!(value & (1 << i));  
            //digitalWrite(_LCD_DIN, !!(value & (1 << (7 - i)))); //MSBFIRST
            do { LATAbits.LATA2 = !!(value & (1 << (7 - i))); } while(0);     
            SCLK_RA4_SetHigh();
            __delay_us(UC1609_HIGHFREQ_DELAY);
            SCLK_RA4_SetLow();
            __delay_us(UC1609_HIGHFREQ_DELAY);
    }
}

//Desc: Send data byte with SPI to UC1609C
//Param1: the data byte
void send_data(uint8_t databyte)
{
    CustomshiftOut(databyte); //Software SPI
} 

// Desc: goes to XY position
// Param1 : coloumn 0-192
// Param2  : page 0-7
void LCDGotoXY(uint8_t column , uint8_t page)
{
        CS_RA0_SetLow();
        send_command(UC1609_SET_COLADD_LSB, (column & 0x0F)); 
        send_command(UC1609_SET_COLADD_MSB, (column & 0xF0) >> 4);
        send_command(UC1609_SET_PAGEADD, page++); 
        CS_RA0_SetHigh();
}

// Desc: draws passed character.
// Param1: character 'A' or number in  the ASCII table 1-127(default)
void LCDChar(char character)
{
   CS_RA0_SetLow();
   UC1609_FONTPADDING;;
   uint8_t databyte=0; 
   for (uint8_t  column = 0 ; column <  UC1609_FONTWIDTH ; column++)
    {
        databyte =  custom_font[((character-UC1609_ASCII_OFFSET)*UC1609_FONTWIDTH) + column]; 
        //send_data(( + (((character-UC1609_ASCII_OFFSET)*UC1609_FONTWIDTH)) + column));
        send_data(databyte);
   }
    UC1609_FONTPADDING;
    CS_RA0_SetHigh();
}

// Desc: draws passed  character array
// Param1: pointer to start of character array
void LCDString(const char *characters)
{
    while (*characters)
    LCDChar(*characters++);
}

// EOF
