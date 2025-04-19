#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libs/log.h"
#include "../terminal/programs/exit.h"
#include "../libs/strings.h"
#include "../libs/print.h"

__attribute__((noreturn))
void exception_handler(uint8_t vector);
void exception_handler(uint8_t vector) {
    fatal("Exception Occurred!\n");

    if (vector > 31) {
            warn("EXCEPTION: Unknown exception Vector. outside of range.\n");
            char vector_str[4];
            uint8_to_string(vector, vector_str);
            info("Vector:\n");
            info(vector_str);
            printf("\n");
            halt();
    }

    switch(vector) {
        case 0:
            warn("EXCEPTION: division by zero.\n");
            break;
        case 1:
            warn("EXCEPTION: debug\n");
            break;
        case 2:
            warn("EXCEPTION: non-maskable interrupt\n");
            break;
        case 3:
            warn("EXCEPTION: breakpoint\n");
            break;
        case 4:
            warn("EXCEPTION: overflow\n");
            break;
        case 5:
            warn("EXCEPTION: Bound range exceeded\n");
            break;
        case 6:
            warn("EXCEPTION: Invalid Opcode\n");
            break;
        case 7:
            warn("EXCEPTION: Device not available\n");
            break;
        case 8:
            warn("EXCEPTION: Double fault\n");
            break;
        case 9:
            warn("EXCEPTION: Coprocessor segment overrun\n");
            break;
        case 10:
            warn("EXCEPTION: Invalid TSS\n");
            break;
        case 11:
            warn("EXCEPTION: Segment not present\n");
            break;
        case 12:
            warn("EXCEPTION: Stack-segment fault\n");
            break;
        case 13:
            warn("EXCEPTION: General Protection Fault\n");
            break;
        case 14:
            warn("EXCEPTION: Page fault\n");
            break;
        case 15:
            warn("EXCEPTION: Reserved\n");
            break;
        case 16:
            warn("EXCEPTION: x87 Floating-point exception\n");
            break;
        case 17:
            warn("EXCEPTION: Alignment check\n");
            break;
        case 18:
            warn("EXCEPTION: Machine check\n");
            break;
        case 19:
            warn("EXCEPTION: SIMD Floating Point Exception\n");
            break;
        case 20:
            warn("EXCEPTION: Virtualisation Exception\n");
            break;
        case 21:
            warn("EXCEPTION: Control Protection Exception\n");
            break;
        case 22:
            warn("EXCEPTION: reserved\n");
            break;
        case 23:
            warn("EXCEPTION: reserved\n");
            break;
        case 24:
            warn("EXCEPTION: reserved\n");
            break;
        case 25:
            warn("EXCEPTION: reserved\n");
            break;
        case 26:
            warn("EXCEPTION: reserved\n");
            break;
        case 27:
            warn("EXCEPTION: reserved\n");
            break;
        case 28:
            warn("EXCEPTION: Hypervisor Injection Exception\n");
            break;
        case 29:
            warn("EXCEPTION: VMM Communication Exception\n");
            break;
        case 30:
            warn("EXCEPTION: Security Exception\n");
            break;
        case 31:
            warn("EXCEPTION: Reserved");
            break;
        default:
            char vector_str[4]; 
            uint8_to_string(vector, vector_str);
            warn("EXCEPTION: unknown exception vector.\n");
            info("Exception Vector is: \n");
            info(vector_str);
            printf("\n");
            break;
    }
    halt();

    __builtin_unreachable();
}
