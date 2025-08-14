
section .multiboot_header

extern _multiboot_header_start
extern _TEXT_START_
extern _DATA_END_
extern _BSS_END_
extern _start
extern header_start
align 8
header_start:

    dd 0xe85250d6
    dd 0
    dd header_end - header_start

    dd 0xFFFFFFFF - (0xe85250d6 + 0 + (header_end - header_start)) + 1


info_tag_start:

	dw 1 ;info request
	dw 0 
	dd info_tag_end - info_tag_start
	dd 4
	dd 6
	dd 7



info_tag_end:

align 8
addr_tag_start:

	dw 2 ;addr 
	dw 0 
	dd addr_tag_end - addr_tag_start
	dd header_start ;beginning address of header, where magic number is loaded
	dd _TEXT_START_ ;phys address of text beginning offsets in os at which to start loading is headers start minus this
	dd _DATA_END_ ;data sections phys end address (load_end_addr - load_addr) how much data to load
	dd _BSS_END_ ;put stack here so its zeroed nicely


addr_tag_end:

align 8
entry_tag_start:

	dw 3 ;entry
	dw 0
	dd entry_tag_end - entry_tag_start
	dd _start


entry_tag_end:





align 8
end_tag_start:
    dw 0 ; type
    dw 0 ; flags
    dd end_tag_end - end_tag_start
end_tag_end:

header_end: