#include "kernel/kernel.h"


extern uint32_t multiboot2_magic;
extern uint32_t multiboot2_ptr; 
extern uint64_t _kernel_start;
extern uint64_t _kernel_end;

void kernel_main() {
	//here eventually as soon as entry, remake paging in C and once we are in with the physical allocator start off a virtual allocator!!
	//the page frame allocator will be called here to dynamically make paging entries, i think it should be fine for it to be done ASAP!
	video_init(); //sets up ega/vga, no keyboard currently

	uint32_t *m2ptr = (uint32_t *)(uintptr_t)multiboot2_ptr; 
	mb2_parse(m2ptr, multiboot2_magic, _kernel_start, _kernel_end); 

	//does not hlt or call terminal loops

}