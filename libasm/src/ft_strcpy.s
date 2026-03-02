bits 64

; extern printf

global ft_strcpy

; section .data
;     message: db "str1 = %s", 0 ; 3
;     message2: db "str2 = %s", 0 ; 3

section .text
    ft_strcpy:
        push rbx
        mov rbx, rdi ; save arg0 in rbx = dest
        mov rdx, rsi ; save arg1 in rdx = src
        
        ; lea rdi, [rel message] ; crochet ca veut dire recupere le premier byte de la zone memoire ou il est
        ; mov rsi, rbx
        ; mov rax, 0
        ; call printf wrt ..plt

        ; lea rdi, [rel message2] 
        ; mov rsi, rdx
        ; mov rax, 0
        ; call printf wrt ..plt
        
        .loop:
            mov al, byte [rdx] ; first byte of rdx(arg1 = src) save in al
            mov byte [rbx], al ; copy al in rbx(arg0 = dest)
            test al, al ; test if al is 0
            jz .end ; if al is 0, jump to end

            inc rdx ; move to the next byte of rdx(arg1 = src)
            inc rbx ; move to the next byte of rbx(arg0 = dest)
            jmp .loop ; jump to the beginning of the loop

        .end:
            mov rax, rdi ; return dest (arg0) in rax
            pop rbx
            ret