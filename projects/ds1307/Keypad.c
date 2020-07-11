/*
* Project Name: Keypad
* File: keypad.c
* Description: library for 4 by 4 matrix keypad
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler 
* IDE:  MPLAB X v5.30
* Created March 2020
* URL: github gavinlyonsrepo 
*/

#include "Keypad.h"
#include "mcc_generated_files/mcc.h"


// Function name: Read Keys
// Scan all the keypad keys to detect any pressed key, return character 
//          C1  C2  C3  C4
// ROW A    7   8   9   A
// ROW B    4   5   6   B
// ROW C    1   2   3   C
// ROW D    n   0   n   D
char ReadKeys(void)	
{	
    //Test ROW A
    ROWA_RC4_SetLow();
    ROWB_RC5_SetHigh();
    ROWC_RC6_SetHigh();
    ROWD_RC7_SetHigh();

	if (C1_RC0_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C1_RC0_GetValue()==0); return '7'; }
	if (C2_RC1_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C2_RC1_GetValue()==0); return '8'; }
	if (C3_RC2_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C3_RC2_GetValue()==0); return '9'; }
	if (C4_RC3_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C4_RC3_GetValue()==0); return 'A'; }

    //Test ROW B
    ROWA_RC4_SetHigh();
    ROWB_RC5_SetLow();
    ROWC_RC6_SetHigh();
    ROWD_RC7_SetHigh();
   
	if (C1_RC0_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C1_RC0_GetValue()==0); return '4'; }
	if (C2_RC1_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C2_RC1_GetValue()==0); return '5'; }
	if (C3_RC2_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C3_RC2_GetValue()==0); return '6'; }
	if (C4_RC3_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C4_RC3_GetValue()==0); return 'B'; }
	
	//Test ROW C
    ROWA_RC4_SetHigh();
    ROWB_RC5_SetHigh();
    ROWC_RC6_SetLow();
    ROWD_RC7_SetHigh();

	if (C1_RC0_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C1_RC0_GetValue()==0); return '1'; }
	if (C2_RC1_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C2_RC1_GetValue()==0); return '2'; }
	if (C3_RC2_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C3_RC2_GetValue()==0); return '3'; }
	if (C4_RC3_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C4_RC3_GetValue()==0); return 'C'; }
	
    //Test ROW D
    ROWA_RC4_SetHigh();
    ROWB_RC5_SetHigh();
    ROWC_RC6_SetHigh();
    ROWD_RC7_SetLow();
    
	if (C1_RC0_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C1_RC0_GetValue()==0); return 'n'; }
	if (C2_RC1_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C2_RC1_GetValue()==0); return '0'; }
	if (C3_RC2_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C3_RC2_GetValue()==0); return 'n'; }
	if (C4_RC3_GetValue()==0) { __delay_ms(KEYPAD_DEBOUNCE ); while (C4_RC3_GetValue()==0); return 'D'; }

	return 'n';           	// Return 'n' if no key pressed
}


// Function name: GetKey
// Read pressed key value from keypad and return its value
char GetKey(void)           	 // Get key from user
{
	char key = 'n';              // Assume no key pressed

	while(key=='n')              // Wait until a key is pressed
		key = ReadKeys();   // Scan the keys //again and again

	return key;                  //when key pressed then return its value
}