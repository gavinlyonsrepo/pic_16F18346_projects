/*
* Project Name: ST7735, 128 by 128, 1.44", red pcb,  SPI TFT module, library. 
* File: main.c
* Description: test file  
* Author: Gavin Lyons.
* Version: 1.0
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Created Sep 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

// ************ libraries **************
#include "mcc_generated_files/mcc.h"
#include "ST7735_TFT.h"

// *********** Defines **************
#define TEST_DELAY1 1000
#define TEST_DELAY2 2000
#define TEST_DELAY5 5000

// ************ Function Headers ****************
void Setup(void);

void Test1(void); // Hello world fonts + Colors text
void Test1A(void); // print entire font
void Test2(void); // font sizes + character draw
void Test3(void); // pixels and lines
void Test4(void); // rectangles 
void Test5(void); // Circle
void Test6(void); // Triangles 
void Test7(void); // scroll TODO not working in version 1.0
void Test8(void); // shapes media buttons graphic + invert display

// ************  Main application ***************
void main(void)
{  
    Setup();
    fillScreen(ST7735_BLACK);
    LED_RC5_SetLow();
    while (1)
    {
        Test1();
        Test1A();
        Test2();
        Test3();
        Test4(); 
        Test5();
        Test6();
        // Test7(); //TODO Scroll
        Test8();
        fillScreen(ST7735_BLACK);
        LED_RC5_SetHigh();
        drawtext(10, 10, "Test over!", ST7735_WHITE, ST7735_BLACK, 1);
        while(1);
    }    
}
// ********* End OF main ********

// Initialize the device
void Setup(void)
{
    SYSTEM_Initialize();
    LED_RC5_SetHigh();
    __delay_ms(TEST_DELAY2);
    TFT_RedTab_Initialize();
    setTextWrap(true);
    __delay_ms(TEST_DELAY1);
}

void Test1(void)
{
        char *txt = " hello world";    
        drawtext(0, 5, txt, ST7735_WHITE, ST7735_BLACK, 1);
        drawtext(0, 15, txt,  ST7735_BLUE, ST7735_BLACK, 1);
        drawtext(0, 25, txt, ST7735_RED, ST7735_BLACK, 1);
        drawtext(0, 35, txt, ST7735_GREEN, ST7735_BLACK, 1);       
        drawtext(0, 45, txt, ST7735_CYAN, ST7735_BLACK, 1);       
        drawtext(0, 55, txt, ST7735_MAGENTA, ST7735_BLACK, 1);       
        drawtext(0, 65, txt, ST7735_YELLOW, ST7735_BLACK, 1);        
        drawtext(0, 75, txt, ST7735_WHITE, ST7735_BLACK, 1);       
        LED_RC5_Toggle();
         __delay_ms(TEST_DELAY2);
         fillScreen(ST7735_BLACK);
}

void Test1A(void)
{   
        drawtext(0, 5, " !#$%&'()*+,-.", ST7735_WHITE, ST7735_BLACK, 1);
        drawtext(0, 15, "0123456789",  ST7735_BLUE, ST7735_BLACK, 1);
        drawtext(0, 25, "abcdefghijklmn", ST7735_RED, ST7735_BLACK, 1);
        drawtext(0, 35, "ABCDEGHIJKLMN", ST7735_GREEN, ST7735_BLACK, 1);       
        drawtext(0, 45, "opqrstuvwxyz", ST7735_CYAN, ST7735_BLACK, 1);       
        drawtext(0, 55, "OPQRSTUVWYXZ", ST7735_MAGENTA, ST7735_BLACK, 1);       
        drawtext(0, 65, ";:=,.?@", ST7735_YELLOW, ST7735_BLACK, 1);        
        drawtext(0, 75, "[]/", ST7735_BLACK, ST7735_WHITE, 1);       
        LED_RC5_Toggle();
         __delay_ms(TEST_DELAY5);
         fillScreen(ST7735_BLACK);
}

void Test2(void)
{
     char *txttwo = "test2";
     drawtext(0, 5, txttwo, ST7735_WHITE, ST7735_BLACK, 2);
     drawtext(0, 25, txttwo, ST7735_WHITE, ST7735_BLACK, 3);
     drawtext(0, 55, txttwo, ST7735_WHITE, ST7735_BLACK, 4);
     drawChar(0, 80, 'c', ST7735_WHITE, ST7735_BLACK,  5);
     LED_RC5_Toggle();
     __delay_ms(TEST_DELAY2);
     fillScreen(ST7735_BLACK);
}

void Test3(void) //pixels and lines 
{
    drawPixel(5, 5, ST7735_RED);
    drawLine(10, 10, 30, 30, ST7735_RED);
    drawFastVLine(40, 40, 40, ST7735_GREEN);
    drawFastHLine(60, 60, 40, ST7735_YELLOW);
    
    LED_RC5_Toggle();
     __delay_ms(TEST_DELAY2);
     fillScreen(ST7735_BLACK);
}    

void Test4(void)
{
     drawRectWH(5, 5, 20, 20, ST7735_RED);
     fillRectangle(25 , 25 , 40 , 40 ,  ST7735_YELLOW);
     fillRect(80, 5, 20, 20, ST7735_GREEN); 
     drawRoundRect(5, 80, 20, 20, 5, ST7735_CYAN); 
     fillRoundRect(50, 100, 25, 25, 10, ST7735_WHITE);
     LED_RC5_Toggle();
     __delay_ms(TEST_DELAY2);
     fillScreen(ST7735_BLACK);
}

void Test5(void)
{
   drawCircle(40, 40, 20,  ST7735_GREEN); 
   fillCircle(80, 20, 15,  ST7735_YELLOW); 
}

void Test6(void)
{
    drawTriangle(5, 80, 50, 80, 15, 100, ST7735_CYAN); 
    fillTriangle(55, 80, 100, 60, 75, 120, ST7735_RED); 
    LED_RC5_Toggle();
     __delay_ms(TEST_DELAY2);
    fillScreen(ST7735_BLACK);
}

void Test7(void)
{
    char *txtthree = "  scroll  ";
    drawtext(0, 45, txtthree, ST7735_CYAN, ST7735_BLACK, 1); 
    setScrollDefinition(100, 10, 0);
    VerticalScroll(0);
    LED_RC5_Toggle();
    __delay_ms(TEST_DELAY2);
    NormalDisplay(); 
    fillScreen(ST7735_BLACK);
    
}

void Test8() {
  //Draw play button 
  fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);
  fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);
  fillCircle(40, 100, 15,  ST7735_CYAN); 
  fillCircle(80, 100, 15,  ST7735_GREEN); 
  __delay_ms(TEST_DELAY5);
  // change play color
  fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);
  __delay_ms(TEST_DELAY1);
  // change play color
  fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);
  __delay_ms(TEST_DELAY1);
  invertDisplay(true);   //invert display test
   __delay_ms(TEST_DELAY1);
    invertDisplay(false);   //invert display test
    LED_RC5_Toggle();
    __delay_ms(TEST_DELAY2);
    fillScreen(ST7735_BLACK);
}
// *************** End of File ****************