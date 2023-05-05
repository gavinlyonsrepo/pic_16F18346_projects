/* 
 * @file  Push_button.h
 * @brief handles the push button control
 * @author gavin lyons
 * @note requires timer on ~5mS tick to set gPushButtonEvent event flag
 */

#include "mcc_generated_files/mcc.h"

#ifndef PUSH_BUTTON_H
#define	PUSH_BUTTON_H

#ifdef	__cplusplus
extern "C" {
#endif

extern bool gPushButtonEvent; /**< Flag to hold status of push button, true for pressed*/

bool DebounceSwitchRC4(void);


#ifdef	__cplusplus
}
#endif

#endif	/* PUSH_BUTTON_H */

