
/*
* Project Name: ERM19264_UC1609
* File: ERM19264_graphics.c
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/


#include "ERM19264_graphics.h"


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


void custom_graphics_init(int16_t w, int16_t h)
{
  _width    = w;
  _height   = h;
  cursor_y  = cursor_x    = 0;
  textsize  = 1;
  textcolor = textbgcolor = 0xFFFF;
  wrap      = true;
}

// Draw a circle outline
void drawCircle(int16_t x0, int16_t y0, int16_t r,
    uint16_t color) {
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  drawPixel(x0  , y0+r, color);
  drawPixel(x0  , y0-r, color);
  drawPixel(x0+r, y0  , color);
  drawPixel(x0-r, y0  , color);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
  
    drawPixel(x0 + x, y0 + y, color);
    drawPixel(x0 - x, y0 + y, color);
    drawPixel(x0 + x, y0 - y, color);
    drawPixel(x0 - x, y0 - y, color);
    drawPixel(x0 + y, y0 + x, color);
    drawPixel(x0 - y, y0 + x, color);
    drawPixel(x0 + y, y0 - x, color);
    drawPixel(x0 - y, y0 - x, color);
  }
}

void drawCircleHelper( int16_t x0, int16_t y0,
               int16_t r, uint8_t cornername, uint16_t color) {
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      drawPixel(x0 + x, y0 + y, color);
      drawPixel(x0 + y, y0 + x, color);
    } 
    if (cornername & 0x2) {
      drawPixel(x0 + x, y0 - y, color);
      drawPixel(x0 + y, y0 - x, color);
    }
    if (cornername & 0x8) {
      drawPixel(x0 - y, y0 + x, color);
      drawPixel(x0 - x, y0 + y, color);
    }
    if (cornername & 0x1) {
      drawPixel(x0 - y, y0 - x, color);
      drawPixel(x0 - x, y0 - y, color);
    }
  }
}

void fillCircle(int16_t x0, int16_t y0, int16_t r,
			      uint16_t color) {
  drawFastVLine(x0, y0-r, 2*r+1, color);
  fillCircleHelper(x0, y0, r, 3, 0, color);
}

// Used to do circles and roundrects
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r,
    uint8_t cornername, int16_t delta, uint16_t color) {

  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;

    if (cornername & 0x1) {
      drawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
      drawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
    }
    if (cornername & 0x2) {
      drawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
      drawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
    }
  }
}

// Bresenham's algorithm -
void drawLine(int16_t x0, int16_t y0,
			    int16_t x1, int16_t y1,
			    uint16_t color) {
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    swap(x0, y0);
    swap(x1, y1);
  }

  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0<=x1; x0++) {
    if (steep) {
      drawPixel(y0, x0, color);
    } else {
      drawPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

// Draw a rectangle
void drawRect(int16_t x, int16_t y,
			    int16_t w, int16_t h,
			    uint16_t color) {
  drawFastHLine(x, y, w, color);
  drawFastHLine(x, y+h-1, w, color);
  drawFastVLine(x, y, h, color);
  drawFastVLine(x+w-1, y, h, color);
}

void drawFastVLine(int16_t x, int16_t y,
				 int16_t h, uint16_t color) {
  drawLine(x, y, x, y+h-1, color);
}

void drawFastHLine(int16_t x, int16_t y,
				 int16_t w, uint16_t color) {
  drawLine(x, y, x+w-1, y, color);
}

void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
			    uint16_t color) {
  for (int16_t i=x; i<x+w; i++) {
    drawFastVLine(i, y, h, color);
  }
}

void fillScreen(uint16_t color) {
  fillRect(0, 0, _width, _height, color);
}

// Draw a rounded rectangle
void drawRoundRect(int16_t x, int16_t y, int16_t w,
  int16_t h, int16_t r, uint16_t color) {
  drawFastHLine(x+r  , y    , w-2*r, color); // Top
  drawFastHLine(x+r  , y+h-1, w-2*r, color); // Bottom
  drawFastVLine(x    , y+r  , h-2*r, color); // Left
  drawFastVLine(x+w-1, y+r  , h-2*r, color); // Right
  // draw four corners
  drawCircleHelper(x+r    , y+r    , r, 1, color);
  drawCircleHelper(x+w-r-1, y+r    , r, 2, color);
  drawCircleHelper(x+w-r-1, y+h-r-1, r, 4, color);
  drawCircleHelper(x+r    , y+h-r-1, r, 8, color);
}

// Fill a rounded rectangle
void fillRoundRect(int16_t x, int16_t y, int16_t w,
				 int16_t h, int16_t r, uint16_t color) {
  fillRect(x+r, y, w-2*r, h, color);

  // draw four corners
  fillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, color);
  fillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, color);
}

// Draw a triangle
void drawTriangle(int16_t x0, int16_t y0,
				int16_t x1, int16_t y1,
				int16_t x2, int16_t y2, uint16_t color) {
  drawLine(x0, y0, x1, y1, color);
  drawLine(x1, y1, x2, y2, color);
  drawLine(x2, y2, x0, y0, color);
}

// Fill a triangle
void fillTriangle ( int16_t x0, int16_t y0,
				  int16_t x1, int16_t y1,
				  int16_t x2, int16_t y2, uint16_t color) {

  int16_t a, b, y, last;

  // Sort coordinates by Y order (y2 >= y1 >= y0)
  if (y0 > y1) {
    swap(y0, y1); swap(x0, x1);
  }
  if (y1 > y2) {
    swap(y2, y1); swap(x2, x1);
  }
  if (y0 > y1) {
    swap(y0, y1); swap(x0, x1);
  }

  if(y0 == y2) { 
    a = b = x0;
    if(x1 < a)      a = x1;
    else if(x1 > b) b = x1;
    if(x2 < a)      a = x2;
    else if(x2 > b) b = x2;
    drawFastHLine(a, y0, b-a+1, color);
    return;
  }

  int16_t
    dx01 = x1 - x0,
    dy01 = y1 - y0,
    dx02 = x2 - x0,
    dy02 = y2 - y0,
    dx12 = x2 - x1,
    dy12 = y2 - y1;
  int32_t
    sa   = 0,
    sb   = 0;


  if(y1 == y2) last = y1;   // Include y1 scanline
  else         last = y1-1; // Skip it

  for(y=y0; y<=last; y++) {
    a   = x0 + sa / dy01;
    b   = x0 + sb / dy02;
    sa += dx01;
    sb += dx02;

    if(a > b) swap(a,b);
    drawFastHLine(a, y, b-a+1, color);
  }

  sa = dx12 * (y - y1);
  sb = dx02 * (y - y0);
  for(; y<=y2; y++) {
    a   = x1 + sa / dy12;
    b   = x0 + sb / dy02;
    sa += dx12;
    sb += dx02;
    if(a > b) swap(a,b);
    drawFastHLine(a, y, b-a+1, color);
  }
}

// Draw a character
void drawChar(int16_t x, int16_t y, unsigned char c,
								uint8_t color, uint8_t bg, uint8_t size) {

	if((x >= _width)            || // Clip right
		 (y >= _height)           || // Clip bottom
		 ((x + (_CurrentFontWidth+1) * size - 1) < 0) || // Clip left
		 ((y + _CurrentFontheight * size - 1) < 0))   // Clip top
		return;
    if (_FontNumber >= UC1609Font_Bignum)
        return;
    
	for (uint8_t i=0; i<(_CurrentFontWidth+1); i++ ) {
		uint8_t line;
		if (i == _CurrentFontWidth)
		{ 
			line = 0x0;
		}
		else 
		{
			 switch (_FontNumber) {
#ifdef UC1609_Font_Default_enabled
				case UC1609Font_Default : line = pFontDefaultptr[((c - _CurrentFontoffset) * _CurrentFontWidth) + i]; break;
#endif 
#ifdef UC1609_Font_Thick_enabled
				case UC1609Font_Thick : line = pFontThickptr[((c - _CurrentFontoffset) * _CurrentFontWidth) + i]; break;
#endif
#ifdef UC1609_Font_SevenSeg_enabled
				case UC1609Font_Seven_Seg : line = pFontSevenSegptr[((c - _CurrentFontoffset) * _CurrentFontWidth) + i]; break;
#endif
#ifdef UC1609_Font_Wide_enabled
				case  UC1609Font_Wide : line = pFontWideptr[((c - _CurrentFontoffset) * _CurrentFontWidth) + i]; break;
#endif
#ifdef UC1609_Font_Tiny_enabled
				case UC1609Font_Tiny: line = pFontTinyptr[((c - _CurrentFontoffset) * _CurrentFontWidth) + i]; break;
#endif
#ifdef UC1609_Font_Homespun_enabled
				case UC1609Font_Homespun: line = pFontHomeSpunptr[((c - _CurrentFontoffset) * _CurrentFontWidth) + i]; break;
#endif               
				default: // wrong font number
						return;
				break;
				}
		}
		for (int8_t j = 0; j<_CurrentFontheight; j++) {
			if (line & 0x1) {
				if (size == 1) // default size
					drawPixel(x+i, y+j, color);
				else {  // big size
					fillRect(x+(i*size), y+(j*size), size, size, color);
				} 
			} else if (bg != color) {
				if (size == 1) // default size
					drawPixel(x+i, y+j, bg);
				else {  // big size
					fillRect(x+i*size, y+j*size, size, size, bg);
				}
			}
			line >>= 1;
		}
	}
}

void setCursor(int16_t x, int16_t y) {
  cursor_x = x;
  cursor_y = y;
}

void setTextSize(uint8_t s) {
  textsize = (s > 0) ? s : 1;
}

void setTextColor(uint16_t c, uint16_t b) {
  textcolor   = c;
  textbgcolor = b; 
}

void setTextWrap(bool w) {
  wrap = w;
}

// Return the size of the display 
int16_t width(void){
  return _width;
}
 
int16_t height(void){
  return _height;
}

// Font 1-6 only
void drawText(uint8_t x, uint8_t y, char *pText, uint16_t color, uint16_t bg, uint8_t size){
	if (_FontNumber >= UC1609Font_Bignum)
        return;
    
	uint8_t cursor_x, cursor_y;
	cursor_x = x, cursor_y = y;
	
	while (*pText != '\0') 
	{
		if (wrap && ((cursor_x + size * _CurrentFontWidth) > _width)) 
		{
			cursor_x = 0;
			cursor_y = cursor_y + size * 7 + 3;
			if (cursor_y > _height) cursor_y = _height;
		}
		drawChar(cursor_x, cursor_y, *pText, color, bg, size);
		cursor_x = cursor_x + size * (_CurrentFontWidth + 1);
		if (cursor_x > _width) cursor_x = _width;
		pText++;
	}
}

// Desc :  Set the font number
// Param1: fontnumber enum LCD_FONT_TYPE_e , 1-8.
// 1=default 2=thick 3=seven segment 4=wide 5=tiny 6=homespun 7=bignums 8=mednums 

void setFontNum(LCDFontName_e FontNumber) 
{
	_FontNumber = FontNumber;
		
	switch (_FontNumber) 
	{
		case UC1609Font_Default:  // Norm default 5 by 8
			_CurrentFontWidth = UC1609FontWidth_5;
			_CurrentFontoffset =  UC1609FontOffset_Extend;
			_CurrentFontheight = UC1609FontHeight_8;
		break; 
		case UC1609Font_Thick: // Thick 7 by 8 (NO LOWERCASE LETTERS)
			_CurrentFontWidth = UC1609FontWidth_7;
			_CurrentFontoffset = UC1609FontOffset_Space;
			_CurrentFontheight = UC1609FontHeight_8;
		break; 
		case UC1609Font_Seven_Seg:  // Seven segment 4 by 8
			_CurrentFontWidth = UC1609FontWidth_4;
			_CurrentFontoffset = UC1609FontOffset_Space;
			_CurrentFontheight = UC1609FontHeight_8;
		break;
		case UC1609Font_Wide : // Wide  8 by 8 (NO LOWERCASE LETTERS)
			_CurrentFontWidth = UC1609FontWidth_8;
			_CurrentFontoffset = UC1609FontOffset_Space;
			_CurrentFontheight = UC1609FontHeight_8;
		break; 
		case UC1609Font_Tiny:  // tiny 3 by 8
			_CurrentFontWidth = UC1609FontWidth_3;
			_CurrentFontoffset =  UC1609FontOffset_Space;
			_CurrentFontheight = UC1609FontHeight_8;
		break;
		case UC1609Font_Homespun: // homespun 7 by 8 
			_CurrentFontWidth = UC1609FontWidth_7;
			_CurrentFontoffset = UC1609FontOffset_Space;
			_CurrentFontheight = UC1609FontHeight_8;
		break;
		case UC1609Font_Bignum : // big nums 16 by 32 (NUMBERS + : only)
			_CurrentFontWidth = UC1609FontWidth_16;
			_CurrentFontoffset = UC1609FontOffset_Number;
			_CurrentFontheight = UC1609FontHeight_32;
		break; 
		case UC1609Font_Mednum: // med nums 16 by 16 (NUMBERS + : only)
			_CurrentFontWidth = UC1609FontWidth_16;
			_CurrentFontoffset =  UC1609FontOffset_Number;
			_CurrentFontheight = UC1609FontHeight_16;
		break;
		default: // if wrong font num passed in,  set to default
			_CurrentFontWidth = UC1609FontWidth_5;
			_CurrentFontoffset =  UC1609FontOffset_Extend;
			_CurrentFontheight = UC1609FontHeight_8;
			_FontNumber = UC1609Font_Default;
		break;
	}
	
}

// Desc: writes a char (c) on the TFT
// Param 1 , 2 : coordinates (x, y).
// Param 3: The ASCII character
// Param 4: color 
// Param 5: background color
// Notes for font 7 & font 8 (bignums  + mednums)  only
void drawCharNumFont(uint8_t x, uint8_t y, uint8_t c, uint8_t color , uint8_t bg) 
{
    if (_FontNumber < UC1609Font_Bignum) 
		return;
    
	uint8_t i, j;
	uint8_t ctemp = 0, y0 = y; 

	for (i = 0; i < (_CurrentFontheight*2); i++) 
	{
		if (_FontNumber == UC1609Font_Bignum){
		#ifdef UC1609_Font_BigNum_enabled 
			ctemp = pFontBigNumptr[c - _CurrentFontoffset][i];
		#endif
		}
		else if (_FontNumber == UC1609Font_Mednum){
		#ifdef UC1609_Font_MedNum_enabled
			ctemp = pFontMedNumptr[c - _CurrentFontoffset][i];
		#endif
		}else{ 
			return;
		}
		
		for (j = 0; j < 8; j++) 
		{
			if (ctemp & 0x80) 
			{
				drawPixel(x, y, color);
			} else {
				drawPixel(x, y, bg);
			}

			ctemp <<= 1;
			y++;
			if ((y - y0) == _CurrentFontheight) {
				y = y0;
				x++;
				break;
			}
	}
	}
}

// Desc: Writes text string (*ptext) on the TFT 
// Param 1 , 2 : coordinates (x, y).
// Param 3: pointer to string 
// Param 4: color 
// Param 5: background color
// Notes for font 7 & font 8 (bignums  + mednums)  only
void drawTextNumFont(uint8_t x, uint8_t y, char *pText, uint8_t color, uint8_t bg) 
{
	if (_FontNumber < UC1609Font_Bignum) 
		return;

	while (*pText != '\0') 
	{
		if (x > (_width - _CurrentFontWidth )) 
		{
			x = 0;
			y += _CurrentFontheight ;
			if (y > (_height - _CurrentFontheight)) 
			{
					y = x = 0;
			}
		}

		drawCharNumFont(x, y, *pText, color, bg);
		x += _CurrentFontWidth ;
		pText++;
	}
}

// Desc: Draws an bi-color bitmap to screen
// Param 1,2  X,Y screen co-ord
// Param 3,4 0-127 possible values width and height of bitmap in pixels 
// Param 4,5 bitmap colors ,bitmap is bi-color
// Param 6: an array of unsigned chars containing bitmap data horizontally addressed.

void drawBitmapBuffer(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color, uint8_t bgcolor, const unsigned char bitmap[]) {
	int16_t byteWidth = (w + 7) / 8;
	uint8_t byte = 0;
    for (int16_t j = 0; j < h; j++, y++) 
	{
		for (int16_t i = 0; i < w; i++) 
		{
			if (i & 7)
				byte <<= 1;
			else
				byte = bitmap[j * byteWidth + i / 8];
			drawPixel(x+i, y, (byte & 0x80) ? color : bgcolor);
		}
	}
}
