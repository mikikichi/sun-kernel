%macro print 2
        mov esi, %1
        mov edi, 0xb8000

        jmp %%print_char

    %%print_char:
        lodsb
        test al, al
        jz %%.done
        mov ah, %2
        mov [edi], ax
        add edi, 2

        jmp %%print_char

    %%.done:
        ret
%endmacro