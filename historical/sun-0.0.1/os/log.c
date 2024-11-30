#include "log.h"
#include "print.h"

void sys_error(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_RED, VGA_COLOUR_BLACK));
    print("[ERROR] ");
    print(message);
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
}

void sys_warn(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BROWN, VGA_COLOUR_BLACK));
    print("[WARNING] ");
    print(message);
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
}

void sys_info(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_BLUE, VGA_COLOUR_BLACK));
    print("[INFO] ");
    print(message);
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
}

void sys_success(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_GREEN, VGA_COLOUR_BLACK));
    print("[SUCCESS] ");
    print(message);
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
}

void sys_stop(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_BLUE, VGA_COLOUR_BLACK));
    print("[FATAL ERROR] ");
    print(message);
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
    while (1) {
            __asm__ __volatile__("hlt");
        }
}
