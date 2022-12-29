/*
* Project Name: ERM19264_UC1609
* File: Font file
* Description: ERM19264 LCD driven by UC1609C controller font file 
* Author: Gavin Lyons.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#ifndef FONTERM19264_H
#define FONTERM19264_H

// ****** USER FONT OPTION ONE *************
// ****** FONT DEFINE SECTION *************** 
// Comment in the fonts YOU want, One is default. 

#define UC1609_Font_Default_enabled  // (1) default  (FUll ASCII with mods)
//#define UC1609_Font_Thick_enabled  // (2) thick (NO LOWERCASE)
//#define UC1609_Font_SevenSeg_enabled // (3) seven segment 
//#define UC1609_Font_Wide_enabled // (4) wide (NO LOWERCASE)
//#define UC1609_Font_Tiny_enabled // (5) tiny
//#define UC1609_Font_Homespun_enabled // (6) HomeSpun
//#define UC1609_Font_BigNum_enabled // (7) big numbers (NUMBERS ONLY )
//#define UC1609_Font_MedNum_enabled // (8) Med numbers (NUMBERS ONLY )

// ****** END OF FONT DEFINE SECTION ******  
// **********************************************
 
// Font data is in the cpp file accessed thru extern pointers.

#ifdef UC1609_Font_Default_enabled 
extern const unsigned char * pFontDefaultptr;
#endif
#ifdef UC1609_Font_Thick_enabled
extern const unsigned char * pFontThickptr;
#endif
#ifdef UC1609_Font_SevenSeg_enabled
extern const unsigned char * pFontSevenSegptr;
#endif
#ifdef UC1609_Font_Wide_enabled
extern const unsigned char * pFontWideptr;
#endif
#ifdef UC1609_Font_Tiny_enabled 
extern const  unsigned char * pFontTinyptr;
#endif
#ifdef UC1609_Font_Homespun_enabled
extern const unsigned char * pFontHomeSpunptr;
#endif
#ifdef UC1609_Font_BigNum_enabled
extern const uint8_t (* pFontBigNumptr)[64];
#endif
#ifdef UC1609_Font_MedNum_enabled
extern const uint8_t (* pFontMedNumptr)[32]; 
#endif

typedef enum 
{
    UC1609Font_Default = 1,
    UC1609Font_Thick = 2, // NO LOWERCASE
    UC1609Font_Seven_Seg = 3,
    UC1609Font_Wide = 4, // NO LOWERCASE
    UC1609Font_Tiny = 5,
    UC1609Font_Homespun = 6,
    UC1609Font_Bignum = 7, // NUMBERS + : . ,one size
    UC1609Font_Mednum = 8 // NUMBERS + : . ,one size
}LCDFontName_e;

typedef enum 
{
	UC1609FontWidth_3 = 3,
	UC1609FontWidth_5 = 5, 
	UC1609FontWidth_7 = 7, 
	UC1609FontWidth_4 = 4, 
	UC1609FontWidth_8 = 8,
	UC1609FontWidth_16 = 16
}UC1609FontWidth_e; // width of the font in bits *(N bytes cols).

typedef enum 
{
	UC1609FontOffset_Extend = 0x00, //   extends ASCII
	UC1609FontOffset_Space = 0x20,  // Starts at Space
	UC1609FontOffset_Number = 0x30,  // Starts at number '0'
}UC1609FontOffset_e; // font offset in the ASCII table

typedef enum 
{
	UC1609FontHeight_8 = 8, 
	UC1609FontHeight_16 = 16, 
	UC1609FontHeight_32 = 32
}UC1609FontHeight_e; // height of the font in bits

#endif // font file guard header
