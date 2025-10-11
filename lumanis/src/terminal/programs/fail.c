#include <stdbool.h>
#include "lib/strings.h"
#include "program/fail.h"

void fail(void) {



    __asm__ volatile ("int $0");
}