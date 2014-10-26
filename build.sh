#!/bin/sh
set -e

IMAGE=femtoos.img
ISO=femtoos.iso
TMP=/tmp/femtoos
IMAGESIZE=10000

#
# remove old file
#
rm -f $IMAGE
rm -f $ISO

#
# build kernel
#
make clean
make

#
# make .img file, with the kernel and with grub
#
dd bs=1k count=$IMAGESIZE of=$IMAGE if=/dev/zero
mdconfig -a -t vnode -f $IMAGE -u 0
gpart create -s MBR  /dev/md0
gpart add -t fat32 -b 512k /dev/md0
gpart set -a active -i 1 /dev/md0
newfs_msdos -L femtoos /dev/md0s1
mkdir -p $TMP
mount_msdosfs /dev/md0s1 $TMP
grub-install --boot-directory=$TMP/boot/ --allow-floppy --modules="normal part_msdos multiboot" /dev/md0 
cp src/kernel/kernel.elf $TMP/boot/kernel
cp src/grub/* $TMP/boot/grub/

#
# make .iso file
#
#mkisofs -v -R -J -iso-level 3 -o $ISO $TMP

#
# unmount 
#
umount $TMP
mdconfig -u 0 -d




