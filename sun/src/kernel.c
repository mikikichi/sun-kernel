#include <stdbool.h>
#include "libs/print.h"
#include "libs/log.h"
#include "terminal/terminal.h"

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;

void kernel_main(void) 
{
    clear();

    info("Kernel is UP\n");

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

    terminal();
}