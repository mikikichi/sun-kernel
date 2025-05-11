#include <stdbool.h>
#include "libs/print.h"
#include "libs/log.h"
#include "terminal/terminal.h"
#include "idt/idt.h"
#include "terminal/programs/exit.h"
#include "libs/serial.h"
#include <stdarg.h>

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;
extern unsigned char idtinc;

void kernel_main(void) 
{
    clear();

    idt_init();

    serial_init();
    printf("Serial is up!\n");

    info("Kernel is UP\n");

    if (pageinc == 1) {
        begin("Paging has started\n");
    } else {
        fatal("Paging could not start.\n");

        halt();
    }

    if (gdtinc == 1) {
        begin("GDT has loaded\n");
    } else {
        fatal("GDT failed\n");
        halt();
    }

    if (longinc == 1) {
        begin("Long mode entered\n");
    } else {
        fatal("Long mode failed\n");
        halt();
    }

    if (idtinc == 1) {
        begin("IDT has started\n");

    } else {
        fatal("IDT could not start.\n");
        halt();
    }

    terminal();
}