#include "lib/io.h"
#include "video/ega/text_mono.h"


void buffer_write(uint16_t pos, char c) {

	color_buffer = (uint8_t *)COLOR_BUFFER; //again macro?



	color_buffer[pos] = c;

	uint16_t index = ((base + pos) / 2) + 1;
	mono_cursor(index); //for now, cursor moves each print
	return;
}



void buffer_string(uint16_t position, const char *string, uint16_t size) {

	int i; //the i here probably isnt needed
	for (i = 0; i < size; i++) {
		if (string[i] == '\n') { //maybe make the if check more like if !(all possible) to reduce the overhead????

			position += (MAX_WIDTH_M * 2) - (position % (MAX_WIDTH_M * 2)); //wrap these to a macro, looks ugly like this!!

			buffer_write(position, string[i]);
		} else {
			buffer_write(position, string[i]);
			position += 2;
		}

	}

	return;
}

void print(char *string) {
	//call formatter here??
	buffer_string(position, string, strlen(string));

	return;

}