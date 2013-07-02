/*
Linker script for STM32F303xC definitions with 256K Flash and 40K RAM

Memory sizes for STM32F3xx (x is one of C/R/V, indicating pin count 48/64/100):
		 	Flash	RAM	CCRAM
STM32F302xB		128	24	0
STM32F302xC		256	32	0
STM32F303xB		128	32	8
STM32F303xC		256	40	8

The CCRAM or "core coupled RAM" is on both data and instruction bus
so code can execute from there.
Parity checking exists on CCRAM and on first 16K of main RAM.
*/

/* Memory Spaces Definitions */
ENTRY(Reset_Handler)
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
  RAM  (rw) : ORIGIN = 0x20000000, LENGTH = 40K
  CCRAM (rwx) : ORIGIN = 0x10000000, LENGTH = 8K
}

/* highest address of the user mode stack */
/* this is essentially 0x20000000 + 32K */
_estack = 0x2000A000;
