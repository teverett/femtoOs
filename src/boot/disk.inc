
read_disk:
        mov     ah, 0           ; RESET-command
        int     13h             ; Call interrupt 13h
        or      ah, ah          ; Check for error code
        jnz     read_disk       ; Try again if ah != 0

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

