NASM=nasm
NASMARGS=-f elf
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
LD=ld
LDARGS=-melf_i386 -Tlink.ld

# C sources
SRCS_C=$(shell find $(SRC_ROOT) -type f -iname '*.c')

# assembler sources
SRCS_ASM=$(shell find $(SRC_ROOT) -type f -iname '*.s')

# obj dirs
OBJS_ASM=$(subst $(SRC_ROOT)/, , $(SRCS_ASM:.s=.o))
OBJS_C=$(subst $(SRC_ROOT)/, , $(SRCS_C:.c=.o))

# c files	
%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CCARGS) $(EXTRA_CCARGS) -c -o $@ $<

# s files
%.o: %.s
	mkdir -p $(@D)
	$(NASM) $(NASMARGS) -o $@ $< 

kernel.elf: $(OBJS) 
	$(LD) $(LDARGS) -o kernel.elf $(OBJS) 
	
clean:
	rm -rf ${OBJS}
	rm -rf kernel.elf
	rm -rf kernel.bin
