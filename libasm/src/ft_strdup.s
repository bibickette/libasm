bits 64

extern malloc
extern ft_strlen
extern ft_strcpy



global ft_strdup

section .text
    ft_strdup:
        push rbx
        mov rbx, rdi ; sauvegarder le rdi : src
        call ft_strlen ; calculer len src

        inc rax ; ajouter 1 pour le \0
        mov rdi, rax ; result dans arg0 pour malloc
        call malloc wrt ..plt ; et larg 0 cest le len
        test rax, rax ; test si result malloc null
        jz .error

        mov rdi, rax ; on met dans arg 0 notre dest
        mov rsi, rbx ; on met dans arg 1 notre src quon a save dans rbx
        call ft_strcpy ; on copy src sur dest

        pop rbx
        ret
        
    .error:
        xor rax, rax
        pop rbx
        ret