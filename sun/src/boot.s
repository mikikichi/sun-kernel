
global _start
;paging externs
extern set_PML4
extern pml4
extern set_PDPT
;kernel externs
extern kernel_main
extern vbe_set_mode
;gdt externs
extern kernel_code
extern kernel_data
extern gdt_pointer
;linker externs
extern _DATA_START_
extern _DATA_END_
extern _BSS_START_
extern _BSS_END_
extern _STACK_END

%include "print.s"




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
	;ok u need to initialize the data sections and such like for now push these to the stack and then to data sections nothing is given for free huh
	;copy from rom to ram and such... maybe look into early boot stuff again???
	;remember ebx has the pointer, eax has the magic number

	;bss needs to be zeroed out
	;data copied from rom to ram
	mov esp, _STACK_END
	push ebx
	push eax






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


section .text
lgdt [gdt_pointer]                                         ;this could cause a gp if base addresss is non canonical canonical has to do with the extension

jmp kernel_code:long_mode_start


section .text
bits 64

long_mode_start:
    mov rsp, _STACK_END
    mov ax, kernel_data
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax                  
	;eventually here push the multiboot stuff back to stack so it grabs them remember its like 2 1 here 2nd parameter first
	;ebp is the stacks frame in the specific function or thing argument is + local vars are - first ebp is ret address
    mov byte [gdtinc], 1
    mov byte [longinc], 1
    call kernel_main
	hlt