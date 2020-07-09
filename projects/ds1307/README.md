

Overview
--------------------------------------------
* Name: DS1307
* Description: Display Ds1307 Real time clock humidity on an
  HD44780-based LCD 16x02 library I2C bus & PCF8574 interface
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
  * [Schematic](#schematic)
  
Features
----------------------

In this folder the main source code in C for program can be found in file main.c.
The code generated using the MPLAB Code Configurator is in a folder called mcc_generated_files. 

There is an LCD library(LCD.c and LCD.h), for controlling the HD44780-based 
LCD 16x02 library I2C bus & PCF8574 interface.

There is an Ds1307 RTC library(ds1307.c and ds1307.h)

**Connections**

1. RA4 = Status LED 
2. RB4 = SDA, LCD and DS1307
3. RB6 = SCLK, LCD and DS1307


**HD44780-based character LCD**

HD44780 based character LCD displays use 14 wire connections: 8 data lines (D0-D7), 3 control lines (RS, E, R/W), 
and three power lines (Vdd, Vss, Vee). 
Some LCDs come with backlight features that help reading display data in low illumination conditions. 
They have two additional connections (LED+ and LED- or A and K).

In this project, a 4-pin PCF8574 Interface "backpack" board is attached to LCD. It is controlled via the two pin I2C bus.
Both pins must be held logic high by pull-up resistors. w.
The LCD code is in a separate library called "lcd,h".
The Data is sent in 4-bit mode. The upper nibble holds the data and lower nibble of byte manipulates
the control bits of LCD(enable and register select). 

![PCF8574 & LCD ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCDPCF.jpg)


**DS1307 Real time clock (RTC) module**

The DS1307 serial real-time clock (RTC) is a lowpower, full binary-coded decimal (BCD) clock/calendar
plus 56 bytes of NV SRAM. Address and data are transferred serially through an I2C, bidirectional bus.
The clock/calendar provides seconds, minutes, hours,
day, date, month, and year information.

[ Datasheet ](https://datasheets.maximintegrated.com/en/ds/DS1307.pdf)

![ ds1307 ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/ds1307.jpg)

Output
-----------------------

![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/output3.jpg)


Schematic
------------------------

TODO
