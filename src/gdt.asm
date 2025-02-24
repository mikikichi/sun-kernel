gdtr DW 0	; limit
	 DD 0	; Base address

setGdt:
	mov ax, [esp + 4] 
	mov [gdtr], ax
	mov eax, [esp + 8]
	mov [gdtr + 2], eax
	lgdt [gdtr]
	ret

reloadSegments:
	JMP   0x08:.reload_CS 
.reload_CS:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	ret
