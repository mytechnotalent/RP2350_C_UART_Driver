/**
 * FILE: main.c
 *
 * DESCRIPTION:
 * RP2350 Bare-Metal UART Main Application.
 * 
 * BRIEF:
 * Main application entry point for RP2350 UART driver. Contains the
 * main loop that echoes UART input to output.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 2, 2025
 * UPDATE DATE: November 28, 2025
 */

#include "constants.h"
#include "uart.h"

/**
 * @brief   Main application entry point.
 *
 * @details Implements the infinite blink loop.
 *
 * @param   None
 * @retval  None
 */
int main(void)
{
    uint32_t data;
    
    // Loop:
    while (1) {
        // call UART0_In
        data = UART0_In();
        
        // call UART0_Out
        UART0_Out(data);
    }
    
    // should never reach here
    return 0;
}
