print:                          ; print a line of text to the screen via an interrupt
        mov     ah, 0Eh         ; set interrupt function => print to screen
.repeat:
        lodsb                   ; loads the next character into al
        cmp     al, 0           ; compare al to 0 (nul terminator check)
        je      .done           ; "jump equal" to .done label
        int     10h             ; triggers an interrupt to push out the byte
        jmp     .repeat         ; jump back to the repeat, this is how we loop
.done:
        ret

printNum:                       ;Print a number (ax)
        push    cx
        push    dx
        mov     cx,000Ah        ;divide by 10
        mov     bx, sp
getDigit:
        mov     dx,0            ;puting 0 in the high part of the divided number (DX:AX)
        div     cx              ;DX:AX/cx.  ax=dx:ax/cx  and dx=dx:ax%cx(modulus)
        push    dx
        cmp     ax,0
        jne     getDigit
 
printNmb:
        pop     ax
        add     al, 30h         ;adding the '0' char for printing
        mov     ah,0eh          ;print char interrupt
        int     10h
        cmp     bx, sp
        jne     printNmb
 
        pop     dx
        pop     cx
        ret
clear:                          ; clear the screen via an interrupt
        mov     al, 02h         ; al = 02h, code for video mode (80x25)
        mov     ah, 00h         ; code for the change video mode function
        int     10h             ; trigger interrupt to call function
        ret
        