
global _start
extern set_PML4
extern pml4
extern set_PDPT                                                     ;god this extern mess is ugly...
extern kernel_main
extern vbe_set_mode
extern kernel_code
extern kernel_data
extern gdt_pointer

%include "print.s"


section .bss
tempstack:
	resb 4096
tempstacktop:
	align 16


section .data
global pageinc
global gdtinc
global longinc
global multiboot2_ptr
global multiboot2_magic

pageinc:    db 0
gdtinc:     db 0
longinc:    db 0
multiboot2_ptr: dd 0
multiboot2_magic: dd 0
section     .text
bits 32 

_start:

	mov [multiboot2_ptr], ebx                      ;physical pointer to multiboots info struct
	mov [multiboot2_magic], eax                     ;magic number to check if the infos right

	mov esp, tempstacktop

	call set_PML4
	call set_PDPT

	lea eax, [pml4]
	mov cr3, eax

	;PAE 
	mov eax, cr4           
	or eax, 0x20
	mov cr4, eax

	;IA32_EFER longmode
	mov ecx, 0xC0000080
	rdmsr 
	or eax, 0x100 
	wrmsr


	mov eax, cr0
	or eax, 0x80000000 
	or eax, 0x10000 
	mov cr0, eax

	mov byte [pageinc], 1

;to get the right page do (page directory index * 512) + page table index


section .stack:
.stack:
stack_bottom:
    resb 4096 
stack_top:
    align 16                                ;top marks the "end" since stack grows downwards.... alignment 16 is standard

section .text
lgdt [gdt_pointer]                                         ;this could cause a gp if base addresss is non canonical canonical has to do with the extension

jmp kernel_code:long_mode_start


section .text
bits 64

long_mode_start:
    mov rsp, stack_top
    mov ax, kernel_data
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax                  

    mov byte [gdtinc], 1
    mov byte [longinc], 1
    call kernel_main
