
[BITS 16]

_start:
        jmp     word load_kernel; Load the OS Kernel
        
drive           db 0            ; Used to store boot device
readcnt         db 0            ; Used to store bytes read

welcome         db "FemtoOs",13,10,0        
readsectors     db " Sectors read",13,10,0
;----------Bootsector Code----------;
  
load_kernel:
        mov     [drive], dl     ; Store boot disk
        
        call    clear           ; our routine to clear the screen

        mov     si, welcome     ; load the welcome message
        call    puts            ; call our puts function

        call    read_disk       ; Load the OS into memory
        cli                     ; Disable interrupts, we want to be alone
        mov     al, [readcnt]   ; get the read count
        mov     ah, 0
        call    printNum        ; print it
        mov     si, readsectors
        call    puts
       
        jmp     enter_pm        ; enter protected mode
        hlt

clear:                          ; clear the screen via an interrupt
        mov     al, 02h         ; al = 02h, code for video mode (80x25)
        mov     ah, 00h         ; code for the change video mode function
        int     10h             ; trigger interrupt to call function
        ret
                               
puts:                           ; print a line of text to the screen via an interrupt
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

read_disk:
        mov     ah, 0           ; RESET-command
        int     13h             ; Call interrupt 13h
        or      ah, ah          ; Check for error code
        jnz     read_disk       ; Try again if ah != 0
        mov     ax, 0
        mov     ax, 0                               
        mov     es, ax                              
        mov     bx, 0x1000      ; Destination address = 0000:1000

        mov     ah, 02h         ; READ SECTOR-command
        mov     al, 40h         ; Number of sectors to read (0x40 = 64 sectors = 32k)
        mov     dl, [drive]     ; Load boot disk
        mov     ch, 0           ; Cylinder = 0
        mov     cl, 2           ; Starting Sector = 3
        mov     dh, 0           ; Head = 1
        int     13h             ; Call interrupt 13h
        or      ah, ah          ; Check for error code
        jnz     load_kernel     ; Try again if ah != 0
        mov     [readcnt],al    ; save read count
        ret

enter_pm:
        xor     ax, ax          ; Clear AX register
        mov     ds, ax          ; Set DS-register to 0 - used by lgdt

        lgdt    [gdt_desc]      ; Load the GDT descriptor 
        
;----------Entering Protected Mode----------;
                
        mov     eax, cr0         ; Copy the contents of CR0 into EAX
        or      eax, 1           ; Set bit 0     (0xFE = Real Mode)
        mov     cr0, eax         ; Copy the contents of EAX into CR0
        
        jmp     08h:kernel32    ; Jump to code segment, offset kernel32
        
[BITS 32]                       ; We now need 32-bit instructions
kernel32:
        mov     ax, 10h         ; Save data segment identifyer
        mov     ds, ax          ; Move a valid data segment into the data segment register
        mov     ss, ax          ; Move a valid data segment into the stack segment register
        mov     esp, 090000h    ; Move the stack pointer to 090000h
        
        jmp     08h:0x1000      ; Jump to section 08h (code), offset 01000h
        
%include "gdt.inc"

times 510-($-$$) db 0          ; Fill up the file with zeros

dw 0AA55h                       ; Boot sector identifyer
