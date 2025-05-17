#!/bin/bash
echo "Compiling..."
cd src
rm -f compiled/*.o
echo "Compiling C files"
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/print.c -o compiled/print.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/io.c -o compiled/io.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c kernel.c -o compiled/kernel.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/log.c -o compiled/log.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/keyboard.c -o compiled/keyboard.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c terminal/terminal.c -o compiled/terminal.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c terminal/programs/exit.c -o compiled/exit.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c terminal/programs/version.c -o compiled/version.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c idt/idt.c -o compiled/idt.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c idt/isr.c -o compiled/isrc.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/string.c -o compiled/string.o
x86_64-elf-gcc -I ~/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -ffreestanding -Wall -Werror -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -c libs/serial.c -o compiled/serial.o
echo "Assembling boot.s"
nasm -f elf64 boot.s -o compiled/boot.o
echo "Assembling mheaders.s"
nasm -f elf64 mheaders.s -o compiled/mheaders.o
echo "Assembling isr.s"
nasm -f elf64 idt/isr.s -o compiled/isr.o
cd compiled
echo "Linking kernel"
x86_64-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib *.o -lgcc --entry=_start

echo "Moving kernel to ISO folder"
mv kernel.bin ../../isofiles/boot/kernel.bin
cd ../../
echo "Creating ISO..."
grub-mkrescue -o sun.iso isofiles
echo Ignore errors about grub2, this is for compatibility with Fedora Linux
grub2-mkrescue -o sun.iso isofiles
echo running...
qemu-system-x86_64 -d int,cpu_reset -D qemu-debug.log -cdrom sun.iso
