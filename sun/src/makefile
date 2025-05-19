CC := x86_64-elf-gcc       
LD := x86_64-elf-gcc
ASM := nasm
INCLUDE := -I$(HOME)/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -I$(ROOT)/src/libs -I$(ROOT)/src/terminal -I$(ROOT)/src/idt
INCLUDEASM := $(HOME)/sun-kernel/sun/src

LINKFLAGS := -T linker.ld
ASMFLAGS := -f elf64
CFLAGS := -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone

LINKER := -ffreestanding -O2 -nostdlib
WARNFLAGS := -Wall -Werror

ROOT := $(HOME)/sun-kernel/sun
SRCDIRECTORIES := $(ROOT)/src $(ROOT)/src/terminal $(ROOT)/src/terminal/programs $(ROOT)/src/libs $(ROOT)/src/idt
COMPILED := $(ROOT)/src/compiled

SRCFILES := $(shell find $(SRCDIRECTORIES) -type f -name "*.c")
ASMFILES := $(shell find $(SRCDIRECTORIES) -type f -name "*.s")


OBJFILESC := $(patsubst %.c, %.o, $(SRCFILES))
OBJFILESA := $(patsubst %.s,%.o,$(ASMFILES))


DEPC := $(patsubst %.c,%.d,$(SRCFILES))

-include $(DEPC) 

OBJLIST := $(OBJFILESC) $(OBJFILESA)

OBJLINK := $(wildcard $(COMPILED)/*.o)

all: clean $(OBJFILESC) $(OBJFILESA) move link isomove run

.PHONY: clean move link isomove run

clean:
	@echo "Cleaning..."
	-@$(RM) $(wildcard $(COMPILED)/*.o)


%.o: %.c 
	@$(CC) $(INCLUDE) $(CFLAGS) $(WARNFLAGS) -MMD -MP -c $< -o $@

%.o: %.s

	-@$(ASM) -i $(INCLUDEASM) $(ASMFLAGS) $< -o $@

move:
	@echo "Moving to compiled"

	-@for file in $(OBJLIST); do \
		mv $$file $(COMPILED); \
	done

link: $(OBJLINK)
	@echo "Linking..."
	@$(CC) $(LINKER) -o kernel.bin $(FLAGSLINK) $< -lgcc

isomove:
	@echo "Moving ISO"
	@mv kernel.bin $(HOME)/sun-kernel/sun/isofiles/boot

grubiso:
	@grub2-mkrescue -o sun.iso isofiles

run: 
	@qemu-system-x86_64 -cdrom sun.iso
