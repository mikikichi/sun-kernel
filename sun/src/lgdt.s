bits 32


global lgdtset
global flush

section .data
gdtr dw 0
     dq 0


section .text

lgdtset:
mov ax, [esp + 4]
mov [gdtr], ax

mov eax, [esp + 8]
mov [gdtr + 2], eax
lgdt [gdtr]
call [complete]
ret

flush:
push 0x08 ;0x08 code segment index 1 privelege 00 bit moves < 
;far return??

complete:
mov ax, 0x10 ;data segment index 2 this is from the C file 
mov ss, ax 
mov ds, ax
mov es, ax 
ret
