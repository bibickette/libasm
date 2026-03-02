bits 64

global ft_strcpy

section .text
    ft_strcpy:
        push rbx ; callee-saved so value need to be restaured at the end
        mov rbx, rdi ; save arg0 in rbx = dest
        mov rdx, rsi ; save arg1 in rdx = src
        
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
            pop rbx ; restaure callee-saved rbx value
            ret