#include "Push_button.h"
/* 
 * @file  Push_button.h
 * @brief handles the push button control
 * @author gavin lyons
 * @note requires timer on ~5mS tick to set gPushButtonEvent event flag
 */

bool gPushButtonEvent = false;

/*!
 @brief Routine to debounce push button RC4
 Updated every by a timer interrupt.
 @return True if putton pressed and debounced
 @note Soucre ::  http://www.ganssle.com/debouncing.htm 
 */
bool DebounceSwitchRC4(void)
{
    static uint16_t State = 0;
    State = (State <<1) | !BTN_RC4_GetValue() | 0xE000;
    if (State==0xF000)
        return true;
    else
        return false;
}
