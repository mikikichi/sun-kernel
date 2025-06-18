CC := x86_64-elf-gcc
ASM := nasm

ASMFLAGS := -f elf64
CFLAGS := -ffreestanding -m64 -nostdlib -nostdinc -fno-pie -fno-pic -fno-stack-protector -mno-red-zone -g
WARNFLAGS := -Wall -Werror

ROOT := $(CURDIR)
COMPILED := $(ROOT)/src/compiled
DEPS := $(ROOT)/src/deps
SOURCES := $(ROOT)/src
HEADER := -I$(HOME)/opt/cross/lib/gcc/x86_64-elf/15.1.0/include -I$(ROOT)/src/headers
INCLUDEASM := $(ROOT)/src


SRCFILES := $(shell find $(SOURCES) -name '*.c')
ASMFILES := $(shell find $(SOURCES) -name "*.s")

DP := $(ROOT)/src/deps
OBJFILESC := $(patsubst %.c, %.o, $(SRCFILES))
OBJFILESA := $(patsubst %.s, %.o, $(ASMFILES))


DEPC := $(patsubst %.c,%.d,$(SRCFILES))

-include $(DEPC) 

OBJLIST := $(OBJFILESC) $(OBJFILESA)


all: clean $(OBJFILESC) $(OBJFILESA) link move iso run

.PHONY: clean move link isomove run test



clean:
	@echo "Cleaning..."
	-@$(RM) $(wildcard $(COMPILED)/*.o)
	-@$(RM) $(wildcard $(DP)/*.d)


%.o: %.c 
	@$(CC) $(HEADER) $(CFLAGS) $(WARNFLAGS) -MMD -MP -c $< -o $@

%.o: %.s

	@$(ASM) -i $(INCLUDEASM) $(ASMFLAGS) $< -o $@


link: $(OBJLIST)
	@echo "Linking..."
	@x86_64-elf-ld -T linker.ld -o kernel.bin $(OBJLIST)

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
