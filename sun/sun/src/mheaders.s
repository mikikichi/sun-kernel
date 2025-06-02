section .multiboot_header
align 8
header_start:
    dd 0xe85250d6
    dd 0
    dd header_end - header_start

    dd 0xFFFFFFFF - (0xe85250d6 + 0 + (header_end - header_start)) + 1

    dw 0 ; type
    dw 0 ; flags
    dd 8 ; size
header_end: