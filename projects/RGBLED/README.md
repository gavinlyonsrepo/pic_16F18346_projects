Table of contents
---------------------------

  * [Overview](#overview)
  * [Hardware](#hardware)
  * [Software](#software)


Overview
--------------------------------------------
* Name:RGB_LED
* Description:
	A simple Common anode RGB led lighting Display with different modes.
* Author: Gavin Lyons.
* Complier: xc8 v2.4.0
* PIC: PIC16F18346
* IDE:  MPLAB X v6.00

Hardware
------------------------

Schematic, Add more RGB LED's and resistors as necessary. Vcc = 5V.

![ schematic ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/rgbled/rgbled.png)


Software
---------------------------------

Timer0 is used to debounce  S1 push button. Which changes from "timed mode" to the "steady modes". Timer1 is used for a delay at which to  change LED transition in timed mode, 
The transition duration is set by the R2 potentiometer value.
