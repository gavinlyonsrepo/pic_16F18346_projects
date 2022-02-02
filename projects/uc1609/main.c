
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

// For testing fonts 2-6  Comment in define and defines in font file  in FONT DEFINE SECTION
//#define TestFontsOn

#define mylcdheight 64
#define mylcdwidth  192

uint8_t  screenBuffer[1537];   // create a full screen buffer (192 * 64/8) + 1 

  // 'small image', 20x20px vertically addressed
 const  uint8_t smallImage [] = {
    0xff, 0x3f, 0x0f, 0x07, 0x03, 0x13, 0x33, 0x39, 0x39, 0x79, 0xf9, 0xf9, 0xfb, 0xf3, 0xf7, 0xe3,
    0x87, 0x0f, 0x1f, 0xff, 0xf9, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f,
    0x1d, 0x19, 0x10, 0x19, 0x0f, 0x00, 0xc0, 0xf0, 0x0f, 0x0f, 0x0f, 0x0e, 0x0c, 0x0c, 0x08, 0x08,
    0x08, 0x00, 0x00, 0x08, 0x08, 0x08, 0x0c, 0x0c, 0x0e, 0x0f, 0x0f, 0x0f
  };
 
 // 'small image', 20x20px bitmap bi-colour horizontally addressed
uint8_t smallImageVA[60] = {
0xff, 0xff, 0xf0, 0xfe, 0x0f, 0xf0, 0xf0, 0x02, 0xf0, 0xe1, 0xf8, 0x70, 
0xc7, 0xfe, 0x30, 0xc3, 0xff, 0x10, 0x80, 0x7f, 0x10, 0x80, 0x3f, 0x90, 
0x80, 0x3d, 0x80, 0x00, 0x30, 0x80, 0x00, 0x18, 0x80, 0x80, 0x1d, 0x80, 
0x80, 0x0f, 0x10, 0x80, 0x00, 0x10, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 
0xe0, 0x00, 0x70, 0xf0, 0x00, 0xf0, 0xfc, 0x03, 0xf0, 0xff, 0x9f, 0xf0
};

// MAIN SINGLE BUFFER  
void main(void)
{  
    SYSTEM_Initialize();
    LCDbegin(0x49);
    LCDFillScreen(0x00, 0); // Clear the screen
    setTextColor(BACKGROUND, FOREGROUND);
    setTextSize(1); 
    setFontNum(1);
    buffer = (uint8_t*) &screenBuffer;  // Assign the pointer to the buffer
    custom_graphics_init( mylcdwidth, mylcdheight);   
    
    while (1)
    {
        // Test 1a:  bitmap image written directly to screen (20X20 pixels) vertically addressed
        LCDBitmap(50, 10, 20, 20, (uint8_t*)smallImage);
        __delay_ms(5000);
         LCDFillScreen(0x00, 0); // Clear the screen
         // Test 1b:  bitmap image written to the buffer (20X20 pixels) horizontally addressed
         drawBitmapBuffer(100, 10, 20, 20, BACKGROUND, FOREGROUND, (uint8_t*)smallImageVA);
           LCDupdate();
        __delay_ms(5000);
        
        
        // Test 2: text
        setFontNum(1);
        drawChar(150, 30,'1', BACKGROUND, FOREGROUND, 2);
        drawText(10, 10, "hello world ", FOREGROUND, BACKGROUND, 1);
        
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
        LCDclearBuffer(); // Clear the buffer
             
#ifdef TestFontsOn  // testing fonts 2-6
        setFontNum(1);
        // TEST 1 
        drawText(0,0 ,"HelloWorld", FOREGROUND, BACKGROUND, 3);

        // Test 2
        drawText(0, 30 , "1234567890", FOREGROUND, BACKGROUND, 2) ;

        // Test 3
        drawText(0, 50, "HelloWorld", BACKGROUND, FOREGROUND, 1);

        // Test 4
        drawChar(150, 25 , 'H', FOREGROUND, BACKGROUND, 4);
        
         LCDupdate();
        __delay_ms(5000);
        LCDclearBuffer(); // Clear the buffer
        
        // Test 5 
        uint8_t row = 0;
        uint8_t col = 0;
        for (char i = 0; i < 126; i++)
        {
            if (i == '\n' || i == '\r') continue;
           drawChar(col, row, i, FOREGROUND, BACKGROUND, 1);
            col +=8;
            if (col > 180) {
              row += 9;
              col = 0;
		     }
        }
        LCDupdate();
        __delay_ms(5000);
        LCDclearBuffer(); // Clear the buffer
        
        // Test font 2 3 4
        setFontNum(2); // Thick 
        drawText(0,0 ,"HELLO WORLD 123", FOREGROUND, BACKGROUND, 1);
        setFontNum(3);  //seven segment
        drawText(0,20 ,"HELLO WORLD 456 ", FOREGROUND, BACKGROUND, 1);
        setFontNum(4);  // wide 
        drawText(0,40 ,"HELLO WORLD 789", FOREGROUND, BACKGROUND, 1);
        
        LCDupdate();
        __delay_ms(5000);
        LCDclearBuffer(); // Clear the buffer
        
        // Test font 5
        setFontNum(5);
        drawTextNumFont(0, 32, "12345" , BACKGROUND, FOREGROUND);  
        drawCharNumFont(0, 0, '5', FOREGROUND, BACKGROUND); 
        drawCharNumFont(160, 0, '5', BACKGROUND, FOREGROUND); 
       
        LCDupdate();
        __delay_ms(5000);
        LCDclearBuffer(); // Clear the buffer
        
         // Test font 6
        setFontNum(6);
        drawTextNumFont(0, 32, "123456" , BACKGROUND, FOREGROUND);  
        drawCharNumFont(0, 0, '6', FOREGROUND, BACKGROUND); 
        drawCharNumFont(160, 0, '6', BACKGROUND, FOREGROUND); 
        LCDupdate();
        
        __delay_ms(5000);
        LCDclearBuffer(); // Clear the buffer
        
#endif
        LCDupdate(); 
 
    }
}
// EOF
