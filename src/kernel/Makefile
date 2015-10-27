NASM=nasm
NASMARGS=-f elf
CC=cc
CCARGS=-m32  -ffreestanding -fno-builtin -nostdlib
LD=ld
LDARGS=-melf_i386 -Tlink.ld
OBJ_DIR=obj
SRC_ROOT=src

# C sources
SRCS_C=$(shell find $(SRC_ROOT) -type f -iname '*.c')

# assembler sources
SRCS_ASM=$(shell find $(SRC_ROOT) -type f -iname '*.s')

# all sources
SRCS=$(SRCS_ASM)$(SRCS_C)

# obj dirs
OBJS_ASM=$(subst $(SRC_ROOT)/, , $(SRCS_ASM:.s=.o))
OBJS_C=$(subst $(SRC_ROOT)/, , $(SRCS_C:.c=.o))
OBJS=$(addprefix $(OBJ_DIR)/, $(OBJS_ASM) $(OBJS_C))

# set search paths
vpath %.c $(SRC_ROOT)/
vpath %.cpp $(SRC_ROOT)/
vpath %.s $(SRC_ROOT)/

# c files	
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CCARGS) $(EXTRA_CCARGS) -c -o $@ $<

# s files
$(OBJ_DIR)/%.o: %.s
	mkdir -p $(@D)
	$(NASM) $(NASMARGS) -o $@ $< 

kernel.elf: $(OBJS) 
	$(LD) $(LDARGS) -o kernel.elf $(OBJS) 

clean:
	rm -rf ${OBJS}
	rm -rf kernel.elf
	rm -rf kernel.bin
