# Documentation
okay nerds here is the actual serious readme

# Requirements

# Compile the OS
run compilation.sh to get a full and complete sun kernel iso

# Compile individual files
to compile individual files, i personally recommend you use nasm (i can't make you but its all nasm syntax) on a unix like
operating system, the target is elf32 and the linker.ld is in src/compiled - that folder is there for a reason please use it

# Windows users
install a unix compatibility layer like Cygwin (https://www.cygwin.com/) or WSL2 and work on it like your using Linux.
but realistically it is MUCH easier to do Operating System Development on something like Linux or macOS - in the future
id strongly recommend using one of these (or even a BSD or some other unix like)

# File Layout
in src/ you will find all the uncompiled source code
in src/compiled, you will find linker.ld. compilation.sh builds to here, so it is recommended you do too
in isofiles/build you will find kernel.bin (when using compilation.sh). all kernel.bin files must go here when making an iso.
in isofiles/build/grub you will find the grub configuration file, here you can edit the name or boot options.
compilation.sh provides a good example on how to compile the OS, and can be copied if compiling manually for whatever reason.

# Issues, complaints, etc
Put them in the issues tab on GitHub.

# Credits
https://github.com/GBX9570/sun-kernel/
GBX9570 - Project leader/Programmer
Ghatt-O - Programmer
