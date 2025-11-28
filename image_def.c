/**
 * FILE: image_def.c
 *
 * DESCRIPTION:
 * RP2350 IMAGE_DEF Block.
 * 
 * BRIEF:
 * A minimum amount of metadata (a valid IMAGE_DEF block) must be embedded in any
 * binary for the bootrom to recognise it as a valid program image, as opposed to,
 * for example, blank flash contents or a disconnected flash device. This must
 * appear within the first 4 kB of a flash image, or anywhere in a RAM or OTP image.
 * Unlike RP2040, there is no requirement for flash binaries to have a checksummed
 * "boot2" flash setup function at flash address 0. The RP2350 bootrom performs a
 * simple best-effort XIP setup during flash scanning, and a flash-resident program
 * can continue executing in this state, or can choose to reconfigure the QSPI
 * interface at a later time for best performance.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

#include <stdint.h>

/**
 * IMAGE_DEF block structure placed in flash.
 * Must match the exact byte layout from the assembly version.
 */
__attribute__((section(".embedded_block"), used))
const uint8_t picobin_block[] = {
    // PICOBIN_BLOCK_MARKER_START (word: 0xffffded3)
    0xD3, 0xDE, 0xFF, 0xFF,
    
    // PICOBIN_BLOCK_ITEM_1BS_IMAGE_TYPE (byte: 0x42, byte: 0x1, hword: 0x1021)
    0x42,       // PICOBIN_BLOCK_ITEM_1BS_IMAGE_TYPE
    0x01,       // item is 1 word in size
    0x21, 0x10, // SECURE mode (0x1021)
    
    // PICOBIN_BLOCK_ITEM_2BS_LAST (byte: 0xff, hword: 0x0001, byte: 0x0)
    0xFF,       // PICOBIN_BLOCK_ITEM_2BS_LAST
    0x01, 0x00, // item is 1 word in size
    0x00,       // pad
    
    // Relative pointer to next block (word: 0x0 = loop to self)
    0x00, 0x00, 0x00, 0x00,
    
    // PICOBIN_BLOCK_MARKER_END (word: 0xab123579)
    0x79, 0x35, 0x12, 0xAB
};
