ENTRY(_start)

SECTIONS {
    . = 1M;

    .boot ALIGN(4) :
    {
        /* ensure that the multiboot header is at the beginning */
        *(.multiboot_header)
    }

    .text :
    {
        *(.text)
    }
}
