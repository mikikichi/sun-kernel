
global _start
extern paging
extern set_PML4
extern pml4
extern pdpt
extern set_PDPT
extern kernel_main
extern vbe_set_mode
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


pageinc:    db 0
gdtinc:     db 0
longinc:    db 0

section     .text
bits 32                                                ;pt covers per entry 4kib (total coverage 2mib), pd covers per entry 2mib(total coverage possible 1gib)
                                                       ; pdpt covers per entry 1gib (total possible 512gib), pml4 covers per entry 512gib (possible 256 tib)
_start:                                                ; calculation of max is 512 times the entry size
													;steps are put pml 4 into cr3 enable pae in cr4 put 0xC0000080 to rdmsr and friends enable paging with cr0

	mov esp, tempstacktop                      ;without this no call!	

	call set_PML4
	call set_PDPT               ;is this going to zero???
	;cr3 set, this is our guard who will let us enter paging
	mov eax, pml4
	mov cr3, eax

	;PAE friend enabled
	mov eax, cr4            ;move cr4 to eax then turn the pae friend on and put it back where it belongs >-<
	or eax, 0x20
	mov cr4, eax

	mov ecx, 0xC0000080                 ;this is IA32_EFER extended feature enable register. longmode stuff
	rdmsr                                ;ecx server the msr the value like a server then eax is lower 32 bits edx upper 32 bits msr is 64bit but 36 bits are used
	or eax, 0x100                         ;set bit 8 IA32_EFER.LME which is R/W
	wrmsr                                  ;finally we write the value from our friend rdmsr

	;enabling cr0, star of the show! without this all linear addresses are treated as if they were there. linear means "all addresses that can be formed on the system"
	;its related to segmentation thats why gdt and such mental illness of segmentation is still somewhat prevelant (lol linus)
	;paging happens after segmentation translates logical addresses (what the programs think its there) to linear addresses
	;huh so paging is a form of memory protection yeah thats what the wikis say, makes sense why pure segmentation is agony
	;so our old crumpy segmentation is still needed... we love and hate you <3
	mov eax, cr0
	or eax, 0x80000000                   ;this is turning on bit 31 paging in cr0
	or eax, 0x10000                       ;write protect, for safety on ring 0
	mov cr0, eax

	mov byte [pageinc], 1

;to get the right page do (page directory index * 512) + page table index


section .data
gdt:                                                   ;this right here helps segmentation translate logical addresses to linear! wow thanks friend!
	dq 0x0000000000000000                      ;null
.kernel_code: equ $ - gdt

	dq 0x00AF9A000000FFFF                     ;kernel code
.kernel_data: equ $ - gdt                

	dq 0x00CF92000000FFFF                         

.gdt_pointer:
   dw $ - gdt - 1               ;limit 16bit
   dq gdt                             ;base 64bit base is here reference to below note

section .stack:
.stack:
stack_bottom:
    resb 4096                                ;unitialized space declared in non bss? eh?
stack_top:
    align 16                                ;top marks the "end" since stack grows downwards.... alignment 16 is standard

section .text
lgdt [gdt.gdt_pointer]                                         ;this could cause a gp if base addresss is non canonical canonical has to do with the extension
                                                         ;from PAE so we have more stuff but more responsibility. huh where is canonality checked and made??
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
