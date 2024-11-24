i686-elf-as os/boot.s -o bin/boot.o

i686-elf-gcc -c os/kernel.c -o bin/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

i686-elf-gcc -T linker.ld -o bin/sun.bin -ffreestanding -O2 -nostdlib bin/boot.o bin/kernel.o bin/print.o  -lgcc

grub-file --is-x86-multiboot bin/sun.bin
