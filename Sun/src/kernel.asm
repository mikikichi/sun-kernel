global _start
extern _text
extern gdt_start
extern gdt_end
extern gdt_descriptor

section .text
_start:
    lgdt [gdt_descriptor]

    mov ax, 0x08
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08: _text
