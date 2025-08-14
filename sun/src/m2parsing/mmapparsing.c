#include "mult/ranges.h"
#include "mult/memoryinfo.h"
#include "mult/multibootinfo.h"
#include <stdint.h>


mm_range ranges;
mm_count counts;
usableram usable[250];
reservedmem reserved[64];
acpi acpi_reclaim[64];
nvs nvs_memory[64];
defectmem bad_mem[64];



void m2_mmap(basic_tag *tag) {
	//ok I REALLY KINDA sorta hate this lmaoo it looks kinda ugly ughh...


	counts.av_count = 0;     
	counts.re_count = 0;
	counts.ac_count = 0;
	counts.nv_count = 0;
	counts.bad_count = 0;
	ranges.av_base = 0x0;
	ranges.av_end = 0x0;


	memoryentries *mmapentry; //here so its the same type
	memorymap *mmtag = (memorymap *)tag; //just cast it to the mmtag when going through it to view like putting on goggles!
        //its the same type so it knows what -> fields are  //arithmetic to get to the sizes max from the beginning value
	uint8_t *end = (uint8_t *)mmtag + mmtag->size;
	for (mmapentry = mmtag->entries; (uint8_t *)mmapentry < (uint8_t *)end; mmapentry = (memoryentries *)((uint8_t *) mmapentry + mmtag->entry_size)) {
		switch (mmapentry->type){
			case MULTIBOOT_MEMORY_AVAILABLE:
			//its the goodies here that matter not rly the address of mmapentry or something it usually gets written easily
			//eventually here make a check so avaible ram doesnt include kernel
			usableram *ram = usable + counts.av_count;
			ram->addr = mmapentry->addr;
			ram->len = mmapentry->len;
			ram->type = mmapentry->type;
			ram->zero = mmapentry->zero;

			ranges.av_base = (counts.av_count == 0) ? ram->addr : ranges.av_base;
			
			ranges.av_end = ram->addr + ram->len;

			counts.av_count++;
			break;

			case MULTIBOOT_MEMORY_RESERVED:

			reservedmem *res = reserved + counts.re_count;
			res->addr = mmapentry->addr;
			res->len = mmapentry->len;
			res->type = mmapentry->type;
			res->zero = mmapentry->zero;
			ranges.re_base = (counts.re_count == 0) ? res->addr : ranges.re_base;
			
			ranges.re_end = res->addr + res->len;

			counts.re_count++;
			break;

			case MULTIBOOT_MEMORY_ACPI_RECLAIMABLE:
			acpi *ac = acpi_reclaim + counts.ac_count;
			ac->addr = mmapentry->addr;
			ac->len = mmapentry->len;
			ac->type = mmapentry->type;
			ac->zero = mmapentry->zero;
			ranges.ac_base = (counts.ac_count == 0) ? ac->addr : ranges.av_base;
			
			ranges.ac_end = ac->addr + ac->len;

			counts.ac_count++;
			break;
			case MULTIBOOT_MEMORY_NVS:

			nvs *nv = nvs_memory + counts.nv_count;
			nv->addr = mmapentry->addr;
			nv->len = mmapentry->len;
			nv->type = mmapentry->type;
			nv->zero = mmapentry->zero;
			ranges.nv_base = (counts.nv_count == 0) ? nv->addr : ranges.nv_base;
			
			ranges.nv_end = nv->addr + nv->len;

			counts.nv_count++;
			break;
			case MULTIBOOT_MEMORY_BADRAM:

			defectmem *bad = bad_mem + counts.bad_count;
			bad->addr = mmapentry->addr;
			bad->len = mmapentry->len;
			bad->type = mmapentry->type;
			bad->zero = mmapentry->zero;
			ranges.bad_base = (counts.bad_count == 0) ? bad->addr : ranges.bad_base;
			
			ranges.bad_end = bad->addr + bad->len;

			counts.bad_count++;
			break;
		}

	}


	return;
} 