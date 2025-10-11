ENTRY(_start)

SECTIONS {
    . = 1M;                                                          /* dot is a location counter without it its incremented by the size */
	_kernel_start = .;
    .multiboot_header ALIGN(8) :                                      /* multiboot said that it needs to be aligned to 8 bytes */
    {
        KEEP(*(.multiboot_header))                           /* keep will instruct linker to keep specified section even if no symbols inside are referenced */
    }


    .text :  {
	_TEXT_START_ = .;
        *(.text .text.*)   
	_TEXT_END_ = .;                                    /* text is twice so we dont miss any*/
    }

    . = ALIGN(CONSTANT(MAXPAGESIZE));                                         /* maxpagesize is gnu linker variable good and portable!!*/

    .rodata : {
	_RODATA_START_ = .;                                                          /* symbol for ease of life */
        *(.rodata .rodata.*)
	_RODATA_END_ = .;
    }

    . = ALIGN(CONSTANT(MAXPAGESIZE));

    .data : {
	_DATA_START_ = .;
        *(.data .data.*)
	_DATA_END_ = .;
    }

    . = ALIGN(CONSTANT(MAXPAGESIZE));

    .bss : {
	_BSS_START_ = .;
        *(.bss .bss.*)											
        *(COMMON)

	. = ALIGN(0x10);

	_STACK_START = .; /*stack needs to be aligned to 16 cuz address of stack pointer needs to be multiple of 16 0x10 is 16 in hex*/
		. = . + 0x4000;           /*typical stack size here 16kb for starters*/
	_STACK_END = .;




	_BSS_END_ = .; 
    } 
	_kernel_end = .;

    . = ALIGN(CONSTANT(MAXPAGESIZE));



    /DISCARD/ : {                                                         
        *(.eh_frame*)
        *(.note .note.*)
    }
}