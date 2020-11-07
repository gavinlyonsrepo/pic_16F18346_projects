/*
* File: main.c
* Description: ERM19264 LCD driven by UC1609C controller PICproject , test file
* SW SPI , text only 
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346 
* IDE:  MPLAB X v5.30
* Created November 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#include "mcc_generated_files/mcc.h"
#include "ERM19264_UC1609_T.h"

#define VbiasPOT 0xB2 //Constrast 00 to FE , 0x49 is default. user adjust

// Main loop             
void main(void)
{
    SYSTEM_Initialize();
    LCDbegin(VbiasPOT); // initialize the LCD
    LCDFillScreen(0x00); // clear screen
    
    while (1)
    {
    // Test 0 clear screen 
    // Test 1 String function and goto function 
    // Test 2 clear page function
    // Test 3 character function
    // Test 4 print entire font with character function   
    // Test 0 clear screen
    LCDGotoXY(0, 0);
    LCDString("text mode 216 chars"); // Write a character string
    __delay_ms(5000);
    LCDFillScreen(0x00); // Clear the screen
    __delay_ms(50);
    
        // Test 1 String function and goto function  
    LCDGotoXY(0, 0); // (Col , page ) Col 0 to 191 , page 0 to 7
    LCDString("This is text only version"); // Write a character string
    LCDGotoXY(0, 4);
    LCDString("123456789012345678901234567");
    LCDGotoXY(0, 7);
    LCDString("This is page 7");
    __delay_ms(5000);

    // Test 2 clear page function 
    LCDGotoXY(0, 7);
    LCDFillPage(0x00); // Clear page
    LCDGotoXY(0, 6);
    LCDFillPage(0x7E); // Write pattern (0111 1110) to a page
    __delay_ms(5000);
    LCDFillScreen(0x00); // Clear the screen

    // Test 3 character function 
    LCDGotoXY(100, 2);
    LCDChar('H');  // write single  character
    LCDChar('2');
    __delay_ms(5000);
    LCDFillScreen(0x00); // Clear the screen

    // Test 4 print entire font with character function
    // For characters after 'z{|}' in ASCII table user can comment in UC_FONT_MOD_TWO in font file (NOTE: this will increase program size)
    // For characters before space in ASCII table user can comment in UC_FONT_MOD_One in font file (NOTE: this will increase program size)
    LCDGotoXY(0, 0);
    uint8_t row = 1;
    unsigned char i = 1;
    for(i=UC1609_ASCII_OFFSET; i < 126 ; i++)
    {
      if (i % 27 == 0) LCDGotoXY(0, row++);
      LCDChar(i); 
      __delay_ms(50);
    }
    __delay_ms(10000);
    LCDFillScreen(0x00); // Clear the screen
    }
}
// End of File