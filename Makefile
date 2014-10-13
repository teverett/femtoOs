
NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
OBJCOPY=objcopy
LD=ld
LDARGS=-melf_i386_fbsd -Ttext 0x1000

all: floppy.img
floppy.img: kernel.bin boot.bin
	cat boot.bin kernel.bin /dev/zero | dd bs=512 count=2880 of=floppy.img
loader.o: loader.asm
	$(NASM) -f elf loader.asm -o loader.o
kernel.bin: kernel.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary kernel.elf kernel.bin
boot.bin: boot.asm
	$(NASM) -f bin boot.asm -o boot.bin
kernel.elf: loader.o main.c video.c
	$(CC) $(CCARGS) -c *.c
	$(LD) $(LDARGS) -o kernel.elf loader.o main.o video.o
clean:
	rm *.elf *.bin *.o *.img
