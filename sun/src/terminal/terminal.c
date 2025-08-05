#include <stdbool.h>
#include "lib/print.h"
#include "lib/log.h"
#include "lib/keyboard.h"
#include "lib/strings.h"
#include "term/terminal.h"
#include "program/exit.h"
#include "program/version.h"
#include "program/serialterm.h"
#include "program/fail.h"
#include "exc/exceptionhandler.h"


void terminal() {
    begin("Terminal began\n");
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BROWN, VGA_COLOUR_BLACK));
    printf("Sun Terminal\n");
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
    printf("Welcome to the basic terminal for the Sun Kernel. Here you can\n");
    printf("test the kernel before implementing your distros features.\n");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));

    while(1) {
        char input[256]; //should be in header yea??
        printf("shell> ");
        read_line(input, 256);   //basis of keyboard input
        printf("\n");

		if (strcmp(input, "test") == 0) {
			printf("test\n");
		} else {
			printf("not currently working\n");
		}

    }

	}