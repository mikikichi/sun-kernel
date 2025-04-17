ENTRY(_start)

SECTIONS {
    . = 1M;                  /* Start the code at 1MB */
    
    /* Bootloader Section */
    .boot ALIGN(4) :
    {
        /* Ensure that the multiboot header is at the beginning of this section */
        *(.multiboot_header)
    }
    
    /* Code Section */
    .text :
    {
        *(.text)             /* All the code goes here */
    }

    /* Data Section */
    .data :
    {
        *(.data)             /* All the data goes here */
    }

    /* BSS Section (uninitialized data) */
    .bss :
    {
        *(.bss)              /* All the uninitialized data goes here */
        *(COMMON)
    }

    /* Stack Section */
    .stack ALIGN(4096) :
    {
        stack_bottom = .;
        . = . + 4096;         /* Reserve 4KB for the stack */
        stack_top = .;
    }

    /* Page Table Section */
    .page_tables :
    {
        *(p)
    }

    /* Global Descriptor Table (GDT) Section */
    .gdt64 ALIGN(8) :
    {
        *(gdt64)
    }

    /* End of the Kernel Binary */
    end = .;
}
