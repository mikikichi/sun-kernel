//eventually when new modes come mode switching will be handled here, so this api helps with me not needing to write code for each scenario!

#include "video/video_api.h"


//pos = y * MAX_WIDTH_M + x;

void video_init() {
	ega_init(); //for now this just calls ega which calls 7 mode, will have a section of some kind here or just automatic switching??
}