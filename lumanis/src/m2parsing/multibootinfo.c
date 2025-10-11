
#include "mult/multibootinfo.h"

#include "idt/idt.h"
#include "program/exit.h"
#include "mult/boottimeinfo.h"


//Here when boot info is included correctly
boot_info bootlog;

void mb2_parse(uint32_t *m2ptr, uint32_t multiboot2_magic, uint64_t _kernel_start, uint64_t _kernel_end) {

	bootlog.kernel_end = _kernel_end;
	bootlog.kernel_start = _kernel_start;


	if (multiboot2_magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
		return; 
	}

	basic_tag *m_tag = (basic_tag *)((uint8_t *)m2ptr + 8);     //this is 8 bytes past the entry size 

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

