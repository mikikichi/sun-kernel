extern gdt
global setGDT
global reloadSegments

gdtr dw 0
     dd gdt

setGDT:
    mov     [gdtr], di
    mov     [gdtr + 2], rsi
    lgdt    [gdtr]
    ret

reloadSegments:
    push    0x08
    lea     rax, [rel .reload_CS]
    push    rax
    iretq
.reload_CS:
    mov     ax, 0x10
    mov     ds, ax
    mov     es, ax
    mov     fs, ax
    mov     gs, ax
    mov     ss, ax
    ret