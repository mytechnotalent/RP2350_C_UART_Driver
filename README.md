<img src="https://github.com/mytechnotalent/RP2350_C_UART_Driver/blob/main/RP2350_C_UART_Driver.png?raw=true">

## FREE Reverse Engineering Self-Study Course [HERE](https://github.com/mytechnotalent/Reverse-Engineering-Tutorial)
### VIDEO PROMO [HERE](https://www.youtube.com/watch?v=aD7X9sXirF8)

<br>

# RP2350 C UART Driver
An RP2350 C UART driver written entirely in bare-metal C.

<br>

# Install ARM Toolchain
## NOTE: Be SURE to select `Add path to environment variable` on setup.
[HERE](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)

<br>

# Hardware
## Raspberry Pi Pico 2 w/ Header [BUY](https://www.pishop.us/product/raspberry-pi-pico-2-with-header)
## USB A-Male to USB Micro-B Cable [BUY](https://www.pishop.us/product/usb-a-male-to-usb-micro-b-cable-6-inches)
## Raspberry Pi Pico Debug Probe [BUY](https://www.pishop.us/product/raspberry-pi-debug-probe)
## Complete Component Kit for Raspberry Pi [BUY](https://www.pishop.us/product/complete-component-kit-for-raspberry-pi)
## 10pc 25v 1000uF Capacitor [BUY](https://www.amazon.com/Cionyce-Capacitor-Electrolytic-CapacitorsMicrowave/dp/B0B63CCQ2N?th=1)
### 10% PiShop DISCOUNT CODE - KVPE_HS320548_10PC

<br>

# Build
```
.\build.bat
```

<br>

# Clean
```
.\clean.bat
```

<br>

