
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
#include "mult/boottimeinfo.h"


//plans to maybe store the pointers to parsed info in like a custom struct? could be pretty damn useful!!
boot_info bootlog;

void mb2_parse(uint32_t *m2ptr, uint32_t multiboot2_magic, uint64_t _kernel_start, uint64_t _kernel_end) {

	bootlog.kernel_end = _kernel_end;
	bootlog.kernel_start = _kernel_start;


	if (multiboot2_magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
		return; 
	}

	basic_tag *m_tag = (basic_tag *)((uint8_t *)m2ptr + 8);     //this is 8 bytes past the entry size etc now i got the real entries

	while (m_tag->type != MULTIBOOT_TAG_TYPE_END) {
		switch (m_tag->type) {
			case MULTIBOOT_TAG_TYPE_MMAP:

			m2_mmap(m_tag);

			break;

			default:

			break;


		}

		m_tag = (basic_tag *)((uint8_t *) m_tag + ((m_tag->size + 7) & ~7));
	}


	return;
}

