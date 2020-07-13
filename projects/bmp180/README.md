

Overview
--------------------------------------------
* Name: BMP180
* Description: Display BMP180 barometric pressure sensor data on a
  HD44780-based LCD 16x02 I2C bus & PCF8574 interface, e
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

In this folder the main source code in C (xc8) for program can be found in file main.c.
The code generated using the MPLAB Code Configurator is in a folder called mcc_generated_files. 
There is a LCD library(LCD.c and LCD.h), for controlling the HD44780-based 
LCD 16x02 library I2C bus & PCF8574 interface.
There is a BMP180 library(ds1307.c and ds1307.h)


**Connections**

1. RA4 = Status LED 
2. RB4 = SDA, LCD and BMP180
3. RB6 = SCLK, LCD and BMP180


**HD44780-based character LCD**

HD44780 based character LCD displays use 14 wire connections: 8 data lines (D0-D7), 3 control lines (RS, E, R/W), 
and three power lines (Vdd, Vss, Vee). They have two additional connections (LED+ and LED- or A and K).
In this project, a 4-pin PCF8574 Interface "backpack" board is attached to LCD. It is controlled via the two pin I2C bus.
Both pins must be held logic high by pull-up resistors.
The LCD code is in a separate library called "lcd.h".
The Data is sent in 4-bit mode. The upper nibble holds the data and lower nibble of byte manipulates
the control bits of LCD(enable and register select). 

![PCF8574 & LCD ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCDPCF.jpg)


**BMP180 Digital Pressure Sensor**

This precision sensor from Bosch is a low-cost sensing solution for measuring barometric pressure and temperature. 
Because pressure changes with altitude you can also use it as an altimeter. 
The sensor is soldered onto a PCB module(GY-68) with a 3.3V regulator, I2C level shifter and pull-up resistors on the I2C pins.
The BMP180 is a replacement for the BMP085, 
It is identical to the BMP085 in terms of firmware. 

[ Datasheet ](https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf)

![ bmp180 ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/bmp180pic.jpg)

Output
-----------------------

Pressure output shown in pascals, the library can also calculate pressure by removing effects of 
altitude using sea level pressure and altitude itself for a given pressure. Also Temperature.

![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/bmp180.jpg)
