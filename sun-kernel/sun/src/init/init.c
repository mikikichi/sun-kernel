#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../libs/print.h"
#include "../libs/log.h"
#include "../terminal/programs/exit.h"
#include "../libs/serial.h"
#include "init.h"
#include "../idt/idt.h"

extern unsigned char gdtinc;
extern unsigned char pageinc;
extern unsigned char longinc;
extern unsigned char idtinc;

void init() {

    idt_init();

    info("Kernel is UP\n");
    begin("init is up!\n");

    serial_init();
    begin("Serial is up!\n");

    if(gdtinc != 1) {
        fatal("The GDT could NOT load!\n");
        writeser("GDT could NOT load.");
        halt();
    } else {
        begin("GDT is up!\n");
        writeser("GDT is up!");
    }

    if(pageinc != 1) {
        fatal("Paging could NOT load!\n");
        writeser("Paging could NOT load.");
        halt();
    } else {
        begin("Paging is up!\n");
        writeser("Paging is up!");
    }

    if(longinc != 1) {
        fatal("Long mode could NOT be entered!\n");
        writeser("Long Mode could NOT be entered.");
        halt();
    } else {
        begin("Long mode entered!\n");
        writeser("Long mode entered!");
    }

    idtinc = 1;

    if(idtinc != 1) {
        fatal("The IDT could NOT load!\n");
        writeser("IDT could NOT load.");
        halt();
    } else {
        begin("IDT is up!\n");
        writeser("IDT is up!");
    }

}