ENTRY(_start)

SECTIONS {

    . = 2M;

    .boot :
    {
        *(.multiboot_header)
    }

    .text :
    {
        *(.text)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(.bss)

        *(COMMON)
       . = ALIGN(4096);
    }

    .rodata :
    {
        *(.rodata)
    }
}