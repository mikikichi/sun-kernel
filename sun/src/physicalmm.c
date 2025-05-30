#include "bitmap.h"
#include "libs/log.h"
#include <stdint.h>
#include <limits.h>
#include "libs/print.h"

#define PAGE_SIZE 4096              //4kb
#define TOTAL_MEMORY       //get this info from grub
//#define PAGE_AMOUNT (TOTAL_MEMORY / PAGE_SIZE)
#define BITMAP_SIZE (PAGE_SIZE / 8)

page bitmap[BITMAP_SIZE];

void status() {

}


void allocate() {

}

void free() {
	
}