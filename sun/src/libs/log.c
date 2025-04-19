#include "log.h"
#include "print.h"

void error(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_RED, VGA_COLOUR_BLACK));
    printf("[ !! ] ");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf(message);
}

void warn(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BROWN, VGA_COLOUR_BLACK));
    printf("[ ## ] ");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf(message);
}

void info(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BLUE, VGA_COLOUR_BLACK));
    printf("[ ?? ] ");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf(message);
}

void success(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_GREEN, VGA_COLOUR_BLACK));
    printf("[ ** ] ");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf(message);
}

void begin(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_GREEN, VGA_COLOUR_BLACK));
    printf("[ ++ ] ");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf(message);
}

void fatal(const char* message) {

    terminal_row = 0;
    terminal_column = 0;
    terminal_colour = vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_RED);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_colour);
        }
    }
    printf("Sun Kernel 0.0.2 - build date 19/4/2025\n");
    printf("[ FATAL ERROR ] ");
    printf(message);
    printf("\n");
}