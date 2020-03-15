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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

// get/set SER aliases
#define SER_TRIS                 TRISBbits.TRISB4
#define SER_LAT                  LATBbits.LATB4
#define SER_PORT                 PORTBbits.RB4
#define SER_WPU                  WPUBbits.WPUB4
#define SER_OD                   ODCONBbits.ODCB4
#define SER_ANS                  ANSELBbits.ANSB4
#define SER_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SER_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SER_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SER_GetValue()           PORTBbits.RB4
#define SER_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SER_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SER_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SER_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SER_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SER_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SER_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SER_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCLK aliases
#define SCLK_TRIS                 TRISBbits.TRISB5
#define SCLK_LAT                  LATBbits.LATB5
#define SCLK_PORT                 PORTBbits.RB5
#define SCLK_WPU                  WPUBbits.WPUB5
#define SCLK_OD                   ODCONBbits.ODCB5
#define SCLK_ANS                  ANSELBbits.ANSB5
#define SCLK_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SCLK_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SCLK_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SCLK_GetValue()           PORTBbits.RB5
#define SCLK_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SCLK_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SCLK_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SCLK_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SCLK_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SCLK_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SCLK_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SCLK_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RCLK aliases
#define RCLK_TRIS                 TRISBbits.TRISB6
#define RCLK_LAT                  LATBbits.LATB6
#define RCLK_PORT                 PORTBbits.RB6
#define RCLK_WPU                  WPUBbits.WPUB6
#define RCLK_OD                   ODCONBbits.ODCB6
#define RCLK_ANS                  ANSELBbits.ANSB6
#define RCLK_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RCLK_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RCLK_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RCLK_GetValue()           PORTBbits.RB6
#define RCLK_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RCLK_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RCLK_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define RCLK_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define RCLK_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define RCLK_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define RCLK_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define RCLK_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set DHT22_RC0 aliases
#define DHT22_RC0_TRIS                 TRISCbits.TRISC0
#define DHT22_RC0_LAT                  LATCbits.LATC0
#define DHT22_RC0_PORT                 PORTCbits.RC0
#define DHT22_RC0_WPU                  WPUCbits.WPUC0
#define DHT22_RC0_OD                   ODCONCbits.ODCC0
#define DHT22_RC0_ANS                  ANSELCbits.ANSC0
#define DHT22_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DHT22_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DHT22_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DHT22_RC0_GetValue()           PORTCbits.RC0
#define DHT22_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DHT22_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DHT22_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define DHT22_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define DHT22_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define DHT22_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define DHT22_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define DHT22_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SW_RC1 aliases
#define SW_RC1_TRIS                 TRISCbits.TRISC1
#define SW_RC1_LAT                  LATCbits.LATC1
#define SW_RC1_PORT                 PORTCbits.RC1
#define SW_RC1_WPU                  WPUCbits.WPUC1
#define SW_RC1_OD                   ODCONCbits.ODCC1
#define SW_RC1_ANS                  ANSELCbits.ANSC1
#define SW_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SW_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SW_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SW_RC1_GetValue()           PORTCbits.RC1
#define SW_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SW_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SW_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SW_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SW_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SW_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SW_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SW_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

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