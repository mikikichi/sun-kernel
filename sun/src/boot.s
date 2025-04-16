; =====================
; VGA COLOUR CHEATSHEET
; =====================
; 0x0 black
; 0x1 blue
; 0x2 green
; 0x3 cyan
; 0x4 red
; 0x5 magenta
; 0x7 brown
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
section     .text
bits 32

section .data
msg     db "Paging works!", 0xa

_start:

    ; LEVEL 4 PAGE TABLE
    mov eax, p3_table ; this copies the contents of the third level page table into the eax reg
    or eax , 0b11 

    ; or is basically an or gate in minecraft
    ; there is redstone running from a redstone lamp to 2 levers, if both are off
    ; then the lamp is off - but if either of the levers are one, the lamp is on.
    ; here, if eax is is 0, and 0b11 is 0, then it returns zero. is eax is 1
    ; and 0b11 is 0, it returns 1. etc, etc
    ; the result is then stored in the page table

    mov dword [p4_table + 0], eax
    ; dword allocates a double word (according to google)
    ; basically copies the zeroth entry into eax
    ; the zero can be removed, mainly kept for style points
    ; cause the 0 will be changed to something that cannot
    ; be removed in later parts of this code so this keeps
    ; the symmetry

    ; LEVEL 3 PAGE TABLE
    mov eax, p2_table
    or eax, 0b11
    mov dword [p3_table + 0], eax

    mov ecx, 0

    print msg, 0x0A

.map_p2_table:
    mov eax, 0x200000 ; 2MiB
    ; each page is 2 MiB in size so to ge tthe right memory
    ; location you multiply the number of the loop counter
    ; (mov ecx, 0) by 0x200000
    mul ecx ; mul multiplies ecx by eax, 
    or eax, 0b10000011 ; this is called a huge page bit, basically makes them 2 MiB instead of 4 KiB
    mov [p2_table + ecx * 8], eax
    ; instead of adding + 0 we now add ecx * 8, because each entry is 8 bytes in size
    ; so the counter should be multiplied by 8

    inc ecx ; increments the loop counter by one
    cmp ecx, 512 ; compares ecx with 512, because there needs to be 512 page entries in total
    jne .map_p2_table

    ; this gives us a maximum of 1gb RAM available to use (i think lmao)

    ; move page table address to cr3
    mov eax, p4_table
    mov cr3, eax ; cr registers control CPU, and can only take a value from
    ; another register - hence moving p4_table into eax instead of directly into cr3

    ;enable PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ; sets the long mode bit
    mov ecx, 0xC0000080
    rdmsr ; read a model specific register (https://datasheets.chipdb.org/Intel/x86/Pentium/Embedded%20Pentium%AE%20Processor/MDELREGS.PDF) can't be arsed to explain this
    or eax, 1 << 8
    wrmsr

    ; the intermezzOS guide doesnt really explain this so i can't either ):

    ; ENABLE PAGING
    mov eax, cr0
    or eax, 1 << 31
    or eax, 1 << 16
    mov cr0 , eax

    ; technically in long mode now but not really, currently in compatibility mode
    ; to get to real long mode there needs need to be a GDT (look at OSDev site if your unsure)

section .bss ; linker sets everything to 0 in bss
align 4096 ; aligns addresses to be a multiple of 4096
p4_table:
    resb 4096 ; reserves 4096 bytes
p3_table:
    resb 4096
p2_table:
    resb 4096

; my paging is basically from intermezzOS because:
; A. it works
; B. i am way out of my depth trying to attempt it
; yes i know i should NOT be doing OSDev then but
; whatever i enjoy it