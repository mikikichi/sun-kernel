i686-elf-as os/boot.s -o bin/boot.o
i686-elf-gcc -c os/vgabuffer.c -o bin/vgabuffer.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c os/log.c -o bin/log.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c os/kernel.c -o bin/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra


i686-elf-gcc -T linker.ld -o bin/sun.bin -ffreestanding -O2 -nostdlib bin/boot.o bin/kernel.o bin/vgabuffer.o bin/log.o -lgcc

grub-file --is-x86-multiboot bin/sun.bin
echo if 1 is echoed then the bin file is NOT multiboot. if 0 is echoed then the file IS multiboot
echo $?
