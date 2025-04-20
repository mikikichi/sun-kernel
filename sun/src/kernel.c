#include <stdbool.h>
#include "libs/print.h"
#include "libs/log.h"
#include "terminal/terminal.h"
#include "idt/idt.h"
#include "terminal/programs/exit.h"

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;
extern unsigned char idtinc;

void kernel_main(void) 
{

    idt_init();

    clear();

    info("Kernel is UP\n");

    if (pageinc == 1) {
        begin("Paging has started\n");
        func("paging begins");
    } else {
        fatal("Paging could not start.\n");
        halt();
    }

    if (gdtinc == 1) {
        begin("GDT has loaded\n");
        func("GDT begins");
    } else {
        fatal("GDT failed\n");
        halt();
    }

    if (longinc == 1) {
        begin("Long mode entered\n");
        func("long mode entered");
    } else {
        fatal("Long mode failed\n");
        halt();
    }

    if (idtinc == 1) {
        begin("IDT has started\n");
        func("IDT begins");
    } else {
        fatal("IDT could not start.\n");
        halt();
    }

}