bits 64

extern printf
extern ft_strlen

global main

section .data
    message: db "Yo tout le monde", 10, 0 ; 16
    message2: db "len = %d",10, 0 ; 8


section .text
    main:
        mov rax, 1
        mov rdi, 1
        mov rsi, message
        mov rdx, 16+1
        syscall

        ; call printf for return value of write
        lea rdi, [rel message2] ; crochet ca veut dire recupere le premier byte de la zone memoire ou il est
        mov rsi, rax
        mov rax, 0
        call printf wrt ..plt

        lea rdi, [rel message]
        call ft_strlen

        lea rdi, [rel message2] ; crochet ca veut dire recupere le premier byte de la zone memoire ou il est
        mov rsi, rax
        mov rax, 0
        call printf wrt ..plt


        mov rax, 60
        mov rdi, 0
        syscall