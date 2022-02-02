/*
* Project Name: ERM19264_UC1609
* File: custom_graphics.h
* Description: ERM19264 LCD driven by UC1609C controller header file for the custom graphics functions based on Adafruit graphics library
* Author: Gavin Lyons.
* URL: 
*/

#ifndef _CUSTOM_GRAPHICS_H
#define _CUSTOM_GRAPHICS_H

#define ERM19264_ASCII_OFFSET 0x00
#define ERM19264_ASCII_OFFSET_SP 0x20 // Starts at Space
#define ERM19264_ASCII_OFFSET_NUM 0x30 // Starts at number 0

#define swap(a, b) { int16_t t = a; a = b; b = t; }
void drawPixel(int16_t x, int16_t y, uint16_t color);

void  drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void  drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void  drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void  drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void  fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void  fillScreen(uint16_t color);

void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
uint16_t color);
void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
int16_t delta, uint16_t color);
void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
int16_t x2, int16_t y2, uint16_t color);
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
int16_t x2, int16_t y2, uint16_t color);
void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
int16_t radius, uint16_t color);
void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
int16_t radius, uint16_t color);
void drawChar(int16_t x, int16_t y, unsigned char c, uint8_t color,
uint8_t bg, uint8_t size);

void setCursor(int16_t x, int16_t y);
void setTextColor(uint16_t , uint16_t );
void setTextSize(uint8_t s);
void setTextWrap(bool w);
void custom_graphics_init(int16_t w, int16_t h);
void drawText(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size);

void setFontNum(uint8_t FontNumber);
void drawCharNumFont(uint8_t x, uint8_t y, uint8_t c, uint8_t color , uint8_t bg);
void drawTextNumFont(uint8_t x, uint8_t y, char *pText, uint8_t color, uint8_t bg);

void drawBitmapBuffer(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color, uint8_t bgcolor, const unsigned char bitmap[]);

int16_t height(void);
int16_t width(void);


const int16_t
  WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
int16_t
  _width, _height, // Display w/h as modified by current rotation
  cursor_x, cursor_y;
uint16_t
  textcolor, textbgcolor;
uint8_t textsize;

bool wrap; // If set, 'wrap' text at right edge of display

uint8_t _FontNumber = 1;
uint8_t _CurrentFontWidth = 5;
uint8_t _CurrentFontoffset = 0;
uint8_t _CurrentFontheight = 8;

#endif 
