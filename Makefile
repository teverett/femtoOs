
NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
OBJCOPY=objcopy
LD=ld
LDARGS=-melf_i386_fbsd -Ttext 0x1000
SRC=src

all: floppy.img
floppy.img: kernel.bin boot.bin
	cat boot.bin kernel.bin /dev/zero | dd bs=512 count=2880 of=floppy.img
kernel.bin: kernel.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary kernel.elf kernel.bin
boot.bin: $(SRC)/boot/boot.asm
	$(NASM) -f bin $(SRC)/boot/boot.asm -o boot.bin
kernel.elf: $(SRC)/kernel/main.c $(SRC)/kernel/monitor/monitor.c $(SRC)/kernel/interrupt/isr_wrapper.asm $(SRC)/kernel/io.c $(SRC)/kernel/std.c $(SRC)/kernel/interrupt/interrupt_handler.c
	$(CC) $(CCARGS) -c $(SRC)/kernel/main.c $(SRC)/kernel/monitor/monitor.c $(SRC)/kernel/interrupt/interrupt_handler.c $(SRC)/kernel/io.c $(SRC)/kernel/std.c
	$(NASM) -f elf $(SRC)/kernel/interrupt/isr_wrapper.asm -o isr_wrapper.o
	$(NASM) -f elf $(SRC)/kernel/loader.asm -o loader.o
	$(LD) $(LDARGS) -o kernel.elf loader.o main.o isr_wrapper.o interrupt_handler.o std.o monitor.o io.o
clean:
	rm *.elf *.bin *.o *.img
