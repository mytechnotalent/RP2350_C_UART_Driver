/**
 * FILE: delay.c
 *
 * DESCRIPTION:
 * RP2350 Delay Functions.
 * 
 * BRIEF:
 * Provides millisecond delay functions based on a 14.5MHz clock.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "delay.h"

void Delay_MS(uint32_t ms)
{
    // Delay_MS_Check:
    // if MS is not valid, return
    if (ms == 0) {
        return;
    }
    
    // Delay_MS_Setup and Loop:
    // Use inline assembly to match the exact timing of assembly version
    __asm__ volatile (
        "mov r4, #3600\n\t"                      // loops per ms
        "mul r5, %0, r4\n\t"                       // r5 = ms * 3600
        "1:\n\t"                                   // label for loop
        "subs r5, #1\n\t"                          // decrement counter
        "bne 1b\n\t"                               // branch if not zero
        :
        : "r" (ms)
        : "r4", "r5", "cc"
    );
}
