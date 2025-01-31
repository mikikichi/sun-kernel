ENTRY(_start)

SECTIONS {
    . = 0x100000;
    .multiboot_header ALIGN(8) : {
        *(.multiboot_header)
    }

    . = ALIGN(4096);

    .text ALIGN(4K) : {
        *(.text)
    }

    .data ALIGN(4K) : {
        *(.data)
    }

    .bss ALIGN(4K) : {
        *(COMMON)
        *(.bss)
    }

    .gdt ALIGN(16) : {
        *(.gdt)
    }

    .kernel ALIGN(4K) : {
        *(.kernel)
    }

    _start = ADDR(.text); 

    }
