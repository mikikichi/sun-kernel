CC := /mnt/d/HorizonOS/deps/llvm/build/bin/clang       
LD := /mnt/d/HorizonOS/deps/llvm/build/bin/ld.lld
ASM := nasm

INCLUDE := -Isrc -Ideps/freestand-c-hdrs/x86_64/include
INCLUDEASM := src

ASMFLAGS := -f elf64 -g
CFLAGS := -ffreestanding -m64 -O2 -g -nostdlib -nostdinc -fno-exceptions -fno-rtti -fno-omit-frame-pointer -march=x86-64 -fPIE -fPIC -mno-red-zone -mgeneral-regs-only -static --target=x86_64-none-elf

LINKSCRIPT := -T res/linker.ld
LINKERFLAGS := -static -nostdlib
WARNFLAGS := -Wall -Werror

SRCDIRECTORIES := src 
COMPILED := out
ISODIR := iso

KERNEL := $(ISODIR)/root/boot/kernel.bin

SRCFILES := $(shell find $(SRCDIRECTORIES) -type f -name '*.c')
ASMFILES := $(shell find $(SRCDIRECTORIES) -type f -name "*.s")

OBJFILESC := $(patsubst src/%.c, out/%.c.o, $(SRCFILES))
OBJFILESA := $(patsubst src/%.s, out/%.s.o, $(ASMFILES))

DEPC := $(patsubst src/%.c, out/%.c.d, $(SRCFILES))

-include $(DEPC) 

OBJLIST := $(OBJFILESC) $(OBJFILESA)

all: iso

.PHONY: clean

clean:
	@echo "Cleaning..."
	@rm -rf $(COMPILED) $(ISODIR)

out/%.c.o: src/%.c 
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDE) $(CFLAGS) $(WARNFLAGS) -MMD -MP -c $< -o $@

out/%.s.o: src/%.s
	@echo "Assembling $<"
	@mkdir -p $(dir $@)
	@$(ASM) -i $(INCLUDEASM) $(ASMFLAGS) $< -o $@

$(KERNEL): $(OBJLIST)
	@echo "Linking..."
	@mkdir -p $(ISODIR)/root/boot
	@$(LD) $(LINKERFLAGS) $(LINKERSCRIPT) -o $(ISODIR)/root/boot/kernel.bin $(OBJLIST)

iso: $(KERNEL)
	@echo "Creating ISO..."
	@cp -r res/grub $(ISODIR)/root/boot
	@mkdir -p $(ISODIR)/out
	@grub-mkrescue -o $(ISODIR)/out/Sun.iso $(ISODIR)/root

run: 
	@echo "Running..."
	@qemu-system-x86_64 -cdrom $(ISODIR)/out/Sun.iso
