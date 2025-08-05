#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stdint.h>

void io_outb_8(uint16_t port, uint8_t data);
uint8_t io_inb_8(uint16_t port);

#endif