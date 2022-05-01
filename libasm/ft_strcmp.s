section.text:
    global _ft_strcmp

_ft_strcmp:
    push    rdx
    push    rcx
    mov     rdx, 0x0
    mov     rcx, 0x0
    cmp     rdi, 0x0
    jz      _is_null
    cmp     rsi, 0x0
    jz      _is_null
    _loop_start:
        cmp [rdi + rcx], byte 0x0
		jz _rdi_end
		cmp [rsi + rcx], byte 0x0
		jz _ret_num
		mov dl, byte [rdi + rcx]
		cmp dl, byte [rsi + rcx]
		jg _ret_num
		jb _ret_neg
		inc rcx
		jmp _loop_start
    _loop_end:
    pop     rdx
    pop     rcx
    ret

_is_null:
	cmp     rdi, rsi
	jg      _ret_num
	jb      _ret_neg
	jmp     _ret_equal

_ret_neg:
	pop     rdx
	pop     rcx
	mov     rax, -1
	ret

_ret_num:
	pop     rdx
	pop     rcx
	mov     rax, 1
	ret

_ret_equal:
	pop     rdx
	pop     rcx
	mov     rax, 0
	ret

_rdi_end:
    cmp     [rsi + rcx], byte 0x0
    jz      _ret_equal
    jmp     _ret_neg