# constants.h Code
```c
   /**
 * FILE: constants.h
 *
 * DESCRIPTION:
 * RP2350 Memory Addresses and Hardware Register Structures.
 * 
 * BRIEF:
 * Defines all memory-mapped register structures and peripheral base
 * addresses used throughout the RP2350 Blink driver.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

/**
 * Stack addresses.
 */
#define STACK_TOP   0x20082000U
#define STACK_LIMIT 0x2007A000U

/**
 * XOSC (External Crystal Oscillator) Register Structure.
 */
typedef struct {
    volatile uint32_t CTRL;        /**< 0x00: Control register */
    volatile uint32_t STATUS;      /**< 0x04: Status register */
    volatile uint32_t DORMANT;     /**< 0x08: Dormant mode */
    volatile uint32_t STARTUP;     /**< 0x0C: Startup delay */
    volatile uint32_t RESERVED[3]; /**< 0x10-0x18: Reserved */
    volatile uint32_t COUNT;       /**< 0x1C: Frequency count */
} xosc_hw_t;

/**
 * XOSC base address and pointer.
 */
#define XOSC_BASE 0x40048000U
#define XOSC      ((xosc_hw_t *)XOSC_BASE)

/**
 * XOSC status bit definitions.
 */
#define XOSC_STATUS_STABLE_SHIFT 31U

/**
 * CPACR (Coprocessor Access Control Register) in PPB.
 */
#define PPB_BASE 0xE0000000U
#define CPACR    ((volatile uint32_t *)(PPB_BASE + 0x0ED88U))

/**
 * Coprocessor access control bit definitions.
 */
#define CPACR_CP0_SHIFT 0U
#define CPACR_CP1_SHIFT 1U

/**
 * CLOCKS Register Structure.
 */
typedef struct {
    volatile uint32_t RESERVED0[18]; /**< 0x00-0x44: Other clock registers */
    volatile uint32_t CLK_PERI_CTRL; /**< 0x48: Peripheral clock control */
} clocks_hw_t;

/**
 * CLOCKS base address and pointer.
 */
#define CLOCKS_BASE 0x40010000U
#define CLOCKS      ((clocks_hw_t *)CLOCKS_BASE)

/**
 * Clock control bit definitions.
 */
#define CLOCKS_CLK_PERI_CTRL_ENABLE_SHIFT 11U
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_SHIFT 5U
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC  4U

/**
 * RESETS Register Structure.
 */
typedef struct {
    volatile uint32_t RESET;      /**< 0x00: Reset control */
    volatile uint32_t WDSEL;      /**< 0x04: Watchdog select */
    volatile uint32_t RESET_DONE; /**< 0x08: Reset done status */
} resets_hw_t;

/**
 * RESETS base address and pointer.
 */
#define RESETS_BASE        0x40020000U
#define RESETS             ((resets_hw_t *)RESETS_BASE)
#define RESETS_RESET_CLEAR ((volatile uint32_t *)(RESETS_BASE + 0x3000U))

/**
 * Reset control bit definitions.
 */
#define RESETS_RESET_IO_BANK0_SHIFT 6U

/**
 * IO_BANK0 GPIO Control Register (one per GPIO).
 */
typedef struct {
    volatile uint32_t STATUS; /**< 0x00: GPIO status */
    volatile uint32_t CTRL;   /**< 0x04: GPIO control */
} io_bank0_gpio_ctrl_t;

/**
 * IO_BANK0 Register Structure.
 */
typedef struct {
    io_bank0_gpio_ctrl_t GPIO0;  /**< 0x000: GPIO 0 */
    io_bank0_gpio_ctrl_t GPIO1;  /**< 0x008: GPIO 1 */
    io_bank0_gpio_ctrl_t GPIO2;  /**< 0x010: GPIO 2 */
    io_bank0_gpio_ctrl_t GPIO3;  /**< 0x018: GPIO 3 */
    io_bank0_gpio_ctrl_t GPIO4;  /**< 0x020: GPIO 4 */
    io_bank0_gpio_ctrl_t GPIO5;  /**< 0x028: GPIO 5 */
    io_bank0_gpio_ctrl_t GPIO6;  /**< 0x030: GPIO 6 */
    io_bank0_gpio_ctrl_t GPIO7;  /**< 0x038: GPIO 7 */
    io_bank0_gpio_ctrl_t GPIO8;  /**< 0x040: GPIO 8 */
    io_bank0_gpio_ctrl_t GPIO9;  /**< 0x048: GPIO 9 */
    io_bank0_gpio_ctrl_t GPIO10; /**< 0x050: GPIO 10 */
    io_bank0_gpio_ctrl_t GPIO11; /**< 0x058: GPIO 11 */
    io_bank0_gpio_ctrl_t GPIO12; /**< 0x060: GPIO 12 */
    io_bank0_gpio_ctrl_t GPIO13; /**< 0x068: GPIO 13 */
    io_bank0_gpio_ctrl_t GPIO14; /**< 0x070: GPIO 14 */
    io_bank0_gpio_ctrl_t GPIO15; /**< 0x078: GPIO 15 */
    io_bank0_gpio_ctrl_t GPIO16; /**< 0x080: GPIO 16 */
    io_bank0_gpio_ctrl_t GPIO17; /**< 0x088: GPIO 17 */
    io_bank0_gpio_ctrl_t GPIO18; /**< 0x090: GPIO 18 */
    io_bank0_gpio_ctrl_t GPIO19; /**< 0x098: GPIO 19 */
    io_bank0_gpio_ctrl_t GPIO20; /**< 0x0A0: GPIO 20 */
    io_bank0_gpio_ctrl_t GPIO21; /**< 0x0A8: GPIO 21 */
    io_bank0_gpio_ctrl_t GPIO22; /**< 0x0B0: GPIO 22 */
    io_bank0_gpio_ctrl_t GPIO23; /**< 0x0B8: GPIO 23 */
    io_bank0_gpio_ctrl_t GPIO24; /**< 0x0C0: GPIO 24 */
    io_bank0_gpio_ctrl_t GPIO25; /**< 0x0C8: GPIO 25 */
    io_bank0_gpio_ctrl_t GPIO26; /**< 0x0D0: GPIO 26 */
    io_bank0_gpio_ctrl_t GPIO27; /**< 0x0D8: GPIO 27 */
    io_bank0_gpio_ctrl_t GPIO28; /**< 0x0E0: GPIO 28 */
    io_bank0_gpio_ctrl_t GPIO29; /**< 0x0E8: GPIO 29 */
} io_bank0_hw_t;

/**
 * IO_BANK0 base address and pointer.
 */
#define IO_BANK0_BASE 0x40028000U
#define IO_BANK0      ((io_bank0_hw_t *)IO_BANK0_BASE)

/**
 * GPIO control bit definitions.
 */
#define IO_BANK0_CTRL_FUNCSEL_MASK 0x1FU
#define IO_BANK0_CTRL_FUNCSEL_SIO  0x05U

/**
 * PADS_BANK0 Pad Control Register (one per GPIO).
 */
typedef struct {
    volatile uint32_t VOLTAGE_SELECT; /**< 0x00: Voltage select */
    volatile uint32_t GPIO0;          /**< 0x04: GPIO 0 pad control */
    volatile uint32_t GPIO1;          /**< 0x08: GPIO 1 pad control */
    volatile uint32_t GPIO2;          /**< 0x0C: GPIO 2 pad control */
    volatile uint32_t GPIO3;          /**< 0x10: GPIO 3 pad control */
    volatile uint32_t GPIO4;          /**< 0x14: GPIO 4 pad control */
    volatile uint32_t GPIO5;          /**< 0x18: GPIO 5 pad control */
    volatile uint32_t GPIO6;          /**< 0x1C: GPIO 6 pad control */
    volatile uint32_t GPIO7;          /**< 0x20: GPIO 7 pad control */
    volatile uint32_t GPIO8;          /**< 0x24: GPIO 8 pad control */
    volatile uint32_t GPIO9;          /**< 0x28: GPIO 9 pad control */
    volatile uint32_t GPIO10;         /**< 0x2C: GPIO 10 pad control */
    volatile uint32_t GPIO11;         /**< 0x30: GPIO 11 pad control */
    volatile uint32_t GPIO12;         /**< 0x34: GPIO 12 pad control */
    volatile uint32_t GPIO13;         /**< 0x38: GPIO 13 pad control */
    volatile uint32_t GPIO14;         /**< 0x3C: GPIO 14 pad control */
    volatile uint32_t GPIO15;         /**< 0x40: GPIO 15 pad control */
    volatile uint32_t GPIO16;         /**< 0x44: GPIO 16 pad control */
    volatile uint32_t GPIO17;         /**< 0x48: GPIO 17 pad control */
    volatile uint32_t GPIO18;         /**< 0x4C: GPIO 18 pad control */
    volatile uint32_t GPIO19;         /**< 0x50: GPIO 19 pad control */
    volatile uint32_t GPIO20;         /**< 0x54: GPIO 20 pad control */
    volatile uint32_t GPIO21;         /**< 0x58: GPIO 21 pad control */
    volatile uint32_t GPIO22;         /**< 0x5C: GPIO 22 pad control */
    volatile uint32_t GPIO23;         /**< 0x60: GPIO 23 pad control */
    volatile uint32_t GPIO24;         /**< 0x64: GPIO 24 pad control */
    volatile uint32_t GPIO25;         /**< 0x68: GPIO 25 pad control */
    volatile uint32_t GPIO26;         /**< 0x6C: GPIO 26 pad control */
    volatile uint32_t GPIO27;         /**< 0x70: GPIO 27 pad control */
    volatile uint32_t GPIO28;         /**< 0x74: GPIO 28 pad control */
    volatile uint32_t GPIO29;         /**< 0x78: GPIO 29 pad control */
} pads_bank0_hw_t;

/**
 * PADS_BANK0 base address and pointer.
 */
#define PADS_BANK0_BASE 0x40038000U
#define PADS_BANK0      ((pads_bank0_hw_t *)PADS_BANK0_BASE)

/**
 * Pad control bit definitions.
 */
#define PADS_BANK0_OD_SHIFT  7U
#define PADS_BANK0_IE_SHIFT  6U
#define PADS_BANK0_ISO_SHIFT 8U

/**
 * GPIO pin definitions.
 */
#define GPIO16_NUM 16U

#endif /* CONSTANTS_H */              
```

<br>

# vector_table.c Code
```c
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
```

<br>

# stack.h Code
```c
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
```

<br>

# stack.c Code
```c
/**
 * FILE: reset.c
 *
 * DESCRIPTION:
 * RP2350 Reset Controller Functions.
 * 
 * BRIEF:
 * Provides functions to initialize subsystems by clearing their
 * reset bits in the Reset controller.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "reset.h"
#include "constants.h"

void Init_Subsystem(void)
{
    uint32_t value;
    
    // GPIO_Subsystem_Reset:
    // read RESETS->RESET value
    value = RESETS->RESET;
    
    // clear IO_BANK0 bit
    value &= ~(1U << RESETS_RESET_IO_BANK0_SHIFT);
    
    // store value into RESETS->RESET address
    RESETS->RESET = value;
    
    // GPIO_Subsystem_Reset_Wait:
    // wait until done
    while ((RESETS->RESET_DONE & (1U << RESETS_RESET_IO_BANK0_SHIFT)) == 0) {
        // wait
    }
}
```

<br>

# xosc.h Code
```c
/**
 * FILE: xosc.h
 *
 * DESCRIPTION:
 * RP2350 External Crystal Oscillator (XOSC) Functions.
 * 
 * BRIEF:
 * Provides functions to initialize the external crystal oscillator
 * and enable the XOSC peripheral clock.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#ifndef XOSC_H
#define XOSC_H

/**
 * @brief   Init XOSC and wait until it is ready.
 *
 * @details Configures and initializes the external crystal oscillator (XOSC).
 *          Waits for the XOSC to become stable before returning.
 *
 * @param   None
 * @retval  None
 */
void Init_XOSC(void);

/**
 * @brief   Enable XOSC peripheral clock.
 *
 * @details Sets the peripheral clock to use XOSC as its AUXSRC.
 *
 * @param   None
 * @retval  None
 */
void Enable_XOSC_Peri_Clock(void);

#endif /* XOSC_H */
```

<br>

# xosc.c Code
```c
/**
 * FILE: xosc.c
 *
 * DESCRIPTION:
 * RP2350 External Crystal Oscillator (XOSC) Functions.
 * 
 * BRIEF:
 * Provides functions to initialize the external crystal oscillator
 * and enable the XOSC peripheral clock.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "xosc.h"
#include "constants.h"

void Init_XOSC(void)
{
    // set delay 50,000 cycles
    XOSC->STARTUP = 0x00C4U;
    
    // set 1_15MHz, freq range, actual 14.5MHz
    XOSC->CTRL = 0x00FABAA0U;
    
    // wait until stable bit is set
    while ((XOSC->STATUS & (1U << XOSC_STATUS_STABLE_SHIFT)) == 0) {
        // wait
    }
}

void Enable_XOSC_Peri_Clock(void)
{
    uint32_t value;
    
    // read CLK_PERI_CTRL value
    value = CLOCKS->CLK_PERI_CTRL;
    
    // set ENABLE bit
    value |= (1U << CLOCKS_CLK_PERI_CTRL_ENABLE_SHIFT);
    
    // set AUXSRC: XOSC_CLKSRC
    value |= (CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC << CLOCKS_CLK_PERI_CTRL_AUXSRC_SHIFT);
    
    // store value into CLK_PERI_CTRL
    CLOCKS->CLK_PERI_CTRL = value;
}
```

<br>

# reset.h Code
```c
/**
 * FILE: reset.h
 *
 * DESCRIPTION:
 * RP2350 Reset Controller Functions.
 * 
 * BRIEF:
 * Provides functions to initialize subsystems by clearing their
 * reset bits in the Reset controller.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#ifndef RESET_H
#define RESET_H

/**
 * @brief   Init subsystem.
 *
 * @details Initiates the various subsystems by clearing their reset bits.
 *
 * @param   None
 * @retval  None
 */
void Init_Subsystem(void);

#endif /* RESET_H */
```

<br>

