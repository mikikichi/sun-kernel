#include "idt.h"
#include "libs/io.h"

unsigned char idtinc;

static idt_entry_t idt[256];

static idtr_t idtr;

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    idt_entry_t* descriptor = &idt[vector];

    descriptor->isr_low        = (uint64_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08;
    descriptor->ist            = 0;
    descriptor->attributes     = flags;
    descriptor->isr_mid        = ((uint64_t)isr >> 16) & 0xFFFF;
    descriptor->isr_high       = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    descriptor->reserved       = 0;
}

static bool vectors[256];

extern void* isr_stub_table[];

void idt_init() {
    idtr.base = (uintptr_t)&idt;
    idtr.limit = (uint16_t)sizeof(idt) - 1;

    for (uint8_t vector = 0; vector < 32; vector++) {
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
        vectors[vector] = true;
    }

    idtinc = 1;

    __asm__ volatile ("lidt %0" : : "m"(idtr));
    outb(0x21, 0xFF);
    outb(0xA1, 0xFF);
    __asm__ volatile ("sti");
}