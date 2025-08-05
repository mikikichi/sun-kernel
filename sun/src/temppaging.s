global paging
global set_PML4
global set_PDPT
global pml4 
global pdpt
bits 32

section .bss
align 4096 
pml4: resb 4096
pdpt: resb 4096


section .text
paging:
;pml4 index bits 47-39
set_PML4:
	mov eax, pdpt
	or eax, 0x3

	mov dword [pml4 + 0], eax
	ret
;pdpt index bits 38-30													   
set_PDPT: 

	;ngl i think this could have been written in C
	mov eax, 0x00000000 
	or eax, 0x83 
	mov ecx, 0x0

	mov [pdpt + 0], eax
	mov [pdpt + 4], ecx

	mov eax, 0x40000000 
	or eax, 0x83
	mov ecx, 0x0

	mov [pdpt + 8], eax 
	mov [pdpt + 12], ecx 
	ret
