/**
 * FILE: uart.c
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
 * UPDATE DATE: November 28, 2025
 */

#include "uart.h"
#include "constants.h"

void UART_Release_Reset(void)
{
    volatile uint32_t *reset_reg = &RESETS->RESET;
    volatile uint32_t *reset_done_reg = &RESETS->RESET_DONE;
    uint32_t value;
    
    // load RESETS->RESET address and read value
    value = *reset_reg;
    
    // clear UART0 reset bit (bit 26)
    value &= ~(1U << 26);
    
    // write value back to RESETS->RESET
    *reset_reg = value;
    
    // UART_Release_Reset_Wait:
    // loop until UART0 is out of reset
    while (1)
    {
        value = *reset_done_reg;
        
        // test UART0 reset-done bit (bit 26)
        if (value & (1U << 26))
        {
            break;
        }
    }
}

void UART_Init(void)
{
    volatile uint32_t *gpio0_ctrl;
    volatile uint32_t *gpio1_ctrl;
    volatile uint32_t *pad0_reg;
    volatile uint32_t *pad1_reg;
    volatile uint32_t *uart_base = (volatile uint32_t *)UART0_BASE;
    uint32_t value;
    
    // Configure IO_BANK0 pins 0 (TX) and 1 (RX) to UART function
    gpio0_ctrl = &IO_BANK0->GPIO0.CTRL;
    gpio1_ctrl = &IO_BANK0->GPIO1.CTRL;
    
    // FUNCSEL = 2 -> select UART function
    *gpio0_ctrl = 2;  // GPIO0_CTRL (pin0 -> TX)
    *gpio1_ctrl = 2;  // GPIO1_CTRL (pin1 -> RX)
    
    // Configure pad controls in PADS_BANK0
    pad0_reg = &PADS_BANK0->GPIO0;  // PAD[0] address
    pad1_reg = &PADS_BANK0->GPIO1;  // PAD[1] address
    
    // pad config value for TX (pull/func recommended)
    *pad0_reg = 0x04;
    
    // pad config value for RX (pulldown/IE as needed)
    *pad1_reg = 0x40;
    
    // Disable UART while configuring
    uart_base[0x30 / 4] = 0;  // UARTCR = 0
    
    // Set baud rate divisors
    uart_base[0x24 / 4] = 6;   // UARTIBRD = 6 (integer baud divisor)
    uart_base[0x28 / 4] = 33;  // UARTFBRD = 33 (fractional baud divisor)
    
    // Configure line control: FIFO enable + 8-bit
    uart_base[0x2C / 4] = 112;  // UARTLCR_H = 0x70
    
    // Enable UART with TX and RX enabled
    // RXE/TXE in bits 8..9, UARTEN in bit 0
    value = (3U << 8) | 1U;
    uart_base[0x30 / 4] = value;  // UARTCR = enable (UARTEN + TXE + RXE)
}

void UART0_Out(uint32_t data)
{
    volatile uint32_t *uart_base = (volatile uint32_t *)UART0_BASE;
    uint32_t flags;
    
    // UART0_Out_loop:
    // Wait for TX FIFO to be not full
    while (1)
    {
        // read UART0 flag register UARTFR
        flags = uart_base[0x18 / 4];
        
        // test bit 5, TX FIFO full (TXFF)
        if ((flags & 32) == 0)
        {
            break;  // TX FIFO is not full, exit loop
        }
    }
    
    // mask off upper bits, keep lower 8 bits
    data &= 0xFF;
    
    // write data to UARTDR
    uart_base[0] = data;
}

uint32_t UART0_In(void)
{
    volatile uint32_t *uart_base = (volatile uint32_t *)UART0_BASE;
    uint32_t flags;
    uint32_t data;
    
    // UART0_In_loop:
    // Wait for RX FIFO to be not empty
    while (1)
    {
        // read UART0 flag register UARTFR
        flags = uart_base[0x18 / 4];
        
        // test bit 4, RX FIFO empty (RXFE)
        if ((flags & 16) == 0)
        {
            break;  // RX FIFO is not empty, exit loop
        }
    }
    
    // load data from UARTDR
    data = uart_base[0];
    
    return data;
}
