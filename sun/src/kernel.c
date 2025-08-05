#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "lib/print.h"
#include "lib/log.h"
#include "lib/serial.h"
#include "term/terminal.h"
#include "idt/idt.h"
#include "program/exit.h"
#include "lib/serial.h"
#include "mult/multibootinfo.h"


extern uint32_t multiboot2_magic;
extern uint32_t multiboot2_ptr; 
extern uint64_t _kernel_start;
extern uint64_t _kernel_end;

void kernel_main() {
	//here eventually as soon as entry, remake paging in C and once we are in with the physical allocator start off a virtual allocator!!
	//the page frame allocator will be called here to dynamically make paging entries, i think it should be fine for it to be done ASAP!

    clear();
    serial_init();

    info("Kernel is UP!\n");
    success("Serial is UP!\n");
    serial_print("serial up\n");
	uint32_t *m2ptr = (uint32_t *)(uintptr_t)multiboot2_ptr; 
	mb2_parse(m2ptr, multiboot2_magic, _kernel_start, _kernel_end); 

    success("Running in long mode.\n");

	success("Temporary paging has started - up to 2GB RAM addressable\n");
    serial_print("Paging load\n");
	
	idt_init();

	//removed the tests for gdt and such cuz we would just insta fault no need to check
	terminal();
}