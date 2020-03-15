/*
* File: SevenSegDisplay.h
* Description: header file for Seven Segment ASCII Display  library
* Author: Gavin Lyons.
*/

#ifndef SevenSegDisplay_h
#define SevenSegDisplay_h

#define SHIFT_DELAY 5   //shift delay in usecconds can be adjusted to avoid flickering 
#define ASCII_OFFSET 32 // ASCII table offset to jump over first missing 32 chars
#define HEX_OFFSET   16 // ASCII table offset to reach 0 position
#define DOT_MASK_DEC   0x80 //  Mask to switch on decimal point in fourteen segment.   
#define COMMON_ANODE_MASK 0xFF // mask to be applied if user wants common anode. 


// passed a boolean value
// common true = Common Cathode
// common false = Common Anode
void SevenSegDisplay(bool common);

 /*
Note: 
The digits/startPos parameter in the functions refers to the position/starting bit.
0x80  b10000000 D8 LHS 
0x40- b01000000 D7 
0x20- b00100000 D6  
0x10- b00010000 D5
0x08- b00001000 D4
0x04- b00000100 D3
0x02- b00000010 D2
0x01- b00000001 D1 RHS
*/

// Send ASCII value to 7 segment display, passed ASCII value byte, 
// and  digit position0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01-0x00  D8-D1
void displayASCII(uint8_t ascii, uint8_t digits);

// Same as displayASCII function but turns on dot/decimal point as well ,
// and digit position0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01-0x00  D8-D1
void displayASCIIwDot(uint8_t ascii, uint8_t digits) ;

// Send HEX value to 7 segment display, passed a hex value  0-15 : 0x00 to 0x0F,  
// and  digit position0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01-0x00  D8-D1
void displayHex(uint8_t hex, uint8_t digits );

// Send  segment value to  7 segment display
//  Passed value corresponding to segments  (DP-G-F-E-D-C-B-A) One bytes. 
//  eg 0x01 will switch on A 
//  and  digit position 0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01-0x00 D8-D1
void displaySeg(uint8_t value, uint8_t digits);

// Passed a string and starting position0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01-0x00  D8-D1
// So to print AB as "AB" set start position to 2.
void displayString(const char* str, uint8_t startPos );

// Used by DataDisplay function for shifting out data to 74HC595
void clock(void);

// Used to display data and digit position 
// passed byte  to display.
void DataDisplay(unsigned int data);

bool _commonCathode;

#endif
