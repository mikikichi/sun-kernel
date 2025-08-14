#ifndef PAGES_H
#define PAGES_H


#include <stdint.h>
#include "lib/bool.h"


#define PAGE_SIZE 4096 //decimal
#define MAX_ORDER 10 //maxing it out to 10 cuz theres no reason for a big ass gig page rn lol
#define MEM_START 0x00000000 //not known actually
#define MEM_END 0x40000000

#define BITMAP_SIZE ((262144 / 8) / 2)


//max order is mem / pagesize power of two so shifted left
//maybe limit to a gig for now, cant dynamically allocate anyways gig is 2^30 
//2^30 = 1 073 741 824
//262 144
// 18
//whole region split into smallest would be 262,144 blocks
// 262,144 / 8 for the uint 8 

typedef struct memory_pool {
	struct memorypool* next;
	struct memorypool* prev;
	struct page* entry;



}__attribute__ ((packed)) memory_pool;



typedef struct page {

	struct page* next_free;

	bool allocated;
	int order;

}__attribute__((packed)) page;



//uint8_t bitmap[BITMAP_SIZE]; //make bitmap here only track buddies each pair is one bit kinda like in linux
//maybe just make one for each order easier that way
page pages[262144]; //whole page pool split to the max amount here we got pointers inside each free page to the next
memory_pool memory[MAX_ORDER];



#endif