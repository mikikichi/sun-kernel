#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "vgabuffer.h"
#include "log.h"

#if defined(__linux__)
#error "your building this without a crosscompiler. your trying to build an operating system as a linux executable."
#endif

#if !defined(__i386__)
#error "this OS requires an ix86-elf compiler."
#endif
 
void kernel_main(void)
{
	text_init();
	print("Welcome to the Sun Kernel!\n");
	sys_success("The Sun Kernel has successfullly booted and loaded!\n");
	sys_warn("this kernel comes with absolutely nothing by default. add your own userspace\n");
	clear();
}
