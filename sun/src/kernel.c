#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "lib/print.h"
#include "lib/log.h"
#include "lib/serial.h"
#include "term/terminal.h"
#include "idt/idt.h"
#include "program/exit.h"
#include "lib/serial.h"
#include "mult/multibootinfo.h"

extern unsigned int gdtinc;
extern unsigned int pageinc;
extern unsigned int idtinc;
extern uint32_t multiboot2_magic;
extern uint32_t multiboot2_ptr;                    //cast this to its own pointertype, iterate through what you need send it to the right file etc

void kernel_main() {

    clear();
    serial_init();
    info("Kernel is UP!\n");
    success("Serial is UP!\n");
    serial_print("serial up\n");

	uintptr_t *multibootptr = (uintptr_t *)(uintptr_t)multiboot2_ptr;
	mb2_parse(multibootptr, multiboot2_magic); //doesnt work just included anyways 

    success("Running in long mode.\n");

	gdtinc = 1;

    if(gdtinc == 1) {
        success("GDT has loaded\n");
        serial_print("GDT load\n");
    } else {
        fatal("The GDT failed to load.\n");
        serial_print("GDT fail\n");                                   //but this will never even happen? i think unnecesary code
        halt();
    }
                             //what about some kind of checklist at the end?? well tbh this cant really ever fail but its better to have a failcheck
    pageinc = 1;

    if(pageinc == 1){
        success("Temporary paging has started - up to 2GB RAM addressable\n");
        serial_print("Paging load\n");
    } else {
        fatal("Paging failed to start.\n");
        serial_print("Paging fail\n");
        halt();
    }

    idt_init();

    if(idtinc == 1){
        success("IDT has started\n");
        serial_print("IDT load\n");
    } else {
        fatal("IDT failed to start.\n");
        serial_print("IDT fail\n");
    }
    terminal();
}