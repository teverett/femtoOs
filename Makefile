
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
loader.o: $(SRC)/loader.asm
	$(NASM) -f elf $(SRC)/loader.asm -o loader.o
kernel.bin: kernel.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary kernel.elf kernel.bin
boot.bin: $(SRC)/boot.asm
	$(NASM) -f bin $(SRC)/boot.asm -o boot.bin
kernel.elf: loader.o $(SRC)/main.c $(SRC)/video.c $(SRC)/isr_wrapper.asm
	$(CC) $(CCARGS) -c $(SRC)/*.c
	$(NASM) -f elf $(SRC)/isr_wrapper.asm -o isr_wrapper.o
	$(LD) $(LDARGS) -o kernel.elf loader.o main.o video.o isr_wrapper.o interrupt_handler.o
clean:
	rm *.elf *.bin *.o *.img
