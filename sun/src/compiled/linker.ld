ENTRY(_start)

SECTIONS {

    . = 1M;

    .boot ALIGN(0x1000) :
    {
        *(.multiboot_header)
    }

    .text ALIGN(0x1000) :
    {
        *(.text)
    }

    .data ALIGN(8) :
    {
        *(.data)
    }

    .map_p2_table ALIGN(0x1000) :
    {
        *(.map_p2_table)
    }

    .bss ALIGN(8) :
    {
        *(.bss)
    }

    .stack ALIGN(16) :
    {
        . = . + 0x1000;
    }

    .rodata ALIGN(16) :
    {
        *(.rodata)
    }

    .pointer ALIGN(8) :
    {
        *(.pointer)
    }

    .long_mode_start :
    {
        *(.long_mode_start)
    }
}
