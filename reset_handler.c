/**
 * FILE: reset_handler.c
 *
 * DESCRIPTION:
 * RP2350 Reset Handler.
 * 
 * BRIEF:
 * Entry point after reset. Performs initialization sequence including
 * stack setup, oscillator configuration, subsystem initialization, and
 * UART setup before branching to main application.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 28, 2025
 */

#include "reset_handler.h"
#include "stack.h"
#include "xosc.h"
#include "reset.h"
#include "uart.h"
#include "coprocessor.h"

// Forward declaration of main
extern int main(void);

void __attribute__((naked, noreturn)) Reset_Handler(void)
{
    __asm__ volatile (
        "bl Init_Stack\n\t"
        "bl Init_XOSC\n\t"
        "bl Enable_XOSC_Peri_Clock\n\t"
        "bl Init_Subsystem\n\t"
        "bl UART_Release_Reset\n\t"
        "bl UART_Init\n\t"
        "bl Enable_Coprocessor\n\t"
        "b main\n\t"
    );
}
