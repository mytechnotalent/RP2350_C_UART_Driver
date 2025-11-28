/**
 * FILE: reset.c
 *
 * DESCRIPTION:
 * RP2350 Reset Controller Functions.
 * 
 * BRIEF:
 * Provides functions to initialize subsystems by clearing their
 * reset bits in the Reset controller.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "reset.h"
#include "constants.h"

void Init_Subsystem(void)
{
    uint32_t value;
    
    // GPIO_Subsystem_Reset:
    // read RESETS->RESET value
    value = RESETS->RESET;
    
    // clear IO_BANK0 bit
    value &= ~(1U << RESETS_RESET_IO_BANK0_SHIFT);
    
    // store value into RESETS->RESET address
    RESETS->RESET = value;
    
    // GPIO_Subsystem_Reset_Wait:
    // wait until done
    while ((RESETS->RESET_DONE & (1U << RESETS_RESET_IO_BANK0_SHIFT)) == 0) {
        // wait
    }
}
