#include "terminal.h"
#include "libs/strings.h"
#include "programs/exit.h"
#include "programs/version.h"
#include "programs/serialterm.h"
#include "programs/fail.h"
#include "exception/exceptionhandler.h"

void terminal() {
    begin("Terminal began\n");
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BROWN, VGA_COLOUR_BLACK));
    printf("Sun Terminal\n");
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK));
    printf("Welcome to the basic terminal for the Sun Kernel. Here you can\n");
    printf("test the kernel before implementing your distros features.\n");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));

    while(1) {
        char input[256];
        printf("shell> ");
        read_line(input, 256);
        printf("\n");

        // father forgive me for i have sinned, i have nested if statements

        if(strcmp(input, "exit") == 0) {
            halt();
        } else if(strcmp(input, "hello") == 0) {
                printf("Hello, World!\n");
        } else if(strcmp(input, "version") == 0) {
                version();
        } else if(strcmp(input, "clear") == 0) {
                clear();
        } else if(strcmp(input, "serial") == 0) {
                serial();
        } else if(strcmp(input, "fail") == 0) {
                fail();
        } else if(strcmp(input, "excp") == 0) {
                exception(2);
        } else if(strcmp(input, "help") == 0) {
            printf("'exit' - exits the shell and halts the kernel.\n");
            printf("'hello' - prints 'Hello, World!' to the screen.\n");
            printf("'clear' - clears the screen.\n");
            printf("'version' - shows some information about the kernel version.\n");
            printf("'serial' - enter a basic serial tool.\n");
            printf("'fail' - crashes the system.\n");
            printf("'help' - shows this message.\n");
        } else {
                printf("Command not recognised. Type 'help' for a list of recognised commands.\n");
            }
        }
    }
