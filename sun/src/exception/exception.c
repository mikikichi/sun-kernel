#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "lib/print.h"
#include "lib/log.h"
#include "lib/serial.h"
#include "exc/exception.h"
#include "program/exit.h"
#include "lib/keyboard.h"
#include "lib/strings.h"

void exception1() {
    fatal("EXCEPTION: Division by zero.\n");
    info("Error Code: 1\n");
    warn("You can continue to use the kernel, however instability and\n");
    printf("memory corruption is likely. We recommend you either:\n");
    printf("A) debug this issue\n");
    printf("B) report this issue on Github.\n");
    printf("\n");
    serial_print("EXCEPTION: Division by zero.\n");
    serial_print("Error Code: 1\n");
    printf("\n");
    printf("Type y to continue or n to halt the kernel.\n");

    char input[256];
    printf("[y/n]> ");
    read_line(input, 256);
    printf("\n");

    if(strcmp(input, "y") == 0){
        clear();
    } else{
        halt();
    }
}

void exception2() {
    error("EXCEPTION: Debugging.\n");
    info("Error Code: 2\n");
    serial_print("EXCEPTION: Debug.\n");
    serial_print("Error Code: 2\n");

}

void exception3() {
    fatal("EXCEPTION: Non-maskable interrupt.\n");
    info("Error Code: 3\n");
    serial_print("EXCEPTION: Non-maskable interrupt.\n");
    serial_print("Error Code: 3\n");
    halt();
}

void exception4() {
    fatal("EXCEPTION: Overflow.\n");
    info("Error Code: 4\n");
    serial_print("EXCEPTION: Overflow.\n");
    serial_print("Error Code: 4\n");
    halt();
}

void exception5() {
    fatal("EXCEPTION: Boundary range exceeded.\n");
    info("Error Code: 5\n");
    serial_print("EXCEPTION: Boundary Range exceeded.\n");
    serial_print("Error Code: 5\n");
    halt();
}

void exception6() {
    fatal("EXCEPTION: Invalid Opcode.\n");
    info("Error Code: 6\n");
    serial_print("EXCEPTION: Invalid Opcode.\n");
    serial_print("Error Code: 6\n");
    halt();
}

void exception7() {
    fatal("EXCEPTION: Device unavailable.\n");
    info("Error Code: 7\n");
    serial_print("EXCEPTION: Device unavailable.\n");
    serial_print("Error Code: 7\n");
    halt();
}

void exception8() {
    fatal("EXCEPTION: Double fault.\n");
    info("Error Code: 8\n");
    serial_print("EXCEPTION: Double fault.\n");
    serial_print("Error Code: 8\n");
    halt();
}

void exception9() {
    fatal("EXCEPTION: Coprocessor Segment Overrun.\n");
    info("Error Code: 9\n");
    serial_print("EXCEPTION: Coprocessor Segment Overrun.\n");
    serial_print("Error Code: 9\n");
    halt();
}

void exception10() {
    fatal("EXCEPTION: Invalid TSS.\n");
    info("Error Code: 10\n");
    serial_print("EXCEPTION: Invalid TSS.\n");
    serial_print("Error Code: 10\n");
    halt();
}

void exception11() {
    fatal("EXCEPTION: Segment not present.\n");
    info("Error Code: 11\n");
    serial_print("EXCEPTION: Segment not present.\n");
    serial_print("Error Code: 11\n");
    halt();
}

void exception12() {
    fatal("EXCEPTION: Stack-segment fault.\n");
    info("Error Code: 12\n");
    serial_print("EXCEPTION: Stack-segment fault.\n");
    serial_print("Error Code: 12\n");
    halt();
}

void exception13() {
    fatal("EXCEPTION: General protection fault.\n");
    info("Error Code: 13\n");
    serial_print("EXCEPTION: General protection fault.\n");
    serial_print("Error Code: 13\n");
    halt();
}

void exception14() {
    fatal("EXCEPTION: Page fault.\n");
    info("Error Code: 14\n");
    serial_print("EXCEPTION: Page fault.\n");
    serial_print("Error Code: 14\n");
    halt();
}

void exception15() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 1\n");
    serial_print("EXCEPTION: Divsion by zero.\n");
    serial_print("Error Code: 1\n");
    halt();
}

void exception16() {
    fatal("EXCEPTION: x87 floating-point exception.\n");
    info("Error Code: 16\n");
    serial_print("EXCEPTION: x87 floating-point exception.\n");
    serial_print("Error Code: 16\n");
    halt();
}

void exception17() {
    fatal("EXCEPTION: alignment check.\n");
    info("Error Code: 17\n");
    serial_print("EXCEPTION: alignment check.\n");
    serial_print("Error Code: 17\n");
    halt();
}

void exception18() {
    fatal("EXCEPTION: machine check.\n");
    info("Error Code: 18\n");
    serial_print("EXCEPTION: machine check.\n");
    serial_print("Error Code: 18\n");
    halt();
}

void exception19() {
    fatal("EXCEPTION: SIMD floating point exception.\n");
    info("Error Code: 19\n");
    serial_print("EXCEPTION: SIMD floating point exception.\n");
    serial_print("Error Code: 19\n");
    halt();
}

void exception20() {
    fatal("EXCEPTION: virtualisation exception.\n");
    info("Error Code: 20\n");
    serial_print("EXCEPTION: virtualisation exception.\n");
    serial_print("Error Code: 20\n");
    halt();
}

void exception21() {
    fatal("EXCEPTION: control protection exception.\n");
    info("Error Code: 21\n");
    serial_print("EXCEPTION: control protection exception.\n");
    serial_print("Error Code: 21\n");
    halt();
}

void exception22() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 22\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 22\n");
    halt();
}

void exception23() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 23\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 23\n");
    halt();
}

void exception24() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 24\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 24\n");
    halt();
}

void exception25() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 25\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 25\n");
    halt();
}

void exception26() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 26\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 26\n");
    halt();
}

void exception27() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 27\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 27\n");
    halt();
}

void exception28() {
    fatal("EXCEPTION: Hypervisor injection exception.\n");
    info("Error Code: 28\n");
    serial_print("EXCEPTION: hypervisor injection exception.\n");
    serial_print("Error Code: 28\n");
    halt();
}

void exception29() {
    fatal("EXCEPTION: VMM communication exception.\n");
    info("Error Code: 29\n");
    serial_print("EXCEPTION: VMM communication exception.\n");
    serial_print("Error Code: 29\n");
    halt();
}

void exception30() {
    fatal("EXCEPTION: Security exception.\n");
    info("Error Code: 30\n");
    serial_print("EXCEPTION: Security exception.\n");
    serial_print("Error Code: 30\n");
    halt();
}

void exception31() {
    fatal("EXCEPTION: reserved.\n");
    info("Error Code: 31\n");
    serial_print("EXCEPTION: reserved.\n");
    serial_print("Error Code: 31\n");
    halt();
}