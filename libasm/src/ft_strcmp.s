bits 64

; extern printf

global ft_strcmp
; section .data
;     message: db "end", 10 ; 3
;     message2: db "char = %c", 0 ; 8
;     fmt db "char : %c",10, 0

section .text
    ft_strcmp:
        ; arg0 is rdi = s1
        ; arg1 is rdx = s2

        .loop:
            mov al, byte [rdi]
            test al, al
            jz .end

            mov cl, byte [rsi]

            cmp al, cl
            jne .end
            inc rdi
            inc rsi
            jmp .loop


        .end:
            movzx rdi, al
            movzx rsi, cl
            sub rdi, rsi
            mov rax, rdi

            ret