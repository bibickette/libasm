bits 64

extern printf

global ft_strlen
section .data
    message: db "end", 10 ; 3
    message2: db "char = %c", 0 ; 8
    fmt db "char : %c",10, 0

section .text
    ft_strlen:
        mov rbx, rdi
        .loop:
            mov al, [rbx]

            ; lea rdi, [rel message2] ; crochet ca veut dire recupere le premier byte de la zone memoire ou il est
            ; mov rsi, rbx
            ; mov rax, 0
            ; call printf wrt ..plt

            test al, al
            jz .end
            inc rbx
            jmp .loop

        .end:

            sub rbx, rdi
            mov rax, rbx
            ret