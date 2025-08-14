#include "keyboard_header/ps2_header/ps2h.h"
#include "lib/io.h"


void ps2_keysinit(){

io_outb_8(0x64, 0xF5);




}