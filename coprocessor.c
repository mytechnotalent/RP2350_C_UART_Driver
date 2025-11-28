/**
 * FILE: coprocessor.c
 *
 * DESCRIPTION:
 * RP2350 Coprocessor Access Functions.
 * 
 * BRIEF:
 * Provides functions to enable coprocessor access control.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "coprocessor.h"
#include "constants.h"

/**
 * @brief   Enable coprocessor access.
 *
 * @details Grants full access to coprocessor 0 via CPACR.
 *
 * @param   None
 * @retval  None
 */
void Enable_Coprocessor(void)
{
    uint32_t value;
    
    // read CPACR value
    value = *CPACR;
    
    // set CP1: Ctrl access priv coproc 1 bit
    value |= (1U << CPACR_CP1_SHIFT);
    
    // set CP0: Ctrl access priv coproc 0 bit
    value |= (1U << CPACR_CP0_SHIFT);
    
    // store value into CPACR
    *CPACR = value;
    
    // data sync barrier
    __asm__ volatile ("dsb");
    
    // instruction sync barrier
    __asm__ volatile ("isb");
}
