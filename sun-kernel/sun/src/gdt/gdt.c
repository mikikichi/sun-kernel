#include <stdbool.h>
#include <stdint.h>
#include "../libs/print.h"
#include "../libs/log.h"

struct GDT {
    uint32_t limit;
    uint32_t base;
    uint8_t access_byte;
    uint8_t flags;
} __attribute__((packed));

void GDTencode(uint8_t *target, struct GDT source) {
    if(source.limit > 0xFFFFF) {
        fatal("the GDT cannot encode limits larger than 0xFFFFF");
    }

    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;
    
    target[5] = source.access_byte;

    target[6] = (source.limit >> 16) & 0x0F;
    target[6] |= (source.flags << 4);
}

struct GDT gdt[] = {
    {0, 0, 0, 0}, // null descriptor

    //

    {
        0xFFFF,
        0x0000,
        0x9A,
        0xCF
    },

    {
        0xFFFF,
        0x0000,
        0x92,
        0xCF
    },
};