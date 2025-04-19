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
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_RED));
    printf("[ !! ] ");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_RED));
    printf(" System is halting NOW");
    while (1) {
        __asm__ __volatile__("hlt");
    }
}