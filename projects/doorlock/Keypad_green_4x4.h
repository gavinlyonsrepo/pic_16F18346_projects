/*
* Project Name: Keypad
* File: keypad.h
* Description: library for 4 by 4 matrix keypad green pcb
* Author: Gavin Lyons.
*/


#ifndef __KEYPAD_H
#define __KEYPAD_H


#define KEYPAD_DEBOUNCE 200 // Debounce Delay in mS 

// Function declarations
char KeypadGetKey(void);
char KeyPadReadKeys(void);

#endif