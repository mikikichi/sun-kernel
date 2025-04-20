
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "print.h"
#include "log.h"

const size_t VGA_WIDTH = 80;
const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_colour;
uint16_t* terminal_buffer;

uint8_t vga_entry_colour(enum vga_colour fg, enum vga_colour bg) {
    return fg | bg << 4;
    func("vgaentrycolour");
}

uint16_t vga_entry(unsigned char uc, uint8_t colour) {
    return (uint16_t) uc | (uint16_t) colour << 8;
    func("vgaentry");
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
    func("strlen");
}

void clear(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_colour = vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_colour);
            func("clear");
        }
    }
}

void printcolour(uint8_t colour) {
    terminal_colour = colour;
    func("printcolour");
}

void terminal_putentryat(char c, uint8_t colour, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, colour);
    func("terminal_putentryat");
}

void terminal_putchar(char c) {
    if (c == '\n') {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_row = 0;
        }
    } else {
        terminal_putentryat(c, terminal_colour, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH) {
            terminal_column = 0;
            if (++terminal_row == VGA_HEIGHT)
                terminal_row = 0;
        }
        func("terminal_putchar");
    }
}


void terminal_write(const char* data, size_t size) {
    func("terminal_write");
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void printf(const char* data) {
    terminal_write(data, strlen(data));
    func("printf");
}

// repurposed from old broken build of Sun Kernel because this was the only part that worked properly lmfao