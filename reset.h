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
