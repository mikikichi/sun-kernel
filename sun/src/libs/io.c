#include <stdbool.h>
#include <stdint.h>
#include "lib/io.h"

extern uint8_t inb(uint16_t port);
extern void outb(uint16_t port, uint8_t data);

void io_outb_8(uint16_t port, uint8_t data) {
	outb(port, data);
	return;

}

uint8_t io_inb_8(uint16_t port) {

	uint8_t written = inb(port);
	return written;

}