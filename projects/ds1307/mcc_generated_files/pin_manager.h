/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BUZZER_RA2 aliases
#define BUZZER_RA2_TRIS                 TRISAbits.TRISA2
#define BUZZER_RA2_LAT                  LATAbits.LATA2
#define BUZZER_RA2_PORT                 PORTAbits.RA2
#define BUZZER_RA2_WPU                  WPUAbits.WPUA2
#define BUZZER_RA2_OD                   ODCONAbits.ODCA2
#define BUZZER_RA2_ANS                  ANSELAbits.ANSA2
#define BUZZER_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BUZZER_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BUZZER_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BUZZER_RA2_GetValue()           PORTAbits.RA2
#define BUZZER_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BUZZER_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BUZZER_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define BUZZER_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define BUZZER_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define BUZZER_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define BUZZER_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define BUZZER_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED_RA5 aliases
#define LED_RA5_TRIS                 TRISAbits.TRISA5
#define LED_RA5_LAT                  LATAbits.LATA5
#define LED_RA5_PORT                 PORTAbits.RA5
#define LED_RA5_WPU                  WPUAbits.WPUA5
#define LED_RA5_OD                   ODCONAbits.ODCA5
#define LED_RA5_ANS                  ANSELAbits.ANSA5
#define LED_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_RA5_GetValue()           PORTAbits.RA5
#define LED_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_RA5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED_RA5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set C1_RC0 aliases
#define C1_RC0_TRIS                 TRISCbits.TRISC0
#define C1_RC0_LAT                  LATCbits.LATC0
#define C1_RC0_PORT                 PORTCbits.RC0
#define C1_RC0_WPU                  WPUCbits.WPUC0
#define C1_RC0_OD                   ODCONCbits.ODCC0
#define C1_RC0_ANS                  ANSELCbits.ANSC0
#define C1_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define C1_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define C1_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define C1_RC0_GetValue()           PORTCbits.RC0
#define C1_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define C1_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define C1_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define C1_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define C1_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define C1_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define C1_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define C1_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set C2_RC1 aliases
#define C2_RC1_TRIS                 TRISCbits.TRISC1
#define C2_RC1_LAT                  LATCbits.LATC1
#define C2_RC1_PORT                 PORTCbits.RC1
#define C2_RC1_WPU                  WPUCbits.WPUC1
#define C2_RC1_OD                   ODCONCbits.ODCC1
#define C2_RC1_ANS                  ANSELCbits.ANSC1
#define C2_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define C2_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define C2_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define C2_RC1_GetValue()           PORTCbits.RC1
#define C2_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define C2_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define C2_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define C2_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define C2_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define C2_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define C2_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define C2_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set C3_RC2 aliases
#define C3_RC2_TRIS                 TRISCbits.TRISC2
#define C3_RC2_LAT                  LATCbits.LATC2
#define C3_RC2_PORT                 PORTCbits.RC2
#define C3_RC2_WPU                  WPUCbits.WPUC2
#define C3_RC2_OD                   ODCONCbits.ODCC2
#define C3_RC2_ANS                  ANSELCbits.ANSC2
#define C3_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define C3_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define C3_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define C3_RC2_GetValue()           PORTCbits.RC2
#define C3_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define C3_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define C3_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define C3_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define C3_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define C3_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define C3_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define C3_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set C4_RC3 aliases
#define C4_RC3_TRIS                 TRISCbits.TRISC3
#define C4_RC3_LAT                  LATCbits.LATC3
#define C4_RC3_PORT                 PORTCbits.RC3
#define C4_RC3_WPU                  WPUCbits.WPUC3
#define C4_RC3_OD                   ODCONCbits.ODCC3
#define C4_RC3_ANS                  ANSELCbits.ANSC3
#define C4_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define C4_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define C4_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define C4_RC3_GetValue()           PORTCbits.RC3
#define C4_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define C4_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define C4_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define C4_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define C4_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define C4_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define C4_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define C4_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set ROWA_RC4 aliases
#define ROWA_RC4_TRIS                 TRISCbits.TRISC4
#define ROWA_RC4_LAT                  LATCbits.LATC4
#define ROWA_RC4_PORT                 PORTCbits.RC4
#define ROWA_RC4_WPU                  WPUCbits.WPUC4
#define ROWA_RC4_OD                   ODCONCbits.ODCC4
#define ROWA_RC4_ANS                  ANSELCbits.ANSC4
#define ROWA_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define ROWA_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define ROWA_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define ROWA_RC4_GetValue()           PORTCbits.RC4
#define ROWA_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define ROWA_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define ROWA_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define ROWA_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define ROWA_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define ROWA_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define ROWA_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define ROWA_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set ROWB_RC5 aliases
#define ROWB_RC5_TRIS                 TRISCbits.TRISC5
#define ROWB_RC5_LAT                  LATCbits.LATC5
#define ROWB_RC5_PORT                 PORTCbits.RC5
#define ROWB_RC5_WPU                  WPUCbits.WPUC5
#define ROWB_RC5_OD                   ODCONCbits.ODCC5
#define ROWB_RC5_ANS                  ANSELCbits.ANSC5
#define ROWB_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define ROWB_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define ROWB_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define ROWB_RC5_GetValue()           PORTCbits.RC5
#define ROWB_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define ROWB_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define ROWB_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define ROWB_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define ROWB_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define ROWB_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define ROWB_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define ROWB_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set ROWC_RC6 aliases
#define ROWC_RC6_TRIS                 TRISCbits.TRISC6
#define ROWC_RC6_LAT                  LATCbits.LATC6
#define ROWC_RC6_PORT                 PORTCbits.RC6
#define ROWC_RC6_WPU                  WPUCbits.WPUC6
#define ROWC_RC6_OD                   ODCONCbits.ODCC6
#define ROWC_RC6_ANS                  ANSELCbits.ANSC6
#define ROWC_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define ROWC_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define ROWC_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define ROWC_RC6_GetValue()           PORTCbits.RC6
#define ROWC_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define ROWC_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define ROWC_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define ROWC_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define ROWC_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define ROWC_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define ROWC_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define ROWC_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set ROWD_RC7 aliases
#define ROWD_RC7_TRIS                 TRISCbits.TRISC7
#define ROWD_RC7_LAT                  LATCbits.LATC7
#define ROWD_RC7_PORT                 PORTCbits.RC7
#define ROWD_RC7_WPU                  WPUCbits.WPUC7
#define ROWD_RC7_OD                   ODCONCbits.ODCC7
#define ROWD_RC7_ANS                  ANSELCbits.ANSC7
#define ROWD_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define ROWD_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define ROWD_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define ROWD_RC7_GetValue()           PORTCbits.RC7
#define ROWD_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define ROWD_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define ROWD_RC7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define ROWD_RC7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define ROWD_RC7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define ROWD_RC7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define ROWD_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define ROWD_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/