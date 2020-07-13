

Overview
--------------------------------------------
* Name: DS1307
* Description: Display DS1307 Real time clock data on a
  HD44780-based LCD 16x02 Library I2C bus & PCF8574 interface, 
  keyboard entry to set date/time
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
  * [TODO](#todo)
  
Features
----------------------

In this folder the main source code in C (xc8) for program can be found in file main.c.
The code generated using the MPLAB Code Configurator is in a folder called mcc_generated_files. 

There is a LCD library(LCD.c and LCD.h), for controlling the HD44780-based 
LCD 16x02 library I2C bus & PCF8574 interface.

There is a Ds1307 RTC library(ds1307.c and ds1307.h)

There is a keyboard library (Keypad.h and Keyboard.c). 4X4 keypad, This is used to
enter information to change date and time , 
This can also be done by programming on power up by commenting in the necessary function.
The time is changed on timer0 interrupt every second.

**Connections**

1. RA4 = Status LED 
2. RB4 = SDA, LCD and DS1307
3. RB6 = SCLK, LCD and DS1307
4. Keypad 8 connections , see below.

**Keypad**

There is a custom library in main folder called keypad.h and keypad.c.
The keypad in question is 4X4 matrix green PCB.
Which is wired as such from the top.

1.	RC3	C4 Column 4 of keypad, Input with WPU
2.	RC2	C3 Column 3 of keypad, Input with WPU
3.	RC1	C2 Column 2 of keypad, Input with WPU
4.	RC0	C1 Column 1 of keypad, Input with WPU
5.	RC4	Row A of keypad, output
6.	RC5	Row B of keypad, output
7.	RC6	Row C of keypad, output
8.	RC7	Row D of keypad, output

Pressing "D" to normal mode to enter date/time setup mode.
 
RowA    7   8   9   A
RowB    4   5   6   B
RowC    1   2   3   C
RowD    n   0   n   D

Then enter time/date in following order:

1. YYMMDDWHHSS
2. Where W is day of the week Sunday = 1 , Monday = 2 etc

![ output ](https://github.com/gavinlyonsrepo/pic_18F47K42_projects/blob/master/images/keypad.jpg)


**HD44780-based character LCD**

HD44780 based character LCD displays use 14 wire connections: 8 data lines (D0-D7), 3 control lines (RS, E, R/W), 
and three power lines (Vdd, Vss, Vee). They have two additional connections (LED+ and LED- or A and K).
In this project, a 4-pin PCF8574 Interface "backpack" board is attached to LCD. It is controlled via the two pin I2C bus.
Both pins must be held logic high by pull-up resistors.
The LCD code is in a separate library called "lcd.h".
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

![ schematic ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/ds1307sch.jpg)


TODO
------------------------

1.  Error handling function to handle empty battery and no connection to RTC.
2.  Error handling to check for bad user input on keypad.
3.  Add Alarm function.
