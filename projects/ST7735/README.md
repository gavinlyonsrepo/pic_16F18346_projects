Overview
--------------------------------------------
* Name: ST7735
* Description: 
Library for TFT SPI LCD, ST7735 Driver, RED PCB v1.1, 1.44'', 128 x 128 pixels. no SD card holder.
 
* Author: Gavin Lyons
* Complier : XC8: 2.10
* MCC version: 3.95
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Credits:  
Based onCCS C compiler Library by [ simple-circuits](https://simple-circuit.com/st7735-tft-library-ccs-c-compiler/)  , 
Arduino built-in TFT library and some code from github user [bablokb](https://github.com/bablokb/pic-st7735)
  
Features
----------------------

**TFT SPI LCD, ST7735 Driver, RED PCB v1.1, 1.44'', 128 x 128 pixels, No SD card**

![ ig ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/st7735/pcb.jpg)
 
This Color TFT LCD display has 128 x 128 resolution.
It uses SPI interface to communicate with controller. Onboard LDO, support 5V/3.3V input voltage, 
the LED backlight, 3.3V input. Size 1.44 inch, visual area 1.1 inch. Version 1.1. No SD Card. 
Backlight control is left to user.

**PCB Version**

It may  work on other TFT displays using the different init functions, but not tested.
In the header file in USER OPTION 1 PCB_TYPE select your PCB.
default is red.  User can adjust pixel height, pixel width and screen offsets in the header file. 

There are 4 types of the ST7735 TFT display supported.

1. ST7735B controller 
2. ST7735R Green Tab
3. ST7735R Red Tab
4. ST7735R Black Tab (ST7735S)

**SPI**

This library supports both Hardware SPI and software SPI. Change the define a top of header file
to switch between the two. USER OPTION 3 SPI TYPE. 
Tested at 8,000,000 MHZ SPI clock. 

**Files**

The Main.c contains 12 tests showing library functions
The code generated using the MCC is in a folder called mcc_generated_files. 
The SPI routine's are in here.
There is also an TFT library (ST7735_TFT.c and ST7735_TFT.h),
and five fonts file that contains ASCII pixel fonts.

**Fonts**

Font one is included by default to include other font files see
USER OPTION 2 FONT  at start of header file.

Five fonts available : 

| Font num | Font name | Pixel size |  Note |
| ------ | ------ | ------ | ------ |  
| 1 | Default | 5x8 |   ------ |
| 2 | Thick   | 7x8 |  no lowercase letters  |
| 3 | Seven segment | 4x8 | ------ |
| 4 | Wide | 8x8 | no lowercase letters |
| 5 | Tiny | 3x8 |  ------ |

**Bitmap**

There are two functions to support drawing bitmaps
both are bi-color a background and a foreground.
Full color bitmaps are prohibitive on this PIC due to 
lack of memory. Note: The library was developed on a
TFT without built-in SD card feature.

1. Draw small custom icons X by 8 size where X is 0-128
useful to create icons or buttons or fill rows with patterns,
vertically addressed .

2. Draw bitmap, horizontally addressed .
 

**Connections**

| TFT PinNum | Pindesc | PIC SW SPI | PIC HW SPI |
| --- | --- | --- | --- | 
| 1 | LED | VCC |  VCC |
| 2 | SCLK | RA4 | RB6 SCK1 |
| 3 | SDA | RA2 | RB5 SD01 |
| 4 | A0/DC | RA1 | RA1 |
| 5 | RESET | RA5  | RA5 | 
| 6 | SS/CS | RA0 | RA0 |
| 7 | GND | GND | GND |
| 8 | VCC | VCC | VCC  |

1. NOTE connect LED backlight pin 1  thru a 150R to 220R ohm resistor to 3.3V or 5V VCC.
2. This is a 3.3V logic device do NOT connect  the I/O logic lines to 5V. 
3. You can connect VCC to 5V if there is a 3.3 volt regulator on back of TFT module.

Output
-----------------------

Output of some of the test routine's Left to right top to bottom

1. Different defined colors at default font size 1. Full 16 bit colour 565 available 
2. Different sizes of default font: 2,3,4 & 5 . Are fonts are scale-able
3. Different Fonts at font size 2, five fonts included .
4. Shapes
5. Shapes
6. Bitmap (bi-color) A background and a foreground. 

![ ig ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/st7735/9.jpg)
