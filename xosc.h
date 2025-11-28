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
