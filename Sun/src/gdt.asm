section .gdt
global gdt_start
global gdt_end
global gdt_descriptor

gdt_start: ; labels for jumps and stuff
	; starts with null 8 bytes
	dd 0x0 ;4 bytes
	dd 0x0 ; 4 bytes

gdt_code:
	;kernel space
	dw 0xffff ; segment length
	dw 0x0 ; segment base
	db 0x0 ; segment base 2
	db 10011010b ;flags (8 bit)
	db 11001111b ; flags (4 bits) + segment length, bits 16-19
	db 0x0

	; driver space 1
	dw 0xffff
	dw 0x0
	db 0x0
	db 10111010b
	db 11001111b
	db 0x0

	; driver space 2
	dw 0xffff
	dw 0x0
	db 0x0
	db 11011010b
	db 11001111b
	db 0x0

	;user space
	
	dw 0xffff
	dw 0x0
	db 0x0
	db 11111010b
	db 11001111b
	db 0x0
	
gdt_data:
	;kernel data segment
	dw 0xffff
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0
	
	; driver data 1
	dw 0xffff
	dw 0x0
	db 0x0
	db 10111010b
	db 11001111b
	db 0x0

	; driver data 2
	dw 0xffff
	dw 0x0
	db 0x0
	db 11011010b
	db 11001111b
	db 0x0

	;user data
	
	dw 0xffff
	dw 0x0
	db 0x0
	db 11111010b
	db 11001111b
	db 0x0

gdt_end:

gdt_descriptor:
	dw gdt_end - gdt_start - 1
	dd gdt_start
