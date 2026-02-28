.text
.global sum_all
.type sum_all, @function
#%rdi = arr
#%rsi = size

sum_all:
    xor %eax, %eax
    xor %ecx, %ecx

.Lloop:
    cmp %rsi, %rcx
    jge .Ldone

    mov (%rdi, %rcx, 4), %edx
    add %edx, %eax

    inc %rcx
    jmp .Lloop

.Ldone:
    ret

.section .note.GNU-stack,"",@progbits