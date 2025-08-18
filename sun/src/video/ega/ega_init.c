
#include "lib/io.h"
#include "video/ega/text_mono.h"
#include "video/video_init.h"
volatile uint8_t *color_buffer;
uint16_t base = 0x0000;
uint16_t position;
int y = 0;
int x = 0; //wrap this

void ega_init() {
	text_mono_init();


	position = y * MAX_WIDTH_M + x; //should wrap this in a macro maybe?? would clean up the code
	clear(position);

	print("Welcome to the basic terminal for Sun Kernel!\nFeatures OFF: Keyboard");

}
