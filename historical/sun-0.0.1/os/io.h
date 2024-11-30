#ifndef IO_H
#define IO_H

#include <stdint.h>

// Define outb function
static inline void outb(uint16_t port, uint8_t value) {
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

#endif // IO_H
