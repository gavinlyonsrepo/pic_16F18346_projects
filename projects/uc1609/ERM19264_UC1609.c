/*
* Project Name: ERM19264_UC1609
* File: ERM19264_UC1609.c
* Description: ERM19264 LCD driven by UC1609C controller source file
* Author: Gavin Lyons.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include <string.h>  //memset
#include "mcc_generated_files/mcc.h"
#include "ERM19264_UC1609.h"

// Desc Initilist the Multibuffer struct
// Param 1 Pointer to a struct
// Param 2 Point to buffer array data
// Param 3. width of buffer
// Param 4. height of buffer
// Param 5. x offset of buffer
// Param 6. y offset of buffer
void LCDinitBuffer(MultiBuffer_t* my_buffer, uint8_t* bitmap, uint8_t w,  uint8_t h, int16_t  x, int16_t y)
{
    my_buffer->screenbitmap = bitmap; // point it to the buffer
    my_buffer->width = w ;
	my_buffer->height = h;
	my_buffer->xoffset = x;
	my_buffer->yoffset = y; 
}

// Desc: begin Method initialise LCD 
// Sets pinmodes and SPI setup
// Param1: VBiasPOT default = 0x49 , range 0x00 to 0xFE
void  LCDbegin (uint8_t VbiasPOT) 
{
  
  _VbiasPOT  = VbiasPOT;

SPI1_Initialize();
  
  LCDinit();
}

// Desc: Called from LCDbegin carries out Power on sequence and register init
void  LCDinit()
 {
  __delay_ms(UC1609_INIT_DELAY2); //3mS delay, datasheet
  UC1609_CD_SetHigh;
  UC1609_CS_SetHigh;
  LCDReset();

  UC1609_CS_SetLow;

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
  
  UC1609_CS_SetHigh;
}


// Desc: Sends a command to the display
// Param1: the command
// Param2: the values to change
void  send_command (uint8_t command, uint8_t value) 
{
  UC1609_CD_SetLow; 
  send_data(command | value);
  UC1609_CD_SetHigh;
}

// Desc: Resets LCD in a five wire setup called at start 
// and  should also be called in a controlled power down setting
void  LCDReset () 
{
  UC1609_RST_SetLow;
  __delay_ms(UC1609_RESET_DELAY); 
  UC1609_RST_SetHigh;
  __delay_ms(UC1609_RESET_DELAY2);
}

// Desc: turns in display
// Param1: bits 1  on , 0 off
void  LCDEnable (uint8_t bits) 
{
 UC1609_CS_SetLow;
  send_command(UC1609_DISPLAY_ON, bits);
 UC1609_CS_SetHigh;
}


// Desc: Scroll the displayed image up by SL rows. 
//The valid SL value is between 0 (for no
//scrolling) and (64). 
//Setting SL outside of this range causes undefined effect on the displayed
//image.
// Param1: bits 0-64 line number y-axis
void  LCDscroll (uint8_t bits) 
{
 UC1609_CS_SetLow;
  send_command(UC1609_SCROLL, bits);
 UC1609_CS_SetHigh;
}

// Desc: Rotates the display 
// Set LC[2:1] for COM (row) mirror (MY), SEG (column) mirror (MX).
// Param1: 4 possible values 000 010 100 110 (defined)
// If Mx is changed the buffer must BE updated
void  LCDrotate(uint8_t rotatevalue) 
{
 UC1609_CS_SetLow;
  switch (rotatevalue)
  {
      case 0: rotatevalue = 0; break;
      case 0x02: rotatevalue = UC1609_ROTATION_FLIP_ONE; break;
      case 0x04: rotatevalue = UC1609_ROTATION_NORMAL; break;
      case 0x06: rotatevalue = UC1609_ROTATION_FLIP_TWO; break;
      default:  rotatevalue = UC1609_ROTATION_NORMAL; break;
  }
  send_command(UC1609_LCD_CONTROL, rotatevalue);
 UC1609_CS_SetHigh;
}

// Desc: invert the display
// Param1: bits, 1 invert , 0 normal
void  invertDisplay (uint8_t bits) 
{
 UC1609_CS_SetLow;
  send_command(UC1609_INVERSE_DISPLAY, bits);
 UC1609_CS_SetHigh;
}

// Desc: turns on all Pixels
// Param1: bits Set DC[1] to force all SEG drivers to output ON signals
// 1 all on ,  0 all off
void  LCD_allpixelsOn(uint8_t bits) 
{
 UC1609_CS_SetLow;
  send_command(UC1609_ALL_PIXEL_ON, bits);
 UC1609_CS_SetHigh;
}

// Desc: Fill the screen NOT the buffer with a datapattern 
// Param1: datapattern can be set to zero to clear screen (not buffer) range 0x00 to 0ff
// Param2: optional delay in microseconds can be set to zero normally.
void  LCDFillScreen(uint8_t dataPattern, uint8_t delay) 
{
 UC1609_CS_SetLow;
  uint16_t numofbytes = LCD_WIDTH * (LCD_HEIGHT /8); // width * height
  for (uint16_t i = 0; i < numofbytes; i++) 
  {
    send_data(dataPattern);
    __delay_us(1);
  }
UC1609_CS_SetHigh;
}

// Desc: Fill the chosen page(1-8)  with a datapattern 
// Param1: datapattern can be set to 0 to FF (not buffer)
void  LCDFillPage(uint8_t dataPattern) 
{
 UC1609_CS_SetLow;
  uint16_t numofbytes = ((LCD_WIDTH * (LCD_HEIGHT /8))/8); // (width * height/8)/8 = 192 bytes
  for (uint16_t i = 0; i < numofbytes; i++) 
  {
      send_data(dataPattern);
  }
 UC1609_CS_SetHigh;
}

//Desc: Draw a bitmap  to the screen
//Param1: x offset 0-192
//Param2: y offset 0-64
//Param3: width 0-192
//Param4 height 0-64
//Param5 the bitmap  the bitmap vertical addressed.
void  LCDBitmap(int16_t x, int16_t y, uint8_t w, uint8_t h, const uint8_t* data) 
{
 UC1609_CS_SetLow;

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
UC1609_CS_SetHigh;
}


//Desc: Send data byte with SPI to UC1609C
//Param1: the data byte
void send_data(uint8_t spiDataByte)
{
    SPI1_Open(SPI1_DEFAULT);
    SPI1_ExchangeBlock(&spiDataByte, sizeof(spiDataByte));
    SPI1_Close(); 
    //(void)SPI.transfer(byte); // Hardware SPI
} 

//Desc: updates the buffer i.e. writes it to the screen
void  LCDupdate() 
{
LCDBuffer(ActiveBuffer->xoffset, ActiveBuffer->yoffset, ActiveBuffer->width, ActiveBuffer->height, (uint8_t*)ActiveBuffer->screenbitmap);

}

//Desc: clears the buffer i.e. does NOT write to the screen
void  LCDclearBuffer()
{
    memset( ActiveBuffer->screenbitmap, 0x00, (ActiveBuffer->width * (ActiveBuffer->height/ 8))  );
}

//Desc: Draw a bitmap to the screen
//Param1: x offset 0-192
//Param2: y offset 0-64
//Param3: width 0-192
//Param4 height 0-64
//Param5 the bitmap vertical addressed.
void  LCDBuffer(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t* data) 
{
 UC1609_CS_SetLow;

  uint8_t tx, ty; 
  uint16_t offset = 0; 
  uint8_t column = (x < 0) ? 0 : x;
  uint8_t page = (y < 0) ? 0 : y/8;

  for (ty = 0; ty < h; ty = ty + 8) 
  {
    if (y + ty < 0 || y + ty >= LCD_HEIGHT) {continue;}
    
    send_command(UC1609_SET_COLADD_LSB, (column & 0x0F)); 
    send_command(UC1609_SET_COLADD_MSB, (column & 0XF0) >> 4); 
    send_command(UC1609_SET_PAGEADD, page++); 
 
    for (tx = 0; tx < w; tx++) 
    {
          if (x + tx < 0 || x + tx >= LCD_WIDTH) {continue;}
          offset = (w * (ty /8)) + tx; 
          send_data(data[offset++]);
    }
  }
  
UC1609_CS_SetHigh;
}

// Desc: Draws a Pixel to the screen overides the custom graphics library
// Passed x and y co-ords and colour of pixel.
void  drawPixel(int16_t x, int16_t y, uint16_t colour) 
{
    uint8_t temp = 0;
    if ((x < 0) || (x >=ActiveBuffer->width) || (y < 0) || (y >= ActiveBuffer->height)) {
    return;
  }
      uint16_t tc = (ActiveBuffer->width * (y /8)) + x; 
      switch (colour)
      {
        case FOREGROUND: 
            temp =  (1 << (y & 7));   
            ActiveBuffer->screenbitmap[tc] |= temp; 
            break;
        case BACKGROUND:  ActiveBuffer->screenbitmap[tc] &= ~(1 << (y & 7)); break;
        case INVERSE: ActiveBuffer->screenbitmap[tc] ^= (1 << (y & 7)); break;
      }
}

// EOF
