#include <stdbool.h>
#include "../../libs/strings.h"
#include "../../libs/print.h"
#include "../../libs/serial.h"
#include "../../libs/log.h"
#include "../../libs/keyboard.h"

void write() {
    while (1) {
        char input[256];
        printf("write> ");
        read_line(input, 256);
        printf("\n");

        serial_print(input);
        serial_print("\n");
    }
}

void listen() {
    while (1) {
        char buf[100];
        int i = 0;

        while (1) {
            char c = read_serial();

            if (c == '\n' || c == '\0' || i >= sizeof(buf) - 1) {
                buf[i] = '\0';
                break;
            }

            buf[i++] = c;
        }

        printf("\n");
        printf(buf);
        printf("\n");
    }
}



void serial(void) {
    printf("Welcome to Serial!\n");
    printf("Here, you can write to the serial port directly from the shell\n");
    printf("or listen from it.\n");
    printf("Type 'write' to write to the serial port, or 'listen' to listen from it.\n");
    warn("To exit the program, reset the system.\n");

    char input[256];
    printf("> ");
    read_line(input, 256);
    printf("\n");

    if (strcmp(input, "write") == 0) {
        write();
    } else if (strcmp(input, "listen") == 0) {
        listen();
    } else {
        error("Invalid input!\n");
    }
}
