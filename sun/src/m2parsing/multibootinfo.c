
#include "mult/multibootinfo.h"
#include "lib/print.h"
#include <stdint.h>
#include "lib/print.h"
#include "lib/log.h"
#include "lib/serial.h"
#include "term/terminal.h"
#include "idt/idt.h"
#include "program/exit.h"
#include "lib/serial.h"


//plans to maybe store the pointers to parsed info in like a custom struct? could be pretty damn useful!!


void mb2_parse(uintptr_t *multibootptr, uint32_t multiboot2_magic) {


	if (multiboot2_magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
		return; //this rets instantly i know it doesnt work </3 :((!!
	}

	tag *m_tag = (tag *)((uint8_t *)multibootptr + 8);     //this is 8 bytes past the entry size etc now i got the real entries

	while (m_tag->type != MULTIBOOT_TAG_TYPE_END) {
		switch (m_tag->type) {
			case MULTIBOOT_TAG_TYPE_MMAP:
			m2_mmap(m_tag);
			break;

			case MULTIBOOT_TAG_TYPE_BASIC_MEMINFO:

			break;

			case MULTIBOOT_TAG_TYPE_BOOTDEV:

			break;

			case MULTIBOOT_TAG_TYPE_VBE:

			break;

			case MULTIBOOT_TAG_TYPE_FRAMEBUFFER:

			break; 

			case MULTIBOOT_TAG_TYPE_LOAD_BASE_ADDR:

			break; 

			default:

			break;
		}


 		m_tag = (tag *)(uint8_t *) m_tag + ((m_tag->size + 7) & ~7);
	}

	clear();
	return;
}

