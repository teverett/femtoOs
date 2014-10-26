#!/bin/sh
set -e

IMAGE=femtoos.img
TMP=/tmp/femtoos

rm -f $IMAGE
make clean
make
dd bs=512 count=28800 of=$IMAGE if=/dev/zero
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
umount $TMP
mdconfig -u 0 -d




