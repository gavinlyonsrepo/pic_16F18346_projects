/*
* Project Name: ST7735, 128 by 128, 1.44", red pcb,  SPI TFT module, library.  
* File: ST7735.h
* Description: library header file   
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Created Sep 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#ifndef ST7735_TFT_H
#define ST7735_TFT_H

#include <string.h>
#include "mcc_generated_files/mcc.h"

// SPI TFT module connections

// *** If Hardware SPI module is used, comment this line in *******
#define TFT_SPI_HARDWARE        
// *****************************************************************

// SOFTWARE SPI Connections
// CS = RA0
// DC = RA1
// SDATA = RA2
// SCLK = RA4
// RST = RA5

// HARDWARE SPI Connections, MSSP1
// CS = RA0
// DC = RA1
// SDATA = RB5 SD01 
// SCLK = RB6 SCK1 
// RST = RA5

// *********** DEFINES ****************

#define _swap(a, b) { int16_t t; t = a; a = b; b = t;}
#define _width         128
#define _height        128
#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09
#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13
#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E
#define ST7735_PTLAR   0x30
#define ST7735_VSCRDEF 0x33
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36
#define ST7735_VSCRSADD 0x37
#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6
#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5
#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD
#define ST7735_PWCTR6  0xFC
#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Color definitions
#define   ST7735_BLACK   0x0000
#define   ST7735_BLUE    0x001F
#define   ST7735_RED     0xF800
#define   ST7735_GREEN   0x07E0
#define   ST7735_CYAN    0x07FF
#define   ST7735_MAGENTA 0xF81F
#define   ST7735_YELLOW  0xFFE0
#define   ST7735_WHITE   0xFFFF

#define LCD_ASCII_OFFSET 0x20 //0x20, ASCII character for Space, The font table starts with this character

bool wrap = true;
uint8_t colstart = 0, rowstart = 0, _tft_type;
enum ST7735_iconMods { NONE=0,TRANSPARENT,REPLACE,BOTH};//0,1,2,3

// ******** FUNCTION  PROTOTYPES ************ 

// SPI 
void spiwrite(uint8_t);
void write_command(uint8_t );
void write_data(uint8_t );

// Init
void TFT_GreenTab_Initialize(void);
void TFT_RedTab_Initialize(void);
void TFT_BlackTab_Initialize(void);
void TFT_ST7735B_Initialize(void);
void TFT_ResetPIN(void);
void Bcmd();
void Rcmd1();
void Rcmd2green();
void Rcmd2red();
void Rcmd3();

// Misc + Screen related
void setAddrWindow(uint8_t , uint8_t , uint8_t , uint8_t );
void fillScreen(uint16_t color); 
void invertDisplay(bool i); 
void NormalDisplay(void);
void pushColor(uint16_t color);

//Scroll 
void setScrollDefinition(uint8_t top_fix_height, uint8_t bottom_fix_height, bool _scroll_direction);
void VerticalScroll(uint8_t _vsp); 

// Shapes
void drawPixel(uint8_t , uint8_t , uint16_t );
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint16_t color);
void drawFastHLine(uint8_t x, uint8_t y, uint8_t w, uint16_t color);

void drawRectWH(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void fillRectangle(uint8_t , uint8_t , uint8_t , uint8_t , uint16_t );
void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color); 

void drawRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color); 
void fillRoundRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r, uint16_t color);

void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color); 
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color); 
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color); 
void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color); 

void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color); 
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color); 

// Text
void drawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t color, uint16_t bg,  uint8_t size);
void setTextWrap(bool w);
void drawtext(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size);


#endif