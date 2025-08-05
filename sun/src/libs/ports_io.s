bits 64 ;longmode
global inb
global outb
;outb writes, inb shows value
;for outb and inb its like func(port, data) ports are 16 bit data 8 bit
;PORT NUMBER IN DX!!!! al/ax for data
;NASM doesnt use size suffixes!!
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