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

/**
 * UART0 base address.
 */
#define UART0_BASE 0x40070000U

#endif /* CONSTANTS_H */
