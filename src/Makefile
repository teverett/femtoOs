
all: floppy.img
floppy.img: boot0/boot0.bin kernel/kernel.bin
	cat boot0/boot0.bin kernel/kernel.bin /dev/zero | dd bs=512 count=2880 of=floppy.img
kernel/kernel.bin:
	make -C kernel
boot0/boot0.bin:
	make -C boot0
clean:
	make -C kernel clean
	make -C boot0 clean
	rm -rf *.img

