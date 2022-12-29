
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

// ***************** USER OPTION *****************
// For testing fonts 2-6: Comment in this define & defines FONT DEFINE SECTION of font file. 
#define TestFontsOn
//***********************************************

#define LCDcontrast 0x49 //Constrast 00 to FF , 0x49 is default.
#define myLCDwidth  192
#define myLCDheight 64

// create a full screen buffer (192 * 64/8) + 1 
uint8_t screenBuffer[myLCDwidth * (myLCDheight / 8)];

// Mobile icon  16x8px Vertical addressed
const  uint8_t  SignalIconVa[16] = {
      0x03, 0x05, 0x09, 0xff, 0x09, 0x05, 0xf3, 0x00, 0xf8, 0x00, 0xfc, 0x00, 0xfe, 0x00, 0xff, 0x00
  };

// Mobile icon  16x8px horizontal addressed 
const uint8_t  SignalIconHa[16] = {
      0xfe, 0x02, 0x92, 0x0a, 0x54, 0x2a, 0x38, 0xaa, 0x12, 0xaa, 0x12, 0xaa, 0x12, 0xaa, 0x12, 0xaa
  };

void Setup(void);
void Test_1_3(void);
void Test_4_11(void);

// ************** MAIN LOOP *********************  

void main(void) {

    Setup();
    while (1) {
       Test_1_3();
#ifdef TestFontsOn  // testing fonts 2-6
        Test_4_11();
#endif
        LCDupdate();
    }
} // *********** End of main ************************

// ************** FUNCTION SPACE ********************

void Setup(void) {
    SYSTEM_Initialize();

    LCDbegin(LCDcontrast); // set contrast
    LCDFillScreen(0x00, 0); // Clear the screen

    // Set up starting text mode, colour size font 
    setTextColor(BACKGROUND, FOREGROUND);
    setTextSize(1);
    setFontNum(UC1609Font_Default);
    //init the graphics          
    custom_graphics_init(myLCDwidth, myLCDheight);

}

void Test_1_3(void) {
    // Declare a buffer struct
    MultiBuffer_t mybuffer;
    // init the buffer struct
    LCDinitBuffer(&mybuffer, (uint8_t*) & screenBuffer, myLCDwidth, myLCDheight, 0, 0);
    // Assign address of struct to be the active buffer pointer 
    ActiveBuffer = &mybuffer;
    
    // Test 1a:  bitmap image written directly to screen ,vertically addressed
    LCDBitmap(50, 10, 16, 8, (uint8_t*) SignalIconVa);
    __delay_ms(3000);
    LCDFillScreen(0x00, 0); // Clear the screen
    // Test 1b:  bitmap image written to the buffer ,horizontally addressed
    drawBitmapBuffer(100, 10, 16, 8, BACKGROUND, FOREGROUND, (uint8_t*) SignalIconHa);
    LCDupdate();
    __delay_ms(3000);


    // Test 2: text
    setFontNum(UC1609Font_Default);
    drawChar(150, 30, '1', BACKGROUND, FOREGROUND, 2);
    drawText(10, 10, "hello world ", FOREGROUND, BACKGROUND, 1);

    LCDupdate();
    __delay_ms(5000);
    LCDclearBuffer(); // Clear the buffer

    // Test 3: graphics
    drawLine(96, 0, 96, 64, FOREGROUND);
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
}

void Test_4_11(void) {
    
    // Declare a buffer struct
    MultiBuffer_t mybuffer;
    // init the buffer struct
    LCDinitBuffer(&mybuffer, (uint8_t*) & screenBuffer, myLCDwidth, myLCDheight, 0, 0);
    // Assign address of struct to be the active buffer pointer 
    ActiveBuffer = &mybuffer;
    
    setFontNum(UC1609Font_Default );
    // TEST 4
    drawText(0, 0, "HelloWorld", FOREGROUND, BACKGROUND, 3);

    // Test 5
    drawText(0, 30, "1234567890", FOREGROUND, BACKGROUND, 2);

    // Test 6
    drawText(0, 50, "HelloWorld", BACKGROUND, FOREGROUND, 1);

    // Test 7
    drawChar(150, 25, 'H', FOREGROUND, BACKGROUND, 4);

    LCDupdate();
    __delay_ms(5000);
    LCDclearBuffer(); // Clear the buffer

    // Test 8 
    uint8_t row = 0;
    uint8_t col = 0;
    for (char i = 0; i < 126; i++) {
        if (i == '\n' || i == '\r') continue;
        drawChar(col, row, i, FOREGROUND, BACKGROUND, 1);
        col += 8;
        if (col > 180) {
            row += 9;
            col = 0;
        }
    }
    LCDupdate();
    __delay_ms(5000);
    LCDclearBuffer(); // Clear the buffer

    // Test 9 :: font 2 3 4
    setFontNum(UC1609Font_Thick); // Thick 
    drawText(0, 0, "THICK 123", FOREGROUND, BACKGROUND, 1);
    setFontNum(UC1609Font_Seven_Seg); //seven segment
    drawText(0, 10, "seven seg 456 ", FOREGROUND, BACKGROUND, 1);
    setFontNum(UC1609Font_Wide); // wide 
    drawText(0, 20, "WIDE 789", FOREGROUND, BACKGROUND, 1);
    setFontNum(UC1609Font_Tiny); // wide 
    drawText(0, 30, "tiny font 287", FOREGROUND, BACKGROUND, 1);
    setFontNum(UC1609Font_Homespun); // wide 
    drawText(0, 40, "HomeSpun 29", FOREGROUND, BACKGROUND, 1);
    LCDupdate();
    __delay_ms(5000);
    __delay_ms(5000);
    LCDclearBuffer(); // Clear the buffer

    // Test 10 :: font 5
    setFontNum(UC1609Font_Bignum);
    drawTextNumFont(0, 32, "12345", BACKGROUND, FOREGROUND);
    drawCharNumFont(0, 0, '5', FOREGROUND, BACKGROUND);
    drawCharNumFont(160, 0, '5', BACKGROUND, FOREGROUND);

    LCDupdate();
    __delay_ms(5000);
    LCDclearBuffer(); // Clear the buffer

    // Test 11 :: font 6
    setFontNum(UC1609Font_Mednum);
    drawTextNumFont(0, 32, "123456", BACKGROUND, FOREGROUND);
    drawCharNumFont(0, 0, '6', FOREGROUND, BACKGROUND);
    drawCharNumFont(160, 0, '6', BACKGROUND, FOREGROUND);
    LCDupdate();

    __delay_ms(5000);
    LCDclearBuffer(); // Clear the buffer
    
}
// ************* EOF **************
