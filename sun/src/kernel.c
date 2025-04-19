#include <stdbool.h>
#include "libs/print.h"
#include "libs/log.h"
#include "libs/keyboard.h"

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;

void kernel_main(void) 
{
    text_init();

    success("Kernel is UP\n");

    if (pageinc == 1) {
        begin("Paging has started\n");
    } else {
        fatal("Paging could not start.\n");
    }

    if (gdtinc == 1) {
        begin("GDT has loaded\n");
    } else {
        fatal("GDT failed\n");
    }

    if (longinc == 1) {
        begin("Long mode entered\n");
    } else {
        fatal("Long mode failed\n");
    }

    printf("keyboard loop running\n");

    while(1) {
        char input[256];
        printf("enter text> ");
        read_line(input, 256);
        printf("\n");
        printf("you typed:\n");
        printf(input);
        printf("\n");
    }

    fatal("Nothing more to do.\n");

}