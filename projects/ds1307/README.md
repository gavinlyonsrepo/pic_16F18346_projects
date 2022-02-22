

Overview
--------------------------------------------
* Name: DS1307
* Description: Alarm clock,
  Display DS1307 Real time clock data on a
  HD44780-based LCD 16x02 Library I2C bus & PCF8574 interface, 
  keyboard entry to set date/time
* Author: Gavin Lyons.
* Complier: xc8 v2.1.0
* MCC version: 3.95
* PIC: PIC16F18346
* IDE:  MPLAB X v5.30


Table of contents
---------------------------

  * [Overview](#overview)
  * [Output](#output)
  * [Software](#software)
  * [Hardware](#hardware)
  * [Schematic](#schematic)
  
  Output
-----------------------

![ output ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/output3.jpg)
  
Software
----------------------

In this folder the main source code in C (xc8) for program can be found in file main.c.
The code generated using the MPLAB Code Configurator is in a folder called mcc_generated_files. 
There is a LCD library(HD44780_I2C_lcd.c and HD44780_I2C_lcd.h), for controlling the HD44780-based LCD 16x02 library I2C bus & PCF8574 interface.
There is a Ds1307 RTC library(RTC_DS1307.c and RTC_DS1307.h)
There is a keyboard library (Keypad_green_4x4.h and Keypad_green_4x4.c). 4X4 keypad.
The time is changed on timer0 interrupt every second.

Hardware
------------------------

**Keypad**

The keypad in question is 4X4 matrix green PCB, pictured.

Keypad wiring where 1 is top pin 

1.	RC3	C4 Column 4 of keypad, Input with WPU
2.	RC2	C3 Column 3 of keypad, Input with WPU
3.	RC1	C2 Column 2 of keypad, Input with WPU
4.	RC0	C1 Column 1 of keypad, Input with WPU
5.	RC4	Row A of keypad, output
6.	RC5	Row B of keypad, output
7.	RC6	Row C of keypad, output
8.	RC7	Row D of keypad, output

Keypad map
 
| map  |  C1 | C2 | C3 |  C4| 
| ---   | --- | --- | --- | --- |
| RowA  |  7 |  8  | 9 |  A |
| RowB  |  4 |  5  | 6  | B |
| RowC  |  1 |  2  | 3  | C |
| RowD  |  F |  0  | E  | D |

Keypad function

1. A = Alarm set, HHMM
2. B = Alarm unset
3. C = Alarm/Buzzer test
4. D = Time and Date set,  YYMMDDWHHMM , where W is day of week,  Sun = 1
5. E = LCD backlight on/off
6. F = LCD reset 
7. 1 = Display on/off
8. 0 = Alarm stop 

![ output ](https://github.com/gavinlyonsrepo/pic_18F47K42_projects/blob/master/images/keypad.jpg)


**HD44780-based character LCD**

HD44780 based character LCD display plus a 4-pin PCF8574 (I2C) Interface "backpack" board, it is controlled via the two pin I2C bus.
The Data is sent in 4-bit mode. The upper nibble holds the data and lower nibble of byte manipulates the control bits of LCD(enable and register select etc). 

![PCF8574 & LCD ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCDPCF.jpg)


**DS1307 Real time clock (RTC) module**

The DS1307 serial real-time clock (RTC) is a lowpower, full binary-coded decimal (BCD) clock/calendar
plus 56 bytes of NV SRAM. Address and data are transferred serially through an I2C, bidirectional bus.
The clock/calendar provides seconds, minutes, hours,
day, date, month, and year information.

[ Datasheet ](https://datasheets.maximintegrated.com/en/ds/DS1307.pdf)

![ ds1307 ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/ds1307.jpg)

Schematic
------------------------

![ schematic ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/ds1307sch.jpg)

