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
