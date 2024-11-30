#include "print.h"
#include "io.h"

const size_t VGA_WIDTH = 80;
const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_colour;
uint16_t* terminal_buffer;
uint8_t temp_bg_colour = VGA_COLOUR_BLACK;

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

void printcolour(uint8_t colour) {
    terminal_colour = colour;
}

void terminal_putentryat(char c, uint8_t colour, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, colour);
}

void sys_termcursor(size_t row, size_t column)
{
	uint16_t position = row * VGA_WIDTH + column;

    // send the high byte (row) to the cursor location register
    outb(0x3D4, 14); // select the high byte
    outb(0x3D5, position >> 8); // write the high byte

    // send the low byte (column) to the cursor location register
    outb(0x3D4, 15); // select the low byte
    outb(0x3D5, position & 0xFF); 
    }
    
void sys_set_background(uint8_t bg_color) {
    terminal_colour = (terminal_colour & 0x0F) | (bg_color << 4);
    temp_bg_colour = bg_colour;
}

void terminal_putchar(char c) {
    if (c == '\n') {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_row = 0;
        }
	 if (c == '\b')
	    {
	    	terminal_column--;
	    	sys_set_cursor(terminal_row, terminal_column);
	    	terminal_putentryat(' ', terminal_column, bg_color, terminal_column, tty_row);
	    	return;
	    }
    } else {
        terminal_putentryat(c, terminal_colour, terminal_column, terminal_row);
        if (++terminal_column == VGA_WIDTH) {
            terminal_column = 0;
            if (++terminal_row == VGA_HEIGHT)
                terminal_row = 0;
        }
    }
}


void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void print(const char* data) {
    terminal_write(data, strlen(data));
}
