/**
 * FILE: linker.ld
 *
 * DESCRIPTION:
 * RP2350 Minimal Linker Script for bare-metal development.
 *
 * BRIEF:
 * Ensures the boot ROM accepts and runs the image by placing 
 * the IMAGE_DEF block first at 0x10000000, aligning the vector 
 * table to a 128-byte boundary within the first 4 KB and defining 
 * a non-secure stack region in SRAM.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 27, 2025
 */

ENTRY(Reset_Handler)

/**
 * Define memory regions.
 */
__XIP_BASE   = 0x10000000;
__XIP_SIZE   = 32M;

__SRAM_BASE  = 0x20000000;
__SRAM_SIZE  = 512K;                             /* non-secure window */
__STACK_SIZE = 32K;

MEMORY
{
  RAM   (rwx) : ORIGIN = __SRAM_BASE, LENGTH = __SRAM_SIZE
  FLASH (rx)  : ORIGIN = __XIP_BASE,  LENGTH = __XIP_SIZE
}

/**
 * Program headers.
 */
PHDRS
{
  text PT_LOAD FLAGS(5);                         /* RX */
}

/**
 * Section placement.
 */
SECTIONS
{
  . = ORIGIN(FLASH);

  /**
   * Vector table MUST be first at 0x10000000.
   */
  .vectors :
  {
    KEEP(*(.vectors))
  } > FLASH :text

  ASSERT((ADDR(.vectors) == ORIGIN(FLASH)),
         "Vector table must be at start of flash (0x10000000)")

  /**
   * Text and read-only data.
   */
  .text :
  {
    . = ALIGN(4);
    *(.text*)
    *(.rodata*)
    KEEP(*(.init))
    KEEP(*(.fini))
    KEEP(*(.ARM.attributes))
  } > FLASH :text

  /**
   * IMAGE_DEF block at end of code.
   */
  .embedded_block :
  {
    KEEP(*(.embedded_block))
  } > FLASH :text

  /**
   * Non-secure stack symbols.
   */
  __StackTop   = ORIGIN(RAM) + LENGTH(RAM); /* 0x20080000 */
  __StackLimit = __StackTop - __STACK_SIZE;
  __stack      = __StackTop;
  _stack_top   = __StackTop;                /* Symbol for C code */

  .stack (NOLOAD) : { . = ALIGN(8); } > RAM

  PROVIDE(__Vectors = ADDR(.vectors));
}
