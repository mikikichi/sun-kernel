#!/bin/bash
set -e 
echo "Compiling..."
echo "Root privileges WILL be required"
cd src
rm -f compiled/*.o
echo "Compiling kernel.c"
x86_64-elf-gcc -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c kernel.c -o compiled/kernel.o
echo "Assembling boot.s"
nasm -f elf64 boot.s -o compiled/boot.o
echo "Assembling mheaders.s"
nasm -f elf64 mheaders.s -o compiled/mheaders.o
echo "Assembling print.s"
nasm -f elf64 print.s -o compiled/print.o
cd compiled
echo "Linking kernel"
x86_64-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib *.o -lgcc
echo "Moving kernel to ISO folder"
mv kernel.bin ../../isofiles/boot/kernel.bin
cd ../../
echo "Creating ISO..."
grub-mkrescue -o cosmix.iso isofiles
