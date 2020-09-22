Overview
--------------------------------------------
* Name: ST7735
* Description: 
Library for TFT SPI LCD, ST7735 Driver, RED PCB v1.1, 1.44'', 128 x 128 pixels. 
 
* Version 1.0
* Author: Gavin Lyons
* Complier : XC8: 2.10
* MCC version: 3.95
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
* Credits: Based on a CCS C compiler Library by[simple-circuits](https://simple-circuit.com/st7735-tft-library-ccs-c-compiler/) and the Arduino built-in TFT library.
  
Features
----------------------

**TFT SPI LCD, ST7735 Driver, RED PCB v1.1, 1.44'', 128 x 128 pixels**

![ ig ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/ST77352.jpg)
 
This library supports both Hardware SPI and software SPI. Change the define a top of header file
to switch between the two. It may  work on other TFT displays using the different init functions but not tested.
This Color TFT LCD display has 128 x 128 resolution and 262 color, it uses SPI interface to communicate with controller. Onboard LDO, support 5V/3.3V input voltage, the LED backlight, 3.3V input.
Size 1.44 inch, visual area 1.1 inch. 

**Files**

The file main.c contains a set of test routine's. The code generated using the MCC is in a folder called mcc_generated_files. The SPI routine's are in here.
There is also an TFT library (ST7735_TFT.c and ST7735_TFT.h),
and TextFonts.h file that contains the ASCII pixel font.

**Connections**

| TFT PinNum  Pindesc | PIC SW SPI | PIC HW SPI |
| --- | --- | --- | 
| 1 LED | 3.3V | LED |
| 2 SCLK | RA4 | RB6 SCK1 |
| 3 SDA | RA2 | RB5 SD01 |
| 4 A0/DC | RA1 | RA1 |
| 5 RESET | RA5  | RA5 | 
| 6 CS | RA0 | RA0 |
| 7 GND | GND | GND |
| 8 VCC | VCC 3.3V | VCC 3.3V |

1. NOTE connect LED backlight pin 1  thru a ~200 ohm resistor to 3.3V.
2. RC5 = Test Status LED optional. 
3. This is a 3.3 device do NOT connect  the I/O lines to 5v , You can connect VCC to 5V if there is a 3.3 volt regulator on TFT module.

Output
-----------------------

Output of some of the test routine's showing different text sizes and colours and shapes.

![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/ST7735.jpg)
