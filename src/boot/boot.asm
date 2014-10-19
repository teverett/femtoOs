
[BITS 16]

_start:
        jmp     word load_kernel; Load the OS Kernel
        
drive           db 0            ; Used to store boot device
readcnt         db 0            ; Used to store bytes read

welcome         db "FemtoOs",13,10,0        
readsectors     db " sectors read",13,10,0
;----------Bootsector Code----------;
  
load_kernel:
        mov     [drive], dl     ; Store boot disk
        
        call    clear           ; our routine to clear the screen

        mov     si, welcome     ; load the welcome message
        call    print           

        call    read_disk       ; Load the OS into memory
        cli                     ; Disable interrupts, we want to be alone
        mov     al, [readcnt]   ; get the read count
        mov     ah, 0
        call    printNum        ; print it
        mov     si, readsectors
        call    print
       
        jmp     enter_pm        ; enter protected mode
        hlt

%include "screen.inc"
%include "disk.inc"                               

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
