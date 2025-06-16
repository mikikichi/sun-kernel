ENTRY(_start)

SECTIONS {
    . = 1M;                                                          /* dot is a location counter without it its incremented by the size */

    .multiboot_header ALIGN(8) :                                      /* multiboot said that it needs to be aligned to 8 bytes */
    {
        KEEP(*(.multiboot_header))                           /* keep will instruct linker to keep specified section even if no symbols inside are referenced */
    }

    . = ALIGN(CONSTANT(MAXPAGESIZE));                        

    .text : {
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
        *(COMMON) 													/* here for uninitialized data storing thats what a bss is lol */
	_BSS_END_ = .; 
    } 

    . = ALIGN(CONSTANT(MAXPAGESIZE));

    /DISCARD/ : {                                                         
        *(.eh_frame*)
        *(.note .note.*)
    }
}