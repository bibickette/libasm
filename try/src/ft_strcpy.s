bits 64

extern printf

global ft_strcpy

; section .data
;     message: db "str1 = %s", 0 ; 3
;     message2: db "str2 = %s", 0 ; 3

section .text
    ft_strcpy:
        mov rbx, rdi
        mov rdx, rsi
        
        ; lea rdi, [rel message] ; crochet ca veut dire recupere le premier byte de la zone memoire ou il est
        ; mov rsi, rbx
        ; mov rax, 0
        ; call printf wrt ..plt

        ; lea rdi, [rel message2] ; crochet ca veut dire recupere le premier byte de la zone memoire ou il est
        ; mov rsi, rdx
        ; mov rax, 0
        ; call printf wrt ..plt
        .loop:
            mov al, byte [rdx] ; pas obligé decrire byte mais au moins ca precise bien
            mov byte [rbx], al
            test al, al
            jz .end

            inc rdx
            inc rbx
            jmp .loop

        .end:
            mov rax, rdi
            ret