/**
 * FILE: gpio.c
 *
 * DESCRIPTION:
 * RP2350 GPIO Functions.
 * 
 * BRIEF:
 * Provides GPIO configuration, set, and clear functions using
 * coprocessor instructions.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "gpio.h"
#include "constants.h"

void GPIO_Config(uint32_t gpio_num)
{
    volatile uint32_t *pad_reg;
    volatile uint32_t *ctrl_reg;
    uint32_t value;
    
    // GPIO_Config_Modify_Pad:
    // Get pad register for GPIO16
    pad_reg = &PADS_BANK0->GPIO16;
    
    // read PAD value
    value = *pad_reg;
    
    // clear OD bit (output disable)
    value &= ~(1U << PADS_BANK0_OD_SHIFT);
    
    // set IE bit (input enable)
    value |= (1U << PADS_BANK0_IE_SHIFT);
    
    // clear ISO bit (isolate)
    value &= ~(1U << PADS_BANK0_ISO_SHIFT);
    
    // store value into PAD
    *pad_reg = value;
    
    // GPIO_Config_Modify_CTRL:
    // Get control register for GPIO16
    ctrl_reg = &IO_BANK0->GPIO16.CTRL;
    
    // read CTRL value
    value = *ctrl_reg;
    
    // clear FUNCSEL bits
    value &= ~IO_BANK0_CTRL_FUNCSEL_MASK;
    
    // set FUNCSEL to SIO (0x05)
    value |= IO_BANK0_CTRL_FUNCSEL_SIO;
    
    // store value into CTRL
    *ctrl_reg = value;
    
    // GPIO_Config_Enable_OE:
    // enable output using coprocessor
    // gpioc_bit_oe_put(GPIO, 1)
    __asm__ volatile (
        "push {r4-r12, lr}\n\t"
        "mov r4, #1\n\t"
        "mcrr p0, #4, %0, r4, c4\n\t"
        "pop {r4-r12, lr}\n\t"
        :
        : "r" (gpio_num)
        : "r4"
    );
}

void GPIO_Set(uint32_t gpio_num)
{
    // GPIO_Set_Execute:
    // enable output
    // gpioc_bit_out_put(GPIO, 1)
    __asm__ volatile (
        "push {r4-r12, lr}\n\t"
        "mov r4, #1\n\t"
        "mcrr p0, #4, %0, r4, c0\n\t"
        "pop {r4-r12, lr}\n\t"
        :
        : "r" (gpio_num)
        : "r4"
    );
}

void GPIO_Clear(uint32_t gpio_num)
{
    // GPIO_Clear_Execute:
    // disable output
    // gpioc_bit_out_put(GPIO, 0)
    __asm__ volatile (
        "push {r4-r12, lr}\n\t"
        "mov r4, #0\n\t"
        "mcrr p0, #4, %0, r4, c0\n\t"
        "pop {r4-r12, lr}\n\t"
        :
        : "r" (gpio_num)
        : "r4"
    );
}
