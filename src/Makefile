
all: floppy.img
floppy.img: boot/boot.bin kernel/kernel.bin
	cat boot/boot.bin kernel/kernel.bin /dev/zero | dd bs=512 count=2880 of=floppy.img
kernel/kernel.bin:
	make -C kernel
boot/boot.bin:
	make -C boot
clean:
	rm *.img

