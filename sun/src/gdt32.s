bits 32

extern lgdt

section .data
gdt_pointer:
   dw gdt_end - gdt_start - 1               ;limit 16bit
   dd gdt_start                             ;base 32bit


section .text

gdt_start:
;offset 0
.null_entry:
dq 0x0000000000000000

;offset 0x8 so 8 bytes
.kernel_code:
dq 0xFFFF0000009AFC00

;offset 0x10 so 16 bytes
.kernel_data:
dq 0xFFFF00000092FC00

gdt_end:


lgdt:
lgdt [gdt_pointer]
call reload
ret

reload:
jmp 0x08:.segments 

.segments:
mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax                   ;these are all segment registers
ret