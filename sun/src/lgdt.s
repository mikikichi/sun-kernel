bits 64


global lgdtset
global flush

section .data
gdtr dw 0
     dq 0


section .text

lgdtset:

lgdt [gdtr]
call flush
ret

;When executing a far return, the processor pops the return instruction pointer from the top of the stack into the EIP register,
;then pops the segment selector from the top of the stack into the CS register. The processor then begins program execution in the
;new code segment at the new instruction pointer.


flush:

lea rax, [rel .refresh]                                 ;this is the same as rip + refresh because nasm knows to create a rip
push rax
push 0x08
retq

.refresh
mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax                   ;these are all segment registers
ret