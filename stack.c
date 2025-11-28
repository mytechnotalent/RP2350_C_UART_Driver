/**
 * FILE: stack.c
 *
 * DESCRIPTION:
 * RP2350 Stack Initialization.
 * 
 * BRIEF:
 * Provides stack pointer initialization for Main and Process Stack
 * Pointers (MSP/PSP) and their limits.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "stack.h"
#include "constants.h"

void Init_Stack(void)
{
    __asm__ volatile (
        "ldr   r0, =%0\n\t"         // load stack top
        "msr   PSP, r0\n\t"         // set PSP
        "ldr   r0, =%1\n\t"         // load stack limit
        "msr   MSPLIM, r0\n\t"      // set MSP limit
        "msr   PSPLIM, r0\n\t"      // set PSP limit
        "ldr   r0, =%0\n\t"         // reload stack top
        "msr   MSP, r0\n\t"         // set MSP
        :
        : "i" (STACK_TOP), "i" (STACK_LIMIT)
        : "r0"
    );
}
