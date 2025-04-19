#include <stdbool.h>
#include "libs/print.h"
#include "libs/log.h"
#include "terminal/terminal.h"
#include "idt/idt.h"

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;
extern unsigned char idtinc;

void kernel_main(void) 
{
    clear();

    idt_init();

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

    if (idtinc == 1) {
        begin("IDT has loaded\n");
    } else {
        fatal("IDT failed to load.\n");
    }

    terminal();
}