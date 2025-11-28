/**
 * FILE: uart.h
 *
 * DESCRIPTION:
 * RP2350 UART Functions.
 * 
 * BRIEF:
 * Provides UART initialization, transmit, and receive functions for
 * UART0 on the RP2350.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#ifndef UART_H
#define UART_H

#include <stdint.h>

/**
 * @brief   Release UART0 from reset and wait until it is ready.
 *
 * @details Clears the UART0 reset bit in the Reset controller (RESETS->RESET)
 *          and polls the corresponding bit in RESETS->RESET_DONE until the
 *          UART0 block is no longer in reset. This ensures UART registers are
 *          accessible before configuring the peripheral.
 *
 * @param   None
 * @retval  None
 */
void UART_Release_Reset(void);

/**
 * @brief   Initialize UART0 (pins, baud divisors, line control and enable).
 *
 * @details Configures IO_BANK0 pins 0 (TX) and 1 (RX) to the UART function
 *          and programs the corresponding pad controls in PADS_BANK0. It
 *          programs the integer and fractional baud divisors (UARTIBRD and
 *          UARTFBRD), configures UARTLCR_H for 8-bit transfers and FIFOs,
 *          and enables the UART (UARTCR: UARTEN + TXE + RXE).
 *          The routine assumes the UART0 base is available at the
 *          `UART0_BASE` symbol. The selected divisors (IBRD=6, FBRD=33) are
 *          chosen to match the expected peripheral clock; if your UART
 *          peripheral clock differs, adjust these values accordingly.
 *
 * @param   None
 * @retval  None
 */
void UART_Init(void);

/**
 * @brief   UART0 transmit (blocking).
 *
 * @details Waits for TX FIFO to be not full, then writes the lowest 8 bits of r0 to UART0.
 *          Data to send must be in r0 on entry.
 *
 * @param   data - byte to transmit (lower 8 bits used)
 * @retval  None
 */
void UART0_Out(uint32_t data);

/**
 * @brief   UART0 receive (blocking).
 *
 * @details Waits for RX FIFO to be not empty, then reads a byte from UART0 into r0.
 *
 * @param   None
 * @retval  received byte (lower 8 bits valid)
 */
uint32_t UART0_In(void);

#endif /* UART_H */
