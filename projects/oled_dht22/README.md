

Overview
--------------------------------------------
* Name: OLED_DHT22
* Description: Display DHT22 sensor(AM2302 package) temperature and humidity on an
  OLED display (128 by 64 pixels SSD1306 I2C bus).
* Author: Gavin Lyons.
* Complier: xc8 v2.1.0
* Foundation services library: 0.2.0 (I2C)
* MCC version: 3.95
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30


Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)
  * [Output](#output)
  
Features
----------------------

In this folder the main source code in C for program can be found in file main.c.
The code generated using the MPLAB Code Configurator (MCC) tool is  
in a folder called mcc_generated_files. 

There is also an Oled library(OLED.c and OLED.h),
and a font.h file that contains an ASCII pixelfont.

The sensor code is also in a library(dht22.c and dht22.h)

** Connections **

1. RC3 = DHT22 Sensor line,
2. RC2 = Status LED, toggles every sensor refresh. 
3. RB4 = SDA OLED
4. RB6 = SCLK OLED

**OLED 128 by 64 SSD1306**

The SSD1306 OLED display communicates with the master device over I2C mode.
It is controlled via the two pin I2C bus. Both pins must be held logic high by pull-up resistors. 

The ASCII based font file is a called "font.h". Each character is printed in a 5 by 8 box pixel.
(width by height) with a another blank byte printed in between so a box of 48 pixels in total for each character.
The screen is 128 by 32 pixels. So (32/8) 4 rows available and (128/6) 21 columns available.

This library turns the OLED into a character 21x04 based screen.
There are no graphics in library and one font. 
Will also work on a  OLED 128 by 32 SSD1306, as well with one modification to library.
( comment in/out a block of marked code at top of oled.h).


**DHT 22 sensor**
Digital relative humidity & temperature sensorAM2302/DHT22.
This 3 wire sensor provides Temperature and humidity data, 

[link](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)

Output
-----------------------
![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/output.jpg)
