
#include "mult/multibootinfo.h"
#include "lib/print.h"
#include <stdint.h>
#include "lib/log.h"
#include "lib/serial.h"
#include "term/terminal.h"
#include "idt/idt.h"
#include "program/exit.h"
#include "lib/serial.h"

void m2_mmap(tag* tag) {

	mm_range ranges;
	mm_count counts;

	mm_range *range = &ranges; 

	mm_count *count = &counts;
	usableram usable[64];
	reservedmem reserved[64];
	acpi acpi_reclaim[64];
	nvs nvs_memory[64];
	defectmem bad_mem[64];

	count->av_count = 0;     
	count->re_count = 0;
	count->ac_count = 0;
	count->nv_count = 0;
	count->bad_count = 0;
	range->av_base = 0x0;
	range->av_end = 0x0;


	memoryentries *mmapentry; //here so its the same type
	memorymap *mmtag = (memorymap *)tag; //just cast it to the mmtag when going through it to view like putting on goggles!
        //its the same type so it knows what -> fields are  //arithmetic to get to the sizes max from the beginning value
	uint8_t *end = (uint8_t *)mmtag + mmtag->size;
	for (mmapentry = mmtag->entries; (uint8_t *)mmapentry < (uint8_t *)end; mmapentry = (memoryentries *)((uint8_t *) mmapentry + mmtag->entry_size)) {
		switch (mmapentry->type){
			case MULTIBOOT_MEMORY_AVAILABLE:
			//its the goodies here that matter not rly the address of mmapentry or something it usually gets written easily
			usableram *ram = usable + count->av_count;
			ram->addr = mmapentry->addr;
			ram->len = mmapentry->len;
			ram->type = mmapentry->type;
			ram->zero = mmapentry->zero;

			range->av_base = (count->av_count == 0) ? ram->addr : range->av_base;
			
			range->av_end = ram->addr + ram->len;

			count->av_count++;
			break;

			case MULTIBOOT_MEMORY_RESERVED:

			reservedmem *res = reserved + count->re_count;
			res->addr = mmapentry->addr;
			res->len = mmapentry->len;
			res->type = mmapentry->type;
			res->zero = mmapentry->zero;
			range->re_base = (count->re_count == 0) ? res->addr : range->re_base;
			
			range->re_end = res->addr + res->len;

			count->re_count++;
			break;

			case MULTIBOOT_MEMORY_ACPI_RECLAIMABLE:
			acpi *ac = acpi_reclaim + count->ac_count;
			ac->addr = mmapentry->addr;
			ac->len = mmapentry->len;
			ac->type = mmapentry->type;
			ac->zero = mmapentry->zero;
			range->ac_base = (count->ac_count == 0) ? ac->addr : range->av_base;
			
			range->ac_end = ac->addr + ac->len;

			count->ac_count++;
			break;
			case MULTIBOOT_MEMORY_NVS:

			nvs *nv = nvs_memory + count->nv_count;
			nv->addr = mmapentry->addr;
			nv->len = mmapentry->len;
			nv->type = mmapentry->type;
			nv->zero = mmapentry->zero;
			range->nv_base = (count->nv_count == 0) ? nv->addr : range->nv_base;
			
			range->nv_end = nv->addr + nv->len;

			count->nv_count++;
			break;
			case MULTIBOOT_MEMORY_BADRAM:

			defectmem *bad = bad_mem + count->bad_count;
			bad->addr = mmapentry->addr;
			bad->len = mmapentry->len;
			bad->type = mmapentry->type;
			bad->zero = mmapentry->zero;
			range->bad_base = (count->bad_count == 0) ? bad->addr : range->bad_base;
			
			range->bad_end = bad->addr + bad->len;

			count->bad_count++;
			break;
		}

	}

	clear();
	return;
} 