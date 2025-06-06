#include "fail.h"

void fail(void) {
    clear();
    printf("This literally just crashes your system.\n");
    error("Would you like to continue? [Y/n]");
    
    char input[256];
    printf("> ");
    read_line(input, 256);
    printf("\n");

    if(strcmp(input, "y") == 0) {
        printf("Continuing...");
    } else if (strcmp(input, "n") == 0) {
        printf("Exiting...\n");
        return;
    }

    __asm__ volatile ("int $0");
}