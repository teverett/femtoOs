
NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
OBJCOPY=objcopy
LD=ld
LDARGS=-melf_i386_fbsd -Ttext 0x1000

kernel.bin: kernel.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary kernel.elf kernel.bin
kernel.elf: main.c monitor/monitor.c interrupt/isr_wrapper.asm io.c std.c interrupt/interrupt_handler.c
	$(CC) $(CCARGS) -c main.c monitor/monitor.c interrupt/interrupt_handler.c io.c std.c
	$(NASM) -f elf interrupt/isr_wrapper.asm -o isr_wrapper.o
	$(NASM) -f elf loader.asm -o loader.o
	$(LD) $(LDARGS) -o kernel.elf loader.o main.o isr_wrapper.o interrupt_handler.o std.o monitor.o io.o
clean:
	rm *.elf *.bin *.o

