#include <stdbool.h>
#include "libs/print.h"
#include "libs/log.h"
#include "terminal/terminal.h"
#include "idt/idt.h"
#include "terminal/programs/exit.h"
#include "libs/serial.h"
#include "init/init.h"

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;
extern unsigned char idtinc;

void kernel_main(void) 
{
    clear();

    init();
    while(1) {
        terminal();
    }
}