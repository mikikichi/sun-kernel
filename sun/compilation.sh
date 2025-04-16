#!/bin/bash

echo Compiling...
echo root privelleges WILL be required
cd src
sudo nasm -f elf64 boot.s -o compiled/boot.o
sudo nasm -f elf64 mheaders.s -o compiled/mheaders.o
sudo nasm -f elf64 print.s -o compiled/print.o
cd compiled
ld -m elf_x86_64 -T linker.ld *.o -o kernel.bin
mv kernel.bin ../../isofiles/boot/kernel.bin
cd ../../
grub-mkrescue -o cosmix.iso isofiles