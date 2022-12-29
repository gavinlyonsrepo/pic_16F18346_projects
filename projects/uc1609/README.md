![ ERM19264 ](https://github.com/gavinlyonsrepo/ERM19264_UC1609/blob/main/extras/image/color.jpg)

 Table of contents
---------------------------

  * [Overview](#overview)
  * [Arduino Library](#arduino-library) 
  * [Output](#output)
  * [Bitmap](#bitmap)
  * [Connections](#connections)
  * [Files](#files)
 
Overview
--------------------
* Name : ERM19264_UC1609
* Title : Library for ERM19264-5 v3 LCD  (UC1609C controller) 
* Description : 

1. PIC library written in C, Xc8 compiler. 
2. Inverse, rotate and contrast control. 
3. ASCII text strings and character text display.
4. Graphics library included
5. Sleep mode.
6. Multi Buffer Mode
7. Custom bitmaps supported.
8. Hardware SPI.
9. 8 fonts, Size adjustable.
10. Light weight version available in projects folder  "uc1609_text".

Arduino Library
------------------------------------------

This library is a truncated port of my Arduino library.
Lots MORE info and documentation at Arduino Link below.

Arduino C++ [Link](https://github.com/gavinlyonsrepo/ERM19264_UC1609)

The main differences between this PIC port and Arduino library is 
1. PIC port only supports Hardware SPI 
2. PIC port only has one buffer mode(multi-buffer).
3. PIC is written  in  C. 
4. PIC port does not have the in-built Arduino "print" class. 


Output
---------------------------------

Output Screenshots, From left to right , top to bottom.

1. Full screen bitmap displayed
2. Multi buffer mode screen divided into two buffers 
3. Different size and type of fonts 
4. Available font printed out (this can be expanded by mod )
5. Fonts 7-8
6. Fonts 1-4

![op](https://github.com/gavinlyonsrepo/ERM19264_UC1609/blob/main/extras/image/output.jpg)

![op2](https://github.com/gavinlyonsrepo/ERM19264_UC1609/blob/main/extras/image/output2.jpg)

Bitmaps 
----------------------------------

Two  bitmaps functions :

1. LCDBitmap() writes bitmap directly to LCD with vertical addressing
2. drawBitmapBuffer() writes bitmap to software buffer with  horizontal addressing 

Connections
-----------------------------

Hardware SPI.

1. RA0 - CS
2. RA1 - CD
3. RB5 - SDA
4. RB6 - SCLK
5. RA5 - RST

Files
--------------------------------

| Src Files| Desc |
| ------ | ------ |
| ERM19264_UC1609.h | library header file  |
| ERM19264_UC1609.c |  library  source file  |
| ERM19264_graphics.h | graphics header file |
| ERM19264_graphics.c | graphics source file |
| ERM19264_font.h | font header file |
| ERM19264_font.c | font  data file's |

| Examples files   | Description | 
| ------ | ------ | 
| main.c | Shows use of fonts and graphics, with whole screen as one buffer | 
|  main_multibuffer.c  | Shows how to divide screen into 3 sectors, this greatly reduces memory usage , The same piece of memory can be shared by the one buffer, this file is in example folder |

