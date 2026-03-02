bits 64

global ft_strlen

section .text
    ft_strlen:
        push rbx
        mov rbx, rdi
        .loop:
            mov al, byte [rbx] ; pas obligé decrire byte mais au moins ca precise bien

            cmp al, 0 ; ou test al, al
            je .end ; ou jz si test
            inc rbx
            jmp .loop

        .end:
            sub rbx, rdi
            mov rax, rbx
            pop rbx 
            ret