/**
 * FILE: vector_table.c
 *
 * DESCRIPTION:
 * RP2350 Vector Table.
 * 
 * BRIEF:
 * Defines the vector table for the RP2350 containing the initial
 * stack pointer and reset handler entry point.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include <stdint.h>

extern uint32_t _stack_top;
extern void Reset_Handler(void);

// Define vector table type
typedef void (*vector_func_t)(void);

/**
 * Vector table section.
 * Note: The Thumb bit (bit 0 = 1) is automatically set by the linker
 * for function pointers in Thumb mode, so we can use the function directly.
 */
__attribute__((section(".vectors"), used))
const void *_vectors[2] = {
    &_stack_top,                                 // initial stack pointer
    Reset_Handler                                // reset handler (Thumb bit automatic)
};
