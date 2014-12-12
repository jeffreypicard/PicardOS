#!/bin/sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp kernel/kernel.bin isodir/boot/kernel.bin
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "PicardOS" {
        multiboot /boot/kernel.bin
}
EOF
grub-mkrescue -o PicardOS.iso isodir
