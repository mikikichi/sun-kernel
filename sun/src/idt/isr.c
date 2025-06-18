#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "lib/log.h"
#include "program/exit.h"
#include "lib/strings.h"
#include "lib/print.h"
#include "lib/serial.h"
#include "exc/exceptionhandler.h"

__attribute__((noreturn))
void exception_handler(uint8_t vector);
void exception_handler(uint8_t vector) {

    fatal("Exception Occurred!");
    switch(vector) {
        case 1:
            exception(1);
            break;
        case 2:
            exception(2);
            break;
        case 3:
            exception(3);
            break;
        case 4:
            exception(4);
            break;
        case 5:
            exception(5);
            break;
        case 6:
            exception(6);
            break;
        case 7:
            exception(7);
            break;
        case 8:
            exception(8);
            break;
        case 9:
            exception(9);
            break;
        case 10:
            exception(10);
            break;
        case 11:
            exception(11);
            break;
        case 12:
            exception(12);
            break;
        case 13:
            exception(13);
            break;
        case 14:
            exception(14);
            break;
        case 15:
            exception(15);
            break;
        case 16:
            exception(16);
            break;    
        case 17:
            exception(17);
            break;
        case 18:
            exception(18);
            break;
        case 19:
            exception(19);
            break;
        case 20:
            exception(20);
            break;
        case 21:
            exception(21);
            break;
        case 22:
            exception(22);
            break;
        case 23:
            exception(23);
            break;
        case 24:
            exception(24);
            break;
        case 25:
            exception(25);
            break;
        case 26:
            exception(26);
            break;
        case 27:
            exception(27);
            break;
        case 28:
            exception(28);
            break;
        case 29:
            exception(29);
            break;
        case 30:
            exception(30);
            break;
        case 31:
            exception(31);
            break;
        default:
            error("Unknown exception vector.");
            break;
    }

    halt();

    __builtin_unreachable();
}