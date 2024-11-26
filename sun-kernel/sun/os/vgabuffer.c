#include "vgabuffer.h"
#include "io.h"

const size_t VGA_WIDTH = 80;
const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_colour;
uint16_t* terminal_buffer;

uint8_t vga_entry_colour(enum vga_colour fg, enum vga_colour bg) {
    return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t colour) {
    return (uint16_t) uc | (uint16_t) colour << 8;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

int strcmp(const char *s1, const char *s2) {
	const unsigned char *p1 = ( const unsigned char * )s1;
	const unsigned char *p2 = ( const unsigned char * )s2;
	
	while ( *p1 && *p1 == *p2 ) ++p1, ++p2;
	
    return ( *p1 > *p2 ) - ( *p2  > *p1 );
}

void text_init(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_colour = vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_colour);
        }
    }
}


void terminal_putentryat(char c, uint8_t colour, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, colour);
}

void terminal_putchar(char c) {

    if (c == '\n') {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_row = 0;
        }
    } else if (c == '\b') {
        if (terminal_column > 0) {
            terminal_column--;
        } else if (terminal_row > 0) {
            terminal_row--;
            terminal_column = VGA_WIDTH - 1;
        }
        terminal_putentryat(' ', terminal_colour, terminal_column, terminal_row);
    } else if (c == '\t') {}
        terminal_column = (terminal_column + 8) & ~(8 - 1);
        if (terminal_column >= VGA_WIDTH) {
            terminal_column = 0;
            if (++terminal_row == VGA_HEIGHT) {
                terminal_row = 0;
            }
        }
     else {
        terminal_putentryat(c, terminal_colour, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH) {
            terminal_column = 0;
            if (++terminal_row == VGA_HEIGHT) {
                terminal_row = 0;
            }
        }
    }
}


void move_hardware_cursor(size_t x, size_t y) {
    uint16_t pos = y * VGA_WIDTH + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}


void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void print(const char* data) {
    terminal_write(data, strlen(data));
}

void foreground_colour(enum vga_colour fg) {
    terminal_colour = (terminal_colour & 0xF0) | (fg & 0x0F);
}

void background_colour(enum vga_colour bg) {
    terminal_colour = (terminal_colour & 0x0F) | ((bg & 0x0F) << 4);
}

enum vga_colour get_foreground() {
    return (enum vga_colour)(terminal_colour & 0x0F);
}

enum vga_colour get_background() {
    return (enum vga_colour)((terminal_colour >> 4) & 0x0F);
}

void printcolour(uint8_t fg, uint8_t bg) {
    foreground_colour((enum vga_colour)fg);
    background_colour((enum vga_colour)bg);
}

void clear() {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
        	printcolour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
            terminal_putentryat(' ', terminal_colour, x, y);
        }
    }
    terminal_row = 0;
    terminal_column = 0;
    move_hardware_cursor(0, 0);
}

void terminal_set_cursor(size_t x, size_t y) {
    if (x < VGA_WIDTH && y < VGA_HEIGHT) {
        terminal_column = x;
        terminal_row = y;
    }
}

