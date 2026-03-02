bits 64

extern __errno_location


global ft_write

section .text
    ft_write:
        mov rax, 1
        syscall
        cmp rax, 0
        jl .error ; if syscall return value is negative, jump to error
        ret
        
    .error:
        push rbx
        neg rax
        mov rbx, rax ; met la + value de rax dans rbx pour sauvegarder
        call __errno_location wrt ..plt
        mov [rax], rbx ; [rax] = the memory at the address contained in rax
        mov rax, -1 ; rax alone = the number inside the register (could be an address, could be an integer)
        pop rbx
        ret