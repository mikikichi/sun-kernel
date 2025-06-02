
global _start
extern gdt_pointer
extern kernel_main
extern vbe_set_mode
%include "print.s"

section     .text
bits 32

section .data
global pageinc
global gdtinc
global longinc


pageinc:    db 0
gdtinc:     db 0
longinc:    db 0

_start:
    ; LEVEL 4 PAGE TABLE
    mov eax, p3_table 
    or eax , 0b11 

    mov dword [p4_table + 0], eax

    ; LEVEL 3 PAGE TABLE
    mov eax, p2_table
    or eax, 0b11
    mov dword [p3_table + 0], eax

    mov ecx, 0

    mov byte [pageinc], 1

.map_p2_table:
    mov eax, 0x200000 ; 2MiB
    mul ecx 
    or eax, 0b10000011 
    mov [p2_table + ecx * 8], eax

    inc ecx 
    cmp ecx, 512
    jne .map_p2_table

    mov eax, p4_table
    mov cr3, eax 

    ;enable PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    mov ecx, 0xC0000080
    rdmsr 
    or eax, 1 << 8
    wrmsr


    ; ENABLE PAGING
    mov eax, cr0
    or eax, 1 << 31
    or eax, 1 << 16
    mov cr0 , eax


section .data
gdt:
.null_entry: equ $ - gdt

dq 0x0000000000000000                      ;null
.kernel_code: equ $ - gdt

dq 0x00AF9A000000FFFF                     ;kernel code
.kernel_data: equ $ - gdt                

dq 0x00CF92000000FFFF                  

.gdt_pointer:
   dw $ - gdt - 1               ;limit 16bit
   dq gdt                             ;base 64bit



section .bss
align 4096 
p4_table:
    resb 4096 
p3_table:
    resb 4096
p2_table:
    resb 4096

.stack:
stack_bottom:
    resb 4096
stack_top:
    align 16

section .text
lgdt [gdt_pointer]
jmp gdt.kernel_code:long_mode_start


section .text
bits 64

long_mode_start:
    mov rsp, stack_top
    mov ax, gdt.kernel_data
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax                  

    mov byte [gdtinc], 1
    mov byte [longinc], 1
    call kernel_main
