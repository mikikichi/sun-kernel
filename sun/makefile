CC := x86_64-elf-gcc       
LD := x86_64-elf-gcc
ASM := nasm
INCLUDE := -I$(HOME)/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -I$(HOME)/sun-kernel/sun/src/libs -I$(HOME)/sun-kernel/sun/src/terminal -I$(HOME)/sun-kernel/sun/src/idt 
INCLUDEASM := $(HOME)/sun-kernel/sun/src

LINKSCRIPT := -T linker.ld
ASMFLAGS := -f elf64
CFLAGS := -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone

LINKERFLAGS := -ffreestanding -O2 -nostdlib
WARNFLAGS := -Wall -Werror

ROOT := $(HOME)/sun-kernel/sun
SRCDIRECTORIES := $(ROOT)/src 
COMPILED := $(HOME)/sun-kernel/sun/src/compiled
DEPS := $(HOME)/sun-kernel/sun/src/deps

SRCFILES := $(shell find $(SRCDIRECTORIES) -type f -name '*.c')
ASMFILES := $(shell find $(SRCDIRECTORIES) -type f -name "*.s")


OBJFILESC := $(patsubst %.c, %.o, $(SRCFILES))
OBJFILESA := $(patsubst %.s,%.o,$(ASMFILES))


DEPC := $(patsubst %.c,%.d,$(SRCFILES))

-include $(DEPC) 

OBJLIST := $(OBJFILESC) $(OBJFILESA)


all: clean $(OBJFILESC) $(OBJFILESA) link move iso run

.PHONY: clean move link isomove run test


test:
	@"Clearing .d files"
	-@$(RM) $(wildcard $(SRCDIRECTORIES)/*.d)



clean:
	@echo "Cleaning..."
	-@$(RM) $(wildcard $(COMPILED)/*.o)


%.o: %.c 
	@$(CC) $(INCLUDE) $(CFLAGS) $(WARNFLAGS) -MMD -MP -c $< -o $@

%.o: %.s

	@$(ASM) -i $(INCLUDEASM) $(ASMFLAGS) $< -o $@


link: $(OBJLIST)
	@echo "Linking..."
	@$(CC) $(LINKERFLAGS) $(LINKERSCRIPT) -o kernel.bin  $(OBJLIST) -lgcc

move:
	@echo "Moving to compiled"

	-@for file in $(OBJLIST); do \
		mv $$file $(COMPILED); \
	done

	-@for file in $(DEPC); do \
		mv $$file $(DEPS); \
	done


iso:
	@echo "Moving ISO"
	@mv kernel.bin $(HOME)/sun-kernel/sun/isofiles/boot
	@echo "Creating ISO..."

	@grub2-mkrescue -o sun.iso $(HOME)/sun-kernel/sun/isofiles


run: 
	@echo "Running..."
	@qemu-system-x86_64 -cdrom sun.iso
