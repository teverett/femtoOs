NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
LD=ld
LDARGS=-melf_i386_fbsd -Tlink.ld
OBJS=boot.o main.o string.o mem.o devices/monitor/monitor.o io.o gdt.o gdtf.o idt.o idtf.o interrupt.o isr.o devices/timer/timer.o devices/keyboard/keyboard.o devices/rtc/rtc.o kheap.o paging.o assert.o pagingf.o ordered_array.o

.SUFFIXES   : .c .asm 
.c.o        :
	$(CC) $(CCARGS) -c $(.IMPSRC) -o ${.TARGET}
.asm.o      :
	$(NASM) -f elf $(.IMPSRC) -o ${.TARGET}      
kernel.elf: $(OBJS) 
	$(LD) $(LDARGS) -o kernel.elf $(OBJS) 
clean:
	rm -rf ${OBJS}
	rm -rf kernel.elf
	rm -rf kernel.bin

