
/*
* File: main.c
* Description: ERM19264 LCD driven by UC1609C controller PICproject , test file.
* Showing multi-buffer mode the screen is divided into three equal size buffers 
* and different data displayed in each
* Author: Gavin Lyons.
* Complier: xc8 v2.40 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v6.00
* Created Jan 2022
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "ERM19264_UC1609.h"

#define LCDcontrast 0x49 //Constrast 00 to FF , 0x49 is default.
#define myLCDwidth  192
#define myLCDheight 64


// define a buffer to cover one third screen , We divide the screen into 3 buffers, re-use buffer
uint8_t  screenBuffer[(myLCDwidth * (myLCDheight / 8)) / 3]; // 512 bytes

// Function Prototypes
void Display_Buffer_Left(void);
void Display_Buffer_Middle(void);
void Display_Buffer_Right(void);
void Draw_Shapes(void);
void Setup(void);

// ************* MAIN LOOP ***********
void main(void)
{
    Setup();

    while (1)
    {
        //  Test 1 Write to Buffer one
        Display_Buffer_Left();
        // Test 2 write to Buffer two
        Display_Buffer_Middle();
        // Test 3 write to Buffer three
        Display_Buffer_Right();

        __delay_ms(500);
    }
} // END of main

// ************* FUNCTION SPACE *****************

void Setup(void)
{
    SYSTEM_Initialize();
    LCDbegin(LCDcontrast); // set contrast
    LCDFillScreen(0x00, 0); // Clear the screen
    // Set up starting text mode, colour size font
    setTextColor(BACKGROUND, FOREGROUND);
    setTextSize(1);
    setFontNum(FONT_N_DEFAULT);
    custom_graphics_init( myLCDwidth, myLCDheight);
}

// Function to display LHS side of screen (Screen is divided three parts/buffers)
void Display_Buffer_Left(void) {
    
    // 'small image', 20x20px bitmap bi-colour horizontally addressed
const uint8_t smallImageHa[60] = {
    0xff, 0xff, 0xf0, 0xfe, 0x0f, 0xf0, 0xf0, 0x02, 0xf0, 0xe1, 0xf8, 0x70, 
    0xc7, 0xfe, 0x30, 0xc3, 0xff, 0x10, 0x80, 0x7f, 0x10, 0x80, 0x3f, 0x90, 
    0x80, 0x3d, 0x80, 0x00, 0x30, 0x80, 0x00, 0x18, 0x80, 0x80, 0x1d, 0x80, 
    0x80, 0x0f, 0x10, 0x80, 0x00, 0x10, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 
    0xe0, 0x00, 0x70, 0xf0, 0x00, 0xf0, 0xfc, 0x03, 0xf0, 0xff, 0x9f, 0xf0
};

    // Declare a buffer struct
    MultiBuffer_t left_side;
    // init the buffer struct
    LCDinitBuffer(&left_side, (uint8_t*) & screenBuffer, myLCDwidth / 3, myLCDheight, 0, 0);
    // Assign address of struct to be the active buffer pointer
    ActiveBuffer = &left_side;

    LCDclearBuffer();

    Draw_Shapes();
    drawText(10, 10, "left ", FOREGROUND, BACKGROUND, 1);
    drawBitmapBuffer(25, 22, 20, 20, BACKGROUND, FOREGROUND, (uint8_t*)smallImageHa);
    LCDupdate();
}

// Function to display middle part of screen (Screen is divided three parts/buffers)
void Display_Buffer_Middle(void)
{
    // Declare a buffer struct
    MultiBuffer_t middle_side;
    // init the buffer struct
    LCDinitBuffer(&middle_side, (uint8_t*) & screenBuffer, myLCDwidth / 3, myLCDheight, myLCDwidth / 3, 0);
    // Assign address of struct to be the active buffer pointer
    ActiveBuffer = &middle_side;

    LCDclearBuffer();
    
    Draw_Shapes();
    drawText(10, 10, "middle ", FOREGROUND, BACKGROUND, 1);
    fillRoundRect(20, 25, 30, 15, 10, FOREGROUND);
    LCDupdate();
}


// Function to display RHS of screen (Screen is divided three parts/buffers)
void Display_Buffer_Right(void)
{
    static uint8_t iCount=0;
    char count[5]= { 0 };
    
      // Declare a buffer struct
    MultiBuffer_t right_side;
    // init the buffer struct
    LCDinitBuffer(&right_side, (uint8_t*) & screenBuffer, myLCDwidth / 3, myLCDheight, (myLCDwidth/3)*2, 0);
    // Assign address of struct to be the active buffer pointer
    ActiveBuffer = &right_side;

    LCDclearBuffer();

    Draw_Shapes();
    drawText(10, 10, "right ", FOREGROUND, BACKGROUND, 1);
    sprintf(count, "%u", iCount);
    drawText(10, 25, count, FOREGROUND, BACKGROUND, 1);
    iCount++;
    LCDupdate();
}

void Draw_Shapes(void){
  drawRect(0, 0, 64, 64, FOREGROUND);
  drawFastHLine(0, 21, 63, FOREGROUND);
  drawFastHLine(0, 42, 63, FOREGROUND);
}

//  **********  EOF ************
