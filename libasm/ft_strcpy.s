section.text:
    global _ft_strcpy

_ft_strcpy:
    push    rdx
    push    rcx
    mov     rdx, 0x0
    mov     rcx, 0x0
    cmp     rsi, byte 0x0
    jz      _null_input
    cmp     rdi, byte 0x0
    jz      _null_input
    _loop_start:
        mov     dl, byte [rsi + rcx]
        mov     byte [rdi + rcx], dl
        cmp     byte [rsi + rcx], byte 0x0
        jz      _loop_end
        inc     rcx
        jmp     _loop_start
    _loop_end:
    mov     rax, rdi
    pop     rdx
    pop     rcx
    ret

_null_input:
    mov     rax, rsi
    pop     rdx
    pop     rcx
    ret