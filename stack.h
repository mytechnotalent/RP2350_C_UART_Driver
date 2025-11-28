/**
 * FILE: stack.h
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

#ifndef STACK_H
#define STACK_H

/**
 * @brief   Initialize stack pointers.
 *
 * @details Sets Main and Process Stack Pointers (MSP/PSP) and their limits.
 *
 * @param   None
 * @retval  None
 */
void Init_Stack(void);

#endif /* STACK_H */
