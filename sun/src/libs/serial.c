#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "lib/io.h"
#include "lib/serial.h"
#define PORT 0x3f8

int serial_init() {
    outb(PORT + 1, 0x00);    // Disable all interrupts
    outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(PORT + 1, 0x00);    //                  (hi byte)
    outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    outb(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
    outb(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

    if(inb(PORT + 0) != 0xAE) {
        return 1;
    }

    outb(PORT + 4, 0x0F);
    return 0;
}

int serial_received() {
    return inb(PORT + 5) & 1;
}

char read_serial() {
    while(serial_received() == 0);

    return inb(PORT);
}

int is_transmit_empty() {
    return inb(PORT +5) & 0x20;
}

void write_serial(char a) {
    if (a == '\n') write_serial('\r');
    while (!is_transmit_empty());
    outb(PORT, a);
}

void serial_print(const char* str) {
    while (*str) {
        write_serial(*str++);
    }
}
