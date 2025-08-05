#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "lib/io.h"
#include "lib/serial.h"
#define PORT 0x3f8 //com1 serial keyboard

int serial_init() {
    io_outb_8(PORT + 1, 0x00);    // Disable all interrupts
    io_outb_8(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    io_outb_8(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    io_outb_8(PORT + 1, 0x00);    //                  (hi byte)
    io_outb_8(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
    io_outb_8(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    io_outb_8(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
    io_outb_8(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
    io_outb_8(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

    if(io_inb_8(PORT + 0) != 0xAE) {
        return 1;
    }

    io_outb_8(PORT + 4, 0x0F);
    return 0;
}

int serial_received() {
    return io_inb_8(PORT + 5) & 1;
}

char read_serial() {
    while(serial_received() == 0);

    return io_inb_8(PORT);
}

int is_transmit_empty() {
    return io_inb_8(PORT +5) & 0x20;
}

void write_serial(char a) {
    if (a == '\n') write_serial('\r');
    while (!is_transmit_empty());
    io_outb_8(PORT, a);
}

void serial_print(const char* str) {
    while (*str) {
        write_serial(*str++);
    }
}
