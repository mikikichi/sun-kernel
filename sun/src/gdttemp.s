bits 32
global gdt
global kernel_code
global kernel_data
global gdt_pointer

section .data
gdt:
	dq 0x0000000000000000                      ;null
kernel_code: equ $ - gdt

	dq 0x00AF9A000000FFFF                     ;kernel code
kernel_data: equ $ - gdt                

	dq 0x00CF92000000FFFF 

gdt_pointer:
   dw $ - gdt - 1               ;limit 16bit
   dq gdt                             ;base 64bit 
