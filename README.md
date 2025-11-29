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
