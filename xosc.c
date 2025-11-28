/**
 * FILE: xosc.c
 *
 * DESCRIPTION:
 * RP2350 External Crystal Oscillator (XOSC) Functions.
 * 
 * BRIEF:
 * Provides functions to initialize the external crystal oscillator
 * and enable the XOSC peripheral clock.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "xosc.h"
#include "constants.h"

void Init_XOSC(void)
{
    // set delay 50,000 cycles
    XOSC->STARTUP = 0x00C4U;
    
    // set 1_15MHz, freq range, actual 14.5MHz
    XOSC->CTRL = 0x00FABAA0U;
    
    // wait until stable bit is set
    while ((XOSC->STATUS & (1U << XOSC_STATUS_STABLE_SHIFT)) == 0) {
        // wait
    }
}

void Enable_XOSC_Peri_Clock(void)
{
    uint32_t value;
    
    // read CLK_PERI_CTRL value
    value = CLOCKS->CLK_PERI_CTRL;
    
    // set ENABLE bit
    value |= (1U << CLOCKS_CLK_PERI_CTRL_ENABLE_SHIFT);
    
    // set AUXSRC: XOSC_CLKSRC
    value |= (CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC << CLOCKS_CLK_PERI_CTRL_AUXSRC_SHIFT);
    
    // store value into CLK_PERI_CTRL
    CLOCKS->CLK_PERI_CTRL = value;
}
