![ ERM19264 ](https://github.com/gavinlyonsrepo/ERM19264_UC1609/blob/main/extras/image/color.jpg)

  
Overview
--------------------
* Name : ERM19264_UC1609
* Title : Library for ERM19264-5 v3 LCD  (UC1609C controller) 
* Description : 

1. PIC library written in C Xc8 compiler.      
2. Inverse, rotate and contrast control. 
3. ASCII text strings and character text display.
4. Graphics library included
5. Sleep mode.
6. Buffer
7. Custom bitmaps supported.
8. Hardware SPI.
9. 6 fonts, Size adjustable.
10. Light weight text only  version here  | [URL](projects/uc1609_text) |

Output
---------------------------------

Output Screenshots, From left to right top to bottom.

1. Full screen bitmap displayed
2. Multi buffer mode screen divided into two buffers
3. Different size and type of fonts 
4. Available font printed out (this can be expanded by mod see features)

![op](https://github.com/gavinlyonsrepo/ERM19264_UC1609/blob/main/extras/image/output.jpg)


Connections
-----------------------------

1. RA0 - CS
2. RA1 - CD
3. RB5 - SDA
4. RB6 - SCLK
5. RA5 - RST

Ports
------------------------------------------

Lots more info and documentation at links 1 and 2, This library is a truncated port of no 1.
It only supports Hardware SPI and only has one buffer mode.
There is also  light weight basic text only versions available for arduino and PIC at "gavinlyonsrepo" on github.

1. Arduino C++ [Link](https://github.com/gavinlyonsrepo/ERM19264_UC1609)
2. Raspberry PI C++ [Link](https://github.com/gavinlyonsrepo/ERM19264_UC1609_RPI)
3. STM32 C++  [Link](https://github.com/gavinlyonsrepo/STM32_projects)
