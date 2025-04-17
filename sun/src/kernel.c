#include <stdbool.h>
#include "libs/print.h"

extern unsigned char pageinc;
extern unsigned char gdtinc;
extern unsigned char longinc;

void kernel_main(void) 
{

	if (pageinc == 1) {
        printf("[ OKAY ] Paging has started\n");
    } else {
        printf("[ FAIL ] Paging could not start.\n");
    }

    if (gdtinc == 1) {
        printf("[ OKAY ] GDT has loaded\n");
    } else {
        printf("[ FAIL ] GDT failed\n");
    }

    if (longinc == 1) {
        printf("[ OKAY ] Long mode entered\n");
    } else {
        printf("[ FAIL ] Long mode failed\n");
    }
}