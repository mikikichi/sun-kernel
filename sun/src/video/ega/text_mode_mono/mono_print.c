#include "lib/io.h"
#include "video/ega/text_mono.h"



void mono_print(uint16_t pos, char c) {

	color_buffer = (uint8_t *)COLOR_BUFFER; //again macro?

	color_buffer[pos] = c;

	uint16_t index = ((base + pos) / 2) + 1;
	mono_cursor(index); //for now, cursor moves each print
	return;
}

void print_string(uint16_t position, const char *string) {

	int i = 0; //the i here probably isnt needed
	while (string[i] != '\0') {
		mono_print(position, string[i]);
		position += 2;
		i++;
	}

	return;
}