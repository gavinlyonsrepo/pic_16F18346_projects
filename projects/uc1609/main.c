
/*
* File: main.c
* Description: ERM19264 LCD driven by UC1609C controller PICproject , test file.
* HW SPI, text , graphic buffer.
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created November 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "ERM19264_UC1609.h"

#define mylcdheight 64
#define mylcdwidth  192

uint8_t  screenBuffer[1537];   // create a full screen buffer (192 * 64/8) + 1 

  // 'small image', 20x20px
 const  uint8_t smallImage [] = {
    0xff, 0x3f, 0x0f, 0x07, 0x03, 0x13, 0x33, 0x39, 0x39, 0x79, 0xf9, 0xf9, 0xfb, 0xf3, 0xf7, 0xe3,
    0x87, 0x0f, 0x1f, 0xff, 0xf9, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f,
    0x1d, 0x19, 0x10, 0x19, 0x0f, 0x00, 0xc0, 0xf0, 0x0f, 0x0f, 0x0f, 0x0e, 0x0c, 0x0c, 0x08, 0x08,
    0x08, 0x00, 0x00, 0x08, 0x08, 0x08, 0x0c, 0x0c, 0x0e, 0x0f, 0x0f, 0x0f
  };
 
// MAIN SINGLE BUFFER  
void main(void)
{  
    SYSTEM_Initialize();
    LCDbegin(0x49);
    LCDFillScreen(0x00, 0); // Clear the screen
    setTextColor(BACKGROUND, FOREGROUND);
    setTextSize(1); 
    buffer = (uint8_t*) &screenBuffer;  // Assign the pointer to the buffer
    custom_graphics_init( mylcdwidth, mylcdheight);   
    
    while (1)
    {
        // Test 1:  bitmap image(20X20 pixels)
        LCDBitmap(50, 10, 20, 20, (uint8_t*)smallImage);
        __delay_ms(5000);
         LCDFillScreen(0x00, 0); // Clear the screen
        
        // Test 2: text
        drawChar(150, 30,'1', BACKGROUND, FOREGROUND, 2);
        drawtext(10, 10, "hello", FOREGROUND, BACKGROUND, 1);
        //setCursor(120,10);
        LCDupdate();
        __delay_ms(5000);
        LCDclearBuffer(); // Clear the buffer
        
        // Test 3: graphics
        drawLine(96,  0, 96, 64, FOREGROUND);
        drawFastVLine(94, 0, 64, FOREGROUND);
        drawFastHLine(0, 32, 192, FOREGROUND);

        //Q1
        fillRect(0, 10, 20, 20, FOREGROUND);
        fillCircle(40, 20, 10, FOREGROUND);
        fillTriangle(60, 30, 70, 10, 80, 30, FOREGROUND);
        //Q2
        drawRect(100, 10, 20, 20, FOREGROUND);
        drawCircle(140, 20, 10, FOREGROUND);
        drawTriangle(160, 30, 170, 10, 180, 30, FOREGROUND);
        //Q3
        fillRoundRect(0, 40, 40, 20, 10, FOREGROUND);
        fillRoundRect(45, 40, 40, 20, 10, FOREGROUND);
        //Q4
        drawRect(100, 40, 80, 20, FOREGROUND);
        
         LCDupdate();
        __delay_ms(5000);
        LCDclearBuffer(); 
        LCDupdate();
    }
}
// EOF
