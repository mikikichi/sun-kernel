; =====================
; VGA COLOUR CHEATSHEET
; =====================
; 0x0 black
; 0x1 blue
; 0x2 green
; 0x3 cyan
; 0x4 red
; 0x5 magenta
; 0x6 brown
; 0x7 light gray
; 0x8 dark gray
; 0x9 bright blue
; 0xA bright green
; 0xB bright cyan
; 0xC bright red
; 0xD bright magenta
; 0xE yellow
; 0xF white
;
; FOR REFERENCE
; white on black:     mov ah, 0x0F
; the black is the 0x0 part, the background colour.
; the white is the F part, the foreground colour.
; mess about with this, will come in handy for
; logs and stuff

global _start

%include 'print.s'

section .text
bits 32

section .data
global pageinc
global gdtinc
global longinc

pageinc:    db 0
gdtinc:     db 0
longinc:    db 0

section .bss
stack_top:	
	resb 131072
stack_end:

p4_table:
	resb 4096
p3_table:
	resb 4096
p2_table:
	resb 4096


_start:
	
	mov eax, p3_table
	or eax, 0b11
	mov dword[p4_table], eax

	
	mov eax, p2_table
	or eax, 0b11
	mov dword[p3_table], eax

	mov ecx, 0

.p2_table:
	mov eax, 0x200000
	mul ecx
	or eax, 0b10000011
	mov [p2_table + ecx * 8], eax

	inc ecx
	cmp ecx, 512
	jne .p2_table

paging_setup:

	mov edx, cr4
	or edx, (1 << 5)
	mov cr4, edx

	mov ecx, 0xC0000080
	rdmsr
	or eax, (1 << 8)
	wrmsr

	mov eax, p4_table
	mov cr3, eax
	or ebx, (1 << 31) | (1 << 0)
	mov cr0, ebx

	mov ax, gdt64.data
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	jmp gdt64.code

section .rodata ; read only data
gdt64:
    dq 0
.code: equ $ - gdt64 
;.code us the name of this label, and the period tells nasm that its part of the previous label, so this isn't 'code' this is' 'gdt64.code'
    dq (1<<44) | (1<<47) | (1<<41) | (1<<43) | (1<<53) 
    ; executable, 64 bit, readable, present

    ; (1<<#) means left shift 1 by #, eg (1<<44) would set the 44th bit
    ; | is an or statement but cause this is data and not assembly instructions we use | not or


    ; 44: ‘descriptor type’: This has to be 1 for code and data segments
    ; 47: ‘present’: This is set to 1 if the entry is valid
    ; 41: ‘read/write’: If this is a code segment, 1 means that it’s readable
    ; 43: ‘executable’: Set to 1 for code segments
    ; 53: ‘64-bit’: if this is a 64-bit GDT, this should be set

.data: equ $ - gdt64
    dq (1<<44) | (1<<47) | (1<<41)
    ; present, readable

.pointer:
	dw .data + 8 - gdt64 - 1
	dq gdt64

; 64 bit land from here on out - scary
; remember theres no 'eax' or 'ebx' or any of that prehistoric stuff
; we now have the groundbreaking 'rax' and 'rbx'

section .text
bits 64

extern kernel_main

long_mode_start:
    mov byte [longinc], 1
	mov rsp, stack_end
	and rsp, ~0xF
    call kernel_main
