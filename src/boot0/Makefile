
NASM=nasm
OBJS=boot0.o
OBJCOPY=objcopy
LD=ld
LDARGS=-melf_i386_fbsd -Ttext 0x7c00

.SUFFIXES   : .asm 

.asm.o      :
	$(NASM) -f elf $(.IMPSRC) -o ${.TARGET}      

boot0.bin: boot0.elf
	$(OBJCOPY) -R .note -R .comment -S -O binary boot0.elf boot0.bin
boot0.elf: $(OBJS) 
	$(LD) $(LDARGS) -o boot0.elf $(OBJS) 
clean:
	rm -rf ${OBJS}
	rm -rf boot0.elf
	rm -rf boot0.bin
