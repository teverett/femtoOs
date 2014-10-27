NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
LD=ld
LDARGS=-melf_i386_fbsd -Tlink.ld

# note that boot.o must be first
OBJS=i386/boot.o main.o monitor.o i386/gdt.o string.o i386/interrupt.o process.o i386/isr.o timer.o kheap.o i386/paging.o ordered_array.o i386/task.o i386/syscall.o i386/descriptor_tables.o assert.o i386/io.o mem.o

.SUFFIXES   : .c .s
.c.o        :
	$(CC) $(CCARGS) -c $(.IMPSRC) -o ${.TARGET}
.s.o      :
	$(NASM) -f elf $(.IMPSRC) -o ${.TARGET}      
kernel.elf: $(OBJS) 
	$(LD) $(LDARGS) -o kernel.elf $(OBJS) 
clean:
	rm -rf ${OBJS}
	rm -rf kernel.elf
	rm -rf kernel.bin
