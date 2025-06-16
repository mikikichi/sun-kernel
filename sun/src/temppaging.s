global paging
global set_PML4
global set_PDPT
global pml4 
global pdpt
bits 32

section .bss                               ;uninitialized data i think? this isnt the same as a data section
align 4096 
pml4: resb 4096                           ;page table structures are always 4kb the "container" itself is
pdpt: resb 4096                                  ;resb reserves us a sweet spot. 4096 is 4kb this is seen a lot                          ;no need for an array again this reserves the 512 entries!!


section .text
paging:
;level 4 page table
;sign extension 16 bits not sure what this means???? WHAT DOES THAT AVL STUFF MEAN I DON'T GET IT! but its not rly relevant now?
;pml4 index bits 47-39
set_PML4:                                                 ;maps 48bit virtual addresses to 52bit physical with pae
	mov eax, pdpt                                   ;should be physical address of pdpt, this is like a chain i cant throw a pdpt or even pd alone they get lonely ;_;!
	or eax, 0x3                                     ;present, writable physical address of pml4 goes to cr3

	mov dword [pml4 + 0], eax                         ;holds physical address of pdpt address is then stored in current levels entry this is to chain, again needs friends
                                                      ;its like doing pml4[0] in C
;page directory pointer table
;pdpt index bits 38-30													   
set_PDPT:                                       ;pdpt must be located below 4gb memory because cr3 is 32bits even in pae 32bit can only hold 4gb minus 1 byte

                                       ;offsets for gb: 0x00000000, 0x4000000 its plus 4
	mov eax, 0x00000000               ;the entries are 64 even when lower bits 32 are used! remember lower to higher
	or eax, 0x83                          ;this means present writable ps and all that stuff. no need for more complexity rn
	mov ecx, 0x0

	mov [pdpt + 0], eax                            ;lower and higher bits, only the lower bits are used so set flags there!!
	mov [pdpt + 4], ecx                            ;this all becomes one entry! still first index

	mov eax, 0x40000000 
	or eax, 0x83
	mov ecx, 0x0
;virtual is pdpt index times 1gb its index times pagesize in easy speech
	mov [pdpt + 8], eax 
	mov [pdpt + 12], ecx 
	ret

;YOU DON'T NEED TO GO THROUGH THESE IF YOU DON'T USE THEM FOR NOW! set ps bit!!
;pd index bits 29-21
.PD:

	;mov eax, PT             THIS IS NOT NEEDED FOR NOW!!!!
	;or eax, 0x3

	;mov dword [PT + 0], eax

;page table, this tells MMU how to translate addresses, each index contains physical memory address to which each page should be mapped golden rule 48 to 52
;pt index bits 20-12
.PT:

;this could be useful when we have finally an allocator for heap and friends. i think allocating a gig for small things is stupid
;offset within 4kb page bits 11-0
;bits 12-51 physical address set ps
;more monster notes so the indexes are like the "marks" like you see an address, look at the bits mentioned to see if it came from which table