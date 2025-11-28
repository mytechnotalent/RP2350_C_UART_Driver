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
