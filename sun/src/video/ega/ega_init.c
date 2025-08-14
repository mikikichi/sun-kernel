
#include "lib/io.h"
#include "video/ega/text_mono.h"
#include "video/video_init.h"
volatile uint8_t *color_buffer;
uint16_t base = 0x0000;
uint16_t position;
int y;
int x;

void ega_init() {
	text_mono_init();

	y = 0;
	x = 0;

	position = y * MAX_WIDTH_M + x; //should wrap this in a macro maybe?? would clean up the code
	clear(position);

	y = 0;
	x = 0;

	position = y * MAX_WIDTH_M + x;

	char test[] = "Welcome to the basic terminal of Sun Kernel! Currently OFF features include: Keyboard";
	print_string(position, test);

}
