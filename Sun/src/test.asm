global _text

section .text
_text:
	mov esi, 0xb8000
	mov edi, msg

print_loop:
	mov al, [edi]
	test al, al
	jz done

	mov [esi], ax
	add esi, 2

	inc edi
	jmp print_loop

done:
	hlt

section .data
msg db 'Hello, World!', 0
