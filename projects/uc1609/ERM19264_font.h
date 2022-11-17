/*
* Project Name: ERM19264_UC1609
* File: Font file
* Description: ERM19264 LCD driven by UC1609C controller font file 
* Author: Gavin Lyons.
* URL: https://github.com/gavinlyonsrepo/pic_16F18346_projects
*/

#ifndef FONTERM19264_H
#define FONTERM19264_H

// *****************************************
// ****** USER FONT OPTION ONE *************
// ****** FONT DEFINE SECTION **************
// Comment in the fonts YOU want, One is default. 

#define UC1609_Font_Default // (1) default  (FUll ASCII with mods)
//#define UC1609_Font_Thick  // (2) thick (NO LOWERCASE)
//#define UC1609_Font_SevenSeg// (3) seven segment 
//#define UC1609_Font_Wide // (4) wide (NO LOWERCASE)
//#define UC1609_Font_BigNum // (5) big numbers (NUMBERS ONLY )
//#define UC1609_Font_MedNum // (6) Medium nums (NUMBERS ONLY )

// ****** END OF FONT DEFINE SECTION ******  
// ****************************************
 

#ifdef UC1609_Font_Default
extern const unsigned char * pFontDefaultptr; 
#endif
#ifdef UC1609_Font_Thick
extern const unsigned char * pFontThickptr; 
#endif
#ifdef UC1609_Font_SevenSeg
extern const unsigned char * pFontSevenSegptr; 
#endif
#ifdef UC1609_Font_Wide 
extern const unsigned char * pFontWideptr; 
#endif
#ifdef UC1609_Font_BigNum
extern const uint8_t  (* pFontBigNumptr)[64] ;
#endif
#ifdef UC1609_Font_MedNum
extern const uint8_t  (* pFontMedNumptr)[32] ;
#endif

#endif // font file guard header
