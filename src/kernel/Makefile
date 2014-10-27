NASM=nasm
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
LD=ld
LDARGS=-melf_i386_fbsd -Tlink.ld

# note that boot.o must be first
OBJS=boot.o main.o monitor.o gdt.o common.o interrupt.o process.o isr.o timer.o kheap.o paging.o ordered_array.o task.o syscall.o descriptor_tables.o 

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
