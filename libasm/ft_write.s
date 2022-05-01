section.text:
    extern ___error
    global _ft_write

_ft_write:
	mov     rax, 0x2000004
	syscall
	jc		exit_error
	ret

exit_error:
    push    rax
    call    ___error
	pop		rdx
    mov     [rax], rdx
    mov     rax, -1
    ret