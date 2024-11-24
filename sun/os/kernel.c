#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "print.h"

#if defined(__linux__)
#error "your building this without a crosscompiler. your trying to build an operating system as a linux executable."
#endif

#if !defined(__i386__)
#error "this OS requires an ix86-elf compiler."
#endif

#define vga_colour_light_grey vga_colour_light__gray
#define vga_colour_dark_grey vga_colour_dark_gray
 
void kernel_main(void)
{
	text_init();
	print("Hello, Kernel World!\n");
}
