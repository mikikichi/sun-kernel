#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libs/log.h"
#include "../terminal/programs/exit.h"
#include "../libs/strings.h"
#include "../libs/print.h"
#include "../libs/serial.h"

__attribute__((noreturn))
void exception_handler(uint8_t vector);
void exception_handler(uint8_t vector) {

    fatal("Exception Occurred!");

    switch(vector) {
        case 0:
            const char* msg0 = "EXCEPTION: division by zero.";
            while(*msg0){
                write_serial(*msg0++);
            }
            warn("EXCEPTION: division by zero.\n");
            break;
        case 1:
            const char* msg1 = "EXCEPTION: debug";
            while(*msg1){
                write_serial(*msg1++);
            }
            warn("EXCEPTION: debig\n");
            break;
        case 2:
            const char* msg2 = "EXCEPTION: non-maskable interrupt";
            while(*msg2){
                write_serial(*msg2++);
            }
            warn("EXCEPTION: non-maskable interrupt\n");
            break;
        case 3:
            const char* msg3 = "EXCEPTION: breakpoint";
            while(*msg3){
                write_serial(*msg3++);
            }
            warn("EXCEPTION: breakpoint\n");
            break;
        case 4:
            const char* msg4 = "EXCEPTION: overflow";
            while(*msg4){
                write_serial(*msg4++);
            }
            warn("EXCEPTION: overflow\n");
            break;
        case 5:
            const char* msg5 = "EXCEPTION: bound range exceeded";
            while(*msg5){
                write_serial(*msg5++);
            }
            warn("EXCEPTION: bound range exceeded\n");
            break;
        case 6:
            const char* msg6 = "EXCEPTION: invalid opcode";
            while(*msg6){
                write_serial(*msg6++);
            }
            warn("EXCEPTION: invalid opcode\n");
            break;
        case 7:
            const char* msg7 = "EXCEPTION: device not available";
            while(*msg7){
                write_serial(*msg7++);
            }
            warn("EXCEPTION: device not available\n");
            break;
        case 8:
            const char* msg8 = "EXCEPTION: double fault";
            while(*msg8){
                write_serial(*msg8++);
            }
            warn("EXCEPTION: double fault\n");
            break;
        case 9:
            const char* msg9 = "EXCEPTION: coprocessor segment overrun";
            while(*msg9){
                write_serial(*msg9++);
            }
            warn("EXCEPTION: coprocessor segment overrun\n");
            break;
        case 10:
            const char* msg10 = "EXCEPTION: invalid TSS";
            while(*msg10){
                write_serial(*msg10++);
            }
            warn("EXCEPTION: invalid TSS\n");
            break;
        case 11:
            const char* msg11 = "EXCEPTION: segment not present";
            while(*msg11){
                write_serial(*msg11++);
            }
            warn("EXCEPTION: segment not present\n");
            break;
        case 12:
            const char* msg12 = "EXCEPTION: stack-segment fault";
            while(*msg12){
                write_serial(*msg12++);
            }
            warn("EXCEPTION: stack-segment fault\n");
            break;
        case 13:
            const char* msg13 = "EXCEPTION: general protection fault";
            while(*msg13){
                write_serial(*msg13++);
            }
            warn("EXCEPTION: general protection fault\n");
            break;
        case 14:
            const char* msg14 = "EXCEPTION: page fault";
            while(*msg14){
                write_serial(*msg14++);
            }
            warn("EXCEPTION: page fault\n");
            break;
        case 15:
            const char* msg15 = "EXCEPTION: reserved";
            while(*msg15){
                write_serial(*msg15++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 16:
            const char* msg16 = "EXCEPTION: x87 floating-point exception";
            while(*msg16){
                write_serial(*msg16++);
            }
            warn("EXCEPTION: x87 floating-point exception\n");
            break;
        case 17:
            const char* msg17 = "EXCEPTION: alignment check";
            while(*msg17){
                write_serial(*msg17++);
            }
            warn("EXCEPTION: alignment check\n");
            break;
        case 18:
            const char* msg18 = "EXCEPTION: machine check";
            while(*msg18){
                write_serial(*msg18++);
            }
            warn("EXCEPTION: machine check\n");
            break;
        case 19:
            const char* msg19 = "EXCEPTION: SIMD floating point exception";
            while(*msg19){
                write_serial(*msg19++);
            }
            warn("EXCEPTION: SIMD floating point exception\n");
            break;
        case 20:
            const char* msg20 = "EXCEPTION: virtualisation exception";
            while(*msg20){
                write_serial(*msg20++);
            }
            warn("EXCEPTION: virtualisation exception\n");
            break;
        case 21:
            const char* msg21 = "EXCEPTION: control protection exception";
            while(*msg21){
                write_serial(*msg21++);
            }
            warn("EXCEPTION: control protection exception\n");
            break;
        case 22:
            const char* msg22 = "EXCEPTION: reserved";
            while(*msg22){
                write_serial(*msg22++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 23:
            const char* msg23 = "EXCEPTION: reserved";
            while(*msg23){
                write_serial(*msg23++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 24:
            const char* msg24 = "EXCEPTION: reserved";
            while(*msg24){
                write_serial(*msg24++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 25:
            const char* msg25 = "EXCEPTION: reserved";
            while(*msg25){
                write_serial(*msg25++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 26:
            const char* msg26 = "EXCEPTION: reserved";
            while(*msg26){
                write_serial(*msg26++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 27:
            const char* msg27 = "EXCEPTION: reserved";
            while(*msg27){
                write_serial(*msg27++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        case 28:
            const char* msg28 = "EXCEPTION: hypervisor injection exception";
            while(*msg28){
                write_serial(*msg28++);
            }
            warn("EXCEPTION: hypervisor injection exception\n");
            break;
        case 29:
            const char* msg29 = "EXCEPTION: VMM communication exception";
            while(*msg29){
                write_serial(*msg29++);
            }
            warn("EXCEPTION: VMM communication exception\n");
            break;
        case 30:
            const char* msg30 = "EXCEPTION: security exception";
            while(*msg30){
                write_serial(*msg30++);
            }
            warn("EXCEPTION: security exception\n");
            break;
        case 31:
            const char* msg31 = "EXCEPTION: reserved";
            while(*msg31){
                write_serial(*msg31++);
            }
            warn("EXCEPTION: reserved\n");
            break;
        default:
            const char* msgdefault = "EXCEPTION: unknown exception\n";
            while(*msgdefault){
                write_serial(*msgdefault++);
            }
            warn(msgdefault);
            break;
    }

    halt();

    __builtin_unreachable();
}