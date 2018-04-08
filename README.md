# SAMD10 UART Bootloader

This project contains a simple uart based bootloader which can be used as a
starting point for further experiments or dropped into production right away.

The bootloader is designed to allow easy in-system updates for SAMD10C/D MCUs.

## Usage

Using this bootloader is simple:
- Create your firmware, link it with the bootloader-variant of the linker script. (can be found [here](tbd))
- Upload the bootloader to your device using SWD.
- When the bootloader detects that no firmware is programmed, it will wait for a firmware to be uploaded.
- Upload your firmware using the `upload.py` tool.

**Note that your user-firmware has to include a function to enter the bootloader, one is provided [here](tbd)**

Hints:
- The bootloader requires 16 bytes of memory at the beginning of the memory address space.
- If you write a specific value (**0xDEADBEEF**) to the first 16 bytes and issue an
`NVIC_SystemReset()`, the bootloader will wait for a new firmware to be uploaded.
- Currently, there is no timeout implemented, which means if you are within the
bootloader it won't exit automatically.
- `upload.py` has lots of options, especially a strict verification you won't overwrite your bootloader.
- You are able to use interrupts in your user firmware, as the bootloader will relocate the interrupt vector table accordingly.

## Architecture

The source code can be found in main.c, it is based on the awesome
[mcu-starter-projects](https://github.com/ataradov/mcu-starter-projects) by Alex Taradov.

You can compile the project without any IDE installed, you will need arm-none-eabi-gcc and make.
If you have anything in place, just type `make` and you're done.

The provided binaries are built with GCC 7.3, however older versions should be fine.
