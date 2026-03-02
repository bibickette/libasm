bits 64

global ft_strcmp

section .text
    ft_strcmp:
        ; arg0 is rdi = s1
        ; arg1 is rdx = s2

        .loop:
            mov al, byte [rdi] ; mov le 1er byte de s1 dans un registre de 8 bits
            mov cl, byte [rsi]

            test al, al
            jz .end ; jump when last result was zero

            cmp al, cl
            jne .end ; jump when not equal

            inc rdi ; s1 ++
            inc rsi ; s2 ++
            jmp .loop

        .end:
            movzx rdi, al ; on reettend la value sur laquelle on  est a un registre 64 bits
            movzx rsi, cl 
            sub rdi, rsi ; fait *s1 - *s2
            mov rax, rdi ; resultat dans rax
            ret