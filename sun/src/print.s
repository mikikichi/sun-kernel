%macro print 2
        push esi
        push edi

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
        pop edi
        pop esi

        ret
%endmacro