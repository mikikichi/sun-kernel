#include "lib/log.h"
#include "lib/print.h"
#include "lib/strings.h"

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

char last_executed_function[64] = "Unknown";

void func(const char* name) {
    strncpy(last_executed_function, name, sizeof(last_executed_function) - 1);
    last_executed_function[sizeof(last_executed_function) - 1] = '\0';
}

void printfunc() {
    printf("Last executed function: ");
    printf(last_executed_function);
    printf("\n");

    if (strcmp(last_executed_function, "Unknown") == 0) {
        printf("(If this is empty, then it is likely a critical component in boot.s. Report this in the GitHub issues page.)\n");
    }
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
    asm volatile("cli");
    printf("Sun Kernel 0.0.3 - build date 28/5/2025\n");
    printf("[ FATAL ERROR ] ");
    printf(message);
    printf("\n");
}