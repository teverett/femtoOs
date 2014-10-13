
NASM=nasm
CC=cc

all: floppy.img 

floppy.img: kernel.bin boot.bin
	cat boot.bin kernel.bin /dev/zero | dd bs=512 count=2880 of=floppy.img
loader.o: loader.asm
	$(NASM) -f elf loader.asm -o loader.o
kernel.bin: kernel.elf
	objcopy -R .note -R .comment -S -O binary kernel.elf kernel.bin
kernel.elf: loader.o main.c video.c
	$(CC) -m32  -ffreestanding -fno-builtin -nostdlib -c *.c
	ld -melf_i386_fbsd -Ttext 0x1000 -o kernel.elf loader.o main.o video.o
boot.bin: boot.asm
	$(NASM) -f bin boot.asm -o boot.bin
clean:
	rm *.elf
	rm *.bin
	rm *.o
	rm *.img


