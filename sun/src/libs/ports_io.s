bits 64 ;longmode
global inb
global outb

section .text

outb:
	mov dx, di ;port
	mov al, sil ;data

	out dx, al 
	ret


inb:
	mov dx, di 

	in al, dx
	movzx rax, al ;pads 8bit val to be returned in rax
	ret