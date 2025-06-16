Sun - a kernel made of ducttape and prayers

# Documentation
Here's the build instructions

# Requirements
* nasm
* x86_64 cross compiler (gcc AND binutils, https://wiki.osdev.org/GCC_Cross-Compiler)
* ld (part of binutils)
* clang 12 or later
* qemu (or any other virtualisation software)
* xorriso
* grub-mkrescue (part of grub package)


# Compile the OS
run make all to get a full and complete sun kernel iso

# Compile individual files
to compile individual files, i personally recommend you use nasm (i can't make you but its all nasm syntax) on a unix like
operating system, the target is elf64 and the linker.ld is in /sun 

# Windows users
install a unix compatibility layer like Cygwin (https://www.cygwin.com/) or WSL2 and work on it like your using Linux.
but realistically it is MUCH easier to do Operating System Development on something like Linux or macOS - in the future
id strongly recommend using one of these (or even a BSD or some other unix like)

# File Layout
* in src/ you will find all the uncompiled source code
* in src/compiled, you will find linker.ld. compilation.sh builds to here, so it is recommended you do too
* in isofiles/build you will find kernel.bin. all kernel.bin files must go here when making an iso.
* in isofiles/build/grub you will find the grub configuration file, here you can edit the name or boot options.

# Issues, complaints, etc
Put them in the issues tab on GitHub.

# Credits
* https://github.com/GBX9570/sun-kernel/
* GBX9570 - Project leader/Programmer
* Ghatt-O - Programmer
* mikikichi - Programmer
