Overview
--------------------------------------------
* Name: OLED_DHT22
* Description: Display DHT22 sensor(AM2302 package) temperature and humidity on an
  OLED display (128 by 64 pixels SSD1306 I2C bus). The library for OLED has text and graphics features.
* Author: Gavin Lyons.
* Complier: xc8 v2.1.0
* Foundation services library: 0.2.0 (I2C)
* MCC version: 3.95
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30
  
Features
----------------------

In this folder the main source code in C for program can be found in file main.c.
The code generated using the MPLAB Code Configurator is in a folder called mcc_generated_files. 

There is also an Oled library(SSD1306OLED.c and SSD1306OLED.h),
and a TextFonts.h file that contains the ASCII pixelfonts and splash screen image.

The sensor code is also in a library(dht22.c and dht22.h)

**Connections**

1. RC3 = DHT22 Sensor line,
2. RC2 = Status LED, On for init and Error.  
3. RB4 = SDA OLED
4. RB6 = SCLK OLED

**OLED 128 by 64 SSD1306**

The SSD1306 OLED display communicates with the master device over I2C mode.
It is controlled via the two pin I2C bus. Both pins must be held logic high by pull-up resistors. 

The library can  display Graphics, text and bitmaps.

 Will also work on a  OLED (128 by 32) & (96 by 16) SSD1306, as well with one modification to library.
( comment in/out a define at top of header file.). 

Fonts. 

1. PICO font X by Y  = 4 by 6 . 288 characters.
2. UNO font X by Y = 6 by 8 . 147 characters.
3. MEGA font X by Y  = 16 by 16 . 32 characters

**DHT 22 sensor**

Digital relative humidity & temperature sensor AM2302/DHT22.
This 3 wire sensor provides temperature and humidity data, 

[Datasheet link](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)

Error codes:

1. 1200 Unknown
2. 1201 Timeout  ( failed to communicate with sensor)
3. 1202 Checksum ( communicated with sensor but data is corrupt) 


Output
-----------------------
![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/output4.jpg)