# reset.c Code
```c
/**
 * FILE: reset.c
 *
 * DESCRIPTION:
 * RP2350 Reset Controller Functions.
 * 
 * BRIEF:
 * Provides functions to initialize subsystems by clearing their
 * reset bits in the Reset controller.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "reset.h"
#include "constants.h"

void Init_Subsystem(void)
{
    uint32_t value;
    
    // GPIO_Subsystem_Reset:
    // read RESETS->RESET value
    value = RESETS->RESET;
    
    // clear IO_BANK0 bit
    value &= ~(1U << RESETS_RESET_IO_BANK0_SHIFT);
    
    // store value into RESETS->RESET address
    RESETS->RESET = value;
    
    // GPIO_Subsystem_Reset_Wait:
    // wait until done
    while ((RESETS->RESET_DONE & (1U << RESETS_RESET_IO_BANK0_SHIFT)) == 0) {
        // wait
    }
}
```

<br>

# coprocessor.h Code
```c
/**
 * FILE: coprocessor.h
 *
 * DESCRIPTION:
 * RP2350 Coprocessor Access Functions.
 * 
 * BRIEF:
 * Provides functions to enable coprocessor access control.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#ifndef COPROCESSOR_H
#define COPROCESSOR_H

/**
 * @brief   Enable coprocessor access.
 *
 * @details Grants full access to coprocessor 0 via CPACR.
 *
 * @param   None
 * @retval  None
 */
void Enable_Coprocessor(void);

#endif /* COPROCESSOR_H */
```

<br>


# coprocessor.c Code
```c
/**
 * FILE: coprocessor.c
 *
 * DESCRIPTION:
 * RP2350 Coprocessor Access Functions.
 * 
 * BRIEF:
 * Provides functions to enable coprocessor access control.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include "coprocessor.h"
#include "constants.h"

/**
 * @brief   Enable coprocessor access.
 *
 * @details Grants full access to coprocessor 0 via CPACR.
 *
 * @param   None
 * @retval  None
 */
void Enable_Coprocessor(void)
{
    uint32_t value;
    
    // read CPACR value
    value = *CPACR;
    
    // set CP1: Ctrl access priv coproc 1 bit
    value |= (1U << CPACR_CP1_SHIFT);
    
    // set CP0: Ctrl access priv coproc 0 bit
    value |= (1U << CPACR_CP0_SHIFT);
    
    // store value into CPACR
    *CPACR = value;
    
    // data sync barrier
    __asm__ volatile ("dsb");
    
    // instruction sync barrier
    __asm__ volatile ("isb");
}
```

<br>

# gpio.h Code
```c
/**
 * FILE: gpio.h
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

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/**
 * @brief   Configure GPIO.
 *
 * @details Configures a GPIO pin's pad control and function select.
 *
 * @param   gpio_num - GPIO pin number (0-29)
 * @retval  None
 */
void GPIO_Config(uint32_t gpio_num);

/**
 * @brief   GPIO set.
 *
 * @details Drives GPIO output high via coprocessor.
 *
 * @param   gpio_num - GPIO pin number
 * @retval  None
 */
void GPIO_Set(uint32_t gpio_num);

/**
 * @brief   GPIO clear.
 *
 * @details Drives GPIO output low via coprocessor.
 *
 * @param   gpio_num - GPIO pin number
 * @retval  None
 */
void GPIO_Clear(uint32_t gpio_num);

#endif /* GPIO_H */
```

<br>

# gpio.c Code
```c
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
```

<br>

# delay.h Code
```c
/**
 * FILE: delay.h
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

#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>

/**
 * @brief   Delay_MS.
 *
 * @details Delays for ms milliseconds. Conversion: loop_count = ms * 3600
 *          based on a 14.5MHz clock.
 *
 * @param   ms - milliseconds
 * @retval  None
 */
void Delay_MS(uint32_t ms);

#endif /* DELAY_H */
```

<br>

# delay.c Code
```c
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
```

<br>

# reset_handler.h Code
```c
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
```

<br>

# reset_handler.c Code
```c
/**
 * FILE: reset_handler.c
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

#include "reset_handler.h"
#include "stack.h"
#include "xosc.h"
#include "reset.h"
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
        "bl Enable_Coprocessor\n\t"
        "b main\n\t"
    );
}
```

<br>

# uart.h Code
```c
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
```

<br>

# uart.c Code
```c
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
```

<br>

# main.c Code
```c
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
```

<br>

# License
[Apache License 2.0](https://github.com/mytechnotalent/RP2350_C_UART_Driver/blob/main/LICENSE)
