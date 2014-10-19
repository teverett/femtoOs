
NASM=nasm
OBJS=boot.o
OBJCOPY=objcopy
LD=ld
LDARGS=-melf_i386_fbsd -Ttext 0x7c00

.SUFFIXES   : .asm 

.asm.o      :
	$(NASM) -f elf $(.IMPSRC) -o ${.TARGET}      

boot.bin: boot.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary boot.elf boot.bin
boot.elf: $(OBJS) 
	$(LD) $(LDARGS) -o boot.elf $(OBJS) 
clean:
	rm -rf ${OBJS}
	rm -rf boot.elf
	rm -rf boot.bin
