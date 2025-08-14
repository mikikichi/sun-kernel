
#include "lib/io.h"
#include "video/ega/text_mono.h"
#include <stddef.h>

//cursor starts at line 12 ends line 11 
//80 columns number of character rows per screen 25

//mode 7 ports: index 0x3D4, data 0x3D5,
//io outb(port, data)
//planar
//sequencers 3C4, 3C5


void text_mono_init() {
	//setup the sizes of screen and cursor, then notify sequencer
	//b000 


	io_outb_8(0x3C4, 0x00); //reset 
	io_outb_8(0x3C5, 0x3);

	//feature control 3DA/3BA
	//set both lines to negative, vga autosynchs but ega doesnt
	io_outb_8(0x3C2, 0xF6); //negative, odd/even so 11110110 clock 16 assumin mode 7 so odd even is on high page of 64kb
	io_outb_8(0x3BA, 0x01); //bit 0, for FC0 logical high this prolly doesnt do anything in qemu but could in actual hardware
	//page 330 ish

	io_outb_8(0x3C4, 0x01);
	io_outb_8(0x3C5, 0x01); //8/9 dot clocks set to 9, monochrome mode 7 needs 9 dots instead of 8, i want high res so bw set to 0 for scans
	
	io_outb_8(0x3C4, 0x02);
	io_outb_8(0x3C5, 0x01); //plane 0

	io_outb_8(0x3C4, 0x03);
	io_outb_8(0x3C5, 0x00); //all zero for now

	io_outb_8(0x3C4, 0x04);
	io_outb_8(0x3C5, 0x3); //text mode chose extended memory, odd/even on


	io_outb_8(0x3B4, 0x17);
	io_outb_8(0x3B5, 0x0);


	io_outb_8(0x3B4, 0x0C);
	io_outb_8(0x3B5, 0x00); //high start 8-15 divide by 256 so shift left 8 cuzz memory is segmented to 256 blocks

	io_outb_8(0x3B4, 0x0D);
	io_outb_8(0x3B5, 0x00); //low start 0-7



	io_outb_8(0x3B4, 0x00);
	io_outb_8(0x3B5, 0x4E);


	return;

}


void mono_cursor(uint16_t index){

	uint8_t cur_low = index;
	uint8_t cur_high = index >> 8;

	io_outb_8(0x3B4, 0x0E); //cursor high
	io_outb_8(0x3B5, cur_high);

	io_outb_8(0x3B4, 0x0F); //cursor low
	io_outb_8(0x3B5, cur_low);
	return;
}

void clear(uint16_t position) {
	//space 0x20 


	color_buffer = (uint8_t *)COLOR_BUFFER;
	while (color_buffer[position] != 200) { //my theory is that this goes out of bounds if exceeds
		color_buffer[position] = 0x20;

		position += 2;

	}

	return;
}


