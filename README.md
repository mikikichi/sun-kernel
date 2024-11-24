# Sun Kernel
The Sun Kernel Source Tree

# Building
To build, run `build.sh` then `mkiso.sh` as root and finally `run.sh`
ignore the errors, it *should* build fine

alternatively, just run `automate.sh` and it will do it all for you (sudo privelleges required)

you do require an 1686-elf cross-compiler, look at this to find out how to set it up: https://wiki.osdev.org/GCC_Cross-Compiler
please note that you require a Unix environment (specifically, Linux but could run on other ones) for these scripts to work

# File organisation
the 'os' folder contains every part of the kernel in C code
the 'bin' folder is where all the compiled binaries are

# Credits
Most things here are original, but some things have been taken from other sources, so here is the credits:
OSDev Guide (https://wiki.osdev.org/Expanded_Main_Page)
GhattOS 2.0 and Ghatto (https://github.com/ghatt-o/GhattOSv2)
ChatGPT (https://chatgpt.com/)

# Licensing
The Sun Kernel is licensed under the GPL 3.0 license, which in short means:
1. You must use the GPL 3.0 License if you plan on using this for use in other projects.

2. You cannot use this project to make close sourced or proprietary software, or make this project closed source or proprietary.

3. You must retain the original copyright notices as listed in this file and/or in the licenses file, including credit to the original contributers.

For a comprehensive list of the GPL 3.0 license, check in the licenses file above or go to https://www.gnu.org/licenses/gpl-3.0.en.html.

As of the terms of GPL 3.0, we cannot require you give credit in any use of this code outside of this project, however we politely request that you do to help support and continue the Sun and Cosmix project.
