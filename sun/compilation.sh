#!/bin/bash
set -e 
echo "Compiling..."
echo "Root privileges WILL be required"
cd src
rm -f compiled/*.o
echo "Compiling C files"
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/print.c -o compiled/print.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/io.c -o compiled/io.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c kernel.c -o compiled/kernel.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/log.c -o compiled/log.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/keyboard.c -o compiled/keyboard.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c terminal/terminal.c -o compiled/terminal.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c terminal/programs/exit.c -o compiled/exit.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/14.2.0/include -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c terminal/programs/version.c -o compiled/version.o
echo "Assembling boot.s"
nasm -f elf64 boot.s -o compiled/boot.o
echo "Assembling mheaders.s"
nasm -f elf64 mheaders.s -o compiled/mheaders.o
cd compiled
echo "Linking kernel"
x86_64-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib *.o -lgcc
echo "Moving kernel to ISO folder"
mv kernel.bin ../../isofiles/boot/kernel.bin
cd ../../
echo "Creating ISO..."
grub-mkrescue -o cosmix.iso isofiles
