ENTRY(_start)

SECTIONS {

    . = 1M;

    .multiboot_header ALIGN(8) :
    {
        KEEP(*(.multiboot_header))
    }

    .bss :
    {
        *(.bss)

        *(COMMON)
       . = ALIGN(4096);
    }

    .text :
    {
        *(.text)
    }

    .data :
    {
        *(.data)
    }

    .rodata :
    {
        *(.rodata)
    }
}