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
