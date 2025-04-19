#include <stdbool.h>
#include "../../libs/print.h"
#include "../../libs/log.h"

void halt() {
    printf("The kernel will stop now.\n");
    info("It is now safe to turn off the computer.");
    __asm__ __volatile__ ("cli");
    __asm__ __volatile__ ("hlt");
}