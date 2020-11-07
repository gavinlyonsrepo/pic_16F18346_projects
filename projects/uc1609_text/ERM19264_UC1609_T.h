/*
* Project Name: ERM19264_UC1609_T
* File: ERM19264_UC1609_T.h
* Description: ERM19264 LCD driven by UC1609C controller header file text only version
* Author: Gavin Lyons.
* URL: URL: https://github.com/gavinlyonsrepo/pic_16F18346_proj
*/

#ifndef ERM19264_UC1609_T_H
#define ERM19264_UC1609_T_H

#include "LCD_FONT_CUSTOM.h"
#include "mcc_generated_files/mcc.h"

// Display Pixel colours   definition
// (1): white on blue,  FG = white BG = blue
// ERM19264SBS-4 LCD Display White on Blue
// (2): black on white, FG = black BG = white
// ERM19264FS-4 LCD Display Black on White
// (3):white on black,  FG = white, BG = black
// ERM19264DNS-4LCD Display White on Black
#define FOREGROUND  0
#define BACKGROUND 1
#define INVERSE 2

// UC1909 Read registers
#define UC1609_GET_STATUS 0x01 // Not used v1.0

// UC1909 Write registers
#define UC1609_SYSTEM_RESET 0xE2 // Not used v1.0

#define UC1609_POWER_CONTROL 0x2F 
#define UC1609_PC_SET 0x06 // PC[2:0] 110 Internal V LCD (7x charge pump) + 10b: 1.4mA

#define UC1609_ADDRESS_CONTROL 0x88 // set RAM address control
#define UC1609_ADDRESS_SET 0x02 // Set AC [2:0] Program registers  for RAM address control.

#define UC1609_SET_PAGEADD 0xB0 // Page address Set PA[3:0]
#define UC1609_SET_COLADD_LSB 0x00 // Column Address Set CA [3:0]
#define UC1609_SET_COLADD_MSB 0x10 // Column Address Set CA [7:4]

#define UC1609_TEMP_COMP_REG 0x27 // Temperature Compensation Register
#define UC1609_TEMP_COMP_SET 0x00 // TC[1:0] = 00b= -0.00%/ C

#define UC1609_FRAMERATE_REG 0xA0 // Frame rate
#define UC1609_FRAMERATE_SET 0x01  // Set Frame Rate LC [4:3] 01b: 95 fps

#define UC1609_BIAS_RATIO 0xE8 // Bias Ratio. The ratio between V-LCD and V-D .
#define UC1609_BIAS_RATIO_SET 0x03 //  Set BR[1:0] = 11 (set to 9 default)

#define UC1609_GN_PM 0x81 // Set V BIAS Potentiometer to fine tune V-D and V-LCD  (double-byte command)
#define UC1609_DEFAULT_GN_PM 0x49 // default only used if user does not specify Vbias

#define UC1609_LCD_CONTROL 0xC0 // Rotate map control
#define UC1609_DISPLAY_ON 0xAE // enables display
#define UC1609_ALL_PIXEL_ON 0xA4 // sets on all Pixels on
#define UC1609_INVERSE_DISPLAY 0xA6 // inverts display
#define UC1609_SCROLL 0x40 // scrolls , Set the scroll line number. 0-64

// Rotate
#define UC1609_ROTATION_FLIP_TWO 0x06
#define UC1609_ROTATION_NORMAL 0x04
#define UC1609_ROTATION_FLIP_ONE 0x02
#define UC1609_ROTATION_FLIP_THREE 0x00

// Delays
#define UC1609_RESET_DELAY 50 // mS delay
#define UC1609_RESET_DELAY2   0 // mS delay
#define UC1609_INIT_DELAY 100   //  mS delay
#define UC1609_INIT_DELAY2 3 // mS delay

//font
#ifdef UC_FONT_MOD_ONE
	#define UC1609_ASCII_OFFSET 0x00
#else
	#define UC1609_ASCII_OFFSET 0x20 //0x20, ASCII character for Space
#endif
#define UC1609_FONTPADDING  send_data(0x00)
#define UC1609_FONTWIDTH 5

//SPI
#define UC1609_HIGHFREQ_DELAY 0 // Can be used in software SPI for high freq MCU

// Display  Size
const uint8_t LCD_WIDTH = 192;
const uint8_t LCD_HEIGHT = 64;

// Contrast default 0x49 datasheet 00-FE
uint8_t _VbiasPOT; 


//  Functions
void  LCDGotoXY(uint8_t column , uint8_t page);
void  LCDChar(char character);
void  LCDString(const char *characters);
void LCDbegin(uint8_t VbiasPot );
void LCDinit(void);
void LCDEnable(uint8_t on);
void LCDFillScreen(uint8_t pixel);
void LCDFillPage(uint8_t pixels);
void LCDrotate(uint8_t rotatevalue);
void invertDisplay(uint8_t on);
void LCD_allpixelsOn(uint8_t bits);
void LCDscroll(uint8_t bits);
void LCDReset(void);
void LCDBitmap(int16_t x, int16_t y, uint8_t w, uint8_t h, const uint8_t* data);
           
void send_data(uint8_t databyte);
void send_command(uint8_t command, uint8_t value);
void CustomshiftOut(uint8_t val);

#endif
// EOF