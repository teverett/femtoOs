NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
OBJCOPY=objcopy
LD=ld
LDARGS=-melf_i386_fbsd -Ttext 0x1000
OBJS=loader.o main.o string.o mem.o monitor/monitor.o io.o gdt.o gdtf.o idt.o idtf.o interrupt.o isr.o devices/timer/timer.o devices/keyboard/keyboard.o devices/rtc/rtc.o

.SUFFIXES   : .c .asm 
.c.o        :
	$(CC) $(CCARGS) -c $(.IMPSRC) -o ${.TARGET}
.asm.o      :
	$(NASM) -f elf $(.IMPSRC) -o ${.TARGET}      

kernel.bin: kernel.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary kernel.elf kernel.bin
kernel.elf: $(OBJS) 
	$(LD) $(LDARGS) -o kernel.elf $(OBJS) 
clean:
	rm -rf ${OBJS}
	rm -rf kernel.elf
	rm -rf kernel.bin

