#include "pmm/pages.h"

#include "lib/log.h"
#include "lib/bool.h"
#include <stdint.h>
#include <limits.h>
#include "lib/print.h"


//grab all usable ram thats not kernel or modules
//buddy = address ^ size so theyre like neighbors with a wall inbetween with proper alignment
//the power of twos number is what bit is flipped and the bit to the right with a 0 between is what decides if its a or b
//hmm powers of two...

void memory_init() {
//map here kernels start and end values to multiboot usable ram cuz it doesnt take into account that
//2^30 = 1 073 741 824 walk a gig past kernels end
//page pages[262144]; reference here


	
}

//shift << pagesize power2 to get base of pagenumber >> to divide
//number = address >> 12
// like addr / pagesize is what page number has this address
// >> division by power of two << multiply by power of two


void freepage() {
	
}

void usepage() {

}