#include <stdbool.h>


void halt() {
    __asm__ __volatile__ ("cli");
    __asm__ __volatile__ ("hlt");
}