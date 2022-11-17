/* 
* Font data file for TFT library.
* 6 fonts + pointers in the .c file 
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#ifndef ST7735font_one_H
#define ST7735font_one_H

// ****** USER OPTION 3 FONT ******
// Comment in the fonts you want
#define TFT_Font_Default
#define TFT_Font_Thick
#define TFT_Font_SevenSeg
#define TFT_Font_Wide
#define TFT_Font_Tiny
#define TFT_Font_HomeSpun
// ******************************

#ifdef TFT_Font_Default
extern const char * pFontDefaultptr; // defined in ST7735_TFT_FONT.c 
#endif
#ifdef TFT_Font_Thick
extern const char * pFontThickptr; // defined in ST7735_TFT_FONT.c
#endif
#ifdef TFT_Font_SevenSeg
extern const char * pFontSevenptr; // defined in ST7735_TFT_FONT.c
#endif
#ifdef TFT_Font_Wide 
extern const char * pFontWideptr; // defined in ST7735_TFT_FONT.c
#endif
#ifdef TFT_Font_Tiny
extern const char * pFontTinyptr; // defined in ST7735_TFT_FONT.c
#endif
#ifdef TFT_Font_HomeSpun
extern const char * pFontHomeptr; // defined in ST7735_TFT_FONT.c
#endif


#endif // end of guard header 
