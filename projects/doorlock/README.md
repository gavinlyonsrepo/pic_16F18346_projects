Overview
--------------------------------------------
* Name: Electronic lock
* Description:  
Security electronic lock , featuring keypad input , LCD display
Servo control amd EEPROM.
* Author: Gavin Lyons.
* PIC: PIC18F47K42

 
Features
----------------------

There is also two custom libraries one for the LCD and the other for keypad.
Information on these libraries can be found [here at github link.](https://github.com/gavinlyonsrepo/pic_16F18346_projects/tree/master/projects/ds1307)

The password is stored in EEPROM.  Enter code on keypad and press D.
Press C to "re-lock" after sucessfully code entry and unlock. 
Enter B to change password, option to hard-code password.

**Connections**

1. RA0 = SG90 Servo line input. (servo powered from PSU 5V rail)
2. RA5 = Status LED, ON at startup and when safe unlocked 
3. RB6 = SCLK I2C LCD, 
4. RB4 = SDATA I2C LCD, 
5. RC0 = Column 1 of keypad, Input with WPU
6. RC1 = Column 2 of keypad, Input with WPU
7. RC2 = Column 3 of keypad, Input with WPU
8. RC3 = Column 4 of keypad, Input with WPU
9. RC4 = Row A of keypad, output
10. RC5 =  Row B of keypad, output
11. RC6 = Row C of keypad, output
12. RC7 = Row D of keypad, output

