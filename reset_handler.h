/**
 * FILE: reset_handler.h
 *
 * DESCRIPTION:
 * RP2350 Reset Handler.
 * 
 * BRIEF:
 * Entry point after reset. Performs initialization sequence including
 * stack setup, oscillator configuration, and subsystem initialization 
 * before branching to main application.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#ifndef RESET_HANDLER_H
#define RESET_HANDLER_H

/**
 * @brief   Reset handler for RP2350.
 *
 * @details Entry point after reset. Performs:
 *          - Stack initialization
 *          - Coprocessor enable
 *          - GPIO16 pad/function configuration
 *          - Branches to main() which contains the blink loop
 *
 * @param   None
 * @retval  None
 */
void Reset_Handler(void) __attribute__((noreturn));

#endif /* RESET_HANDLER_H */
