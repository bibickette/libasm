bits 64

extern __errno_location


global ft_read

section .text
    ft_read:
        mov rax, 0
        syscall
        cmp rax, 0
        jl .error ; if syscall return value is negative, jump to error
        ret
        
    .error:
        push rbx

        neg rax
        mov rbx, rax
        call __errno_location wrt ..plt
        mov [rax], rbx
        mov rax, -1

        pop rbx
        ret