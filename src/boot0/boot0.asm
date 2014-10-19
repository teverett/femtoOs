
[BITS 16]

_start:
        jmp     word load_kernel

;----------BIOS Parameter Block----------;

TIMES 0Bh-$+_start      DB 0
 
bpbBytesPerSector:      DW 512
bpbSectorsPerCluster:   DB 1
bpbReservedSectors:     DW 1
bpbNumberOfFATs:        DB 2
bpbRootEntries:         DW 224
bpbTotalSectors:        DW 2880
bpbMedia:               DB 0xF0
bpbSectorsPerFAT:       DW 9
bpbSectorsPerTrack:     DW 18
bpbHeadsPerCylinder:    DW 2
bpbHiddenSectors:       DD 0
bpbTotalSectorsBig:     DD 0
bsDriveNumber:          DB 0
bsUnused:               DB 0
bsExtBootSignature:     DB 0x29
bsSerialNumber:         DD 0xa0a1a2a3  
bsVolumeLabel:          DB "FemtoOS    "
bsFileSystem:           DB "FAT12   "

;----------Private Data----------;

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
