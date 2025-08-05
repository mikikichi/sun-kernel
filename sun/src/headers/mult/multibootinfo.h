#ifndef MULTIBOOTINFO_H
#define MULTIBOOTINFO_H
#include <stdint.h>

#define MULTIBOOT_HEADER 1

#define MULTIBOOT_SEARCH                        32768
#define MULTIBOOT_HEADER_ALIGN                  8


#define MULTIBOOT2_HEADER_MAGIC                 0xe85250d6


#define MULTIBOOT2_BOOTLOADER_MAGIC             0x36d76289


#define MULTIBOOT_MOD_ALIGN                     0x00001000


#define MULTIBOOT_INFO_ALIGN                    0x00000008

#define MULTIBOOT_TAG_ALIGN                  8
#define MULTIBOOT_TAG_TYPE_END               0
#define MULTIBOOT_TAG_TYPE_CMDLINE           1
#define MULTIBOOT_TAG_TYPE_BOOT_LOADER_NAME  2
#define MULTIBOOT_TAG_TYPE_MODULE            3
#define MULTIBOOT_TAG_TYPE_BASIC_MEMINFO     4
#define MULTIBOOT_TAG_TYPE_BOOTDEV           5
#define MULTIBOOT_TAG_TYPE_MMAP              6
#define MULTIBOOT_TAG_TYPE_VBE               7
#define MULTIBOOT_TAG_TYPE_FRAMEBUFFER       8
#define MULTIBOOT_TAG_TYPE_ELF_SECTIONS      9
#define MULTIBOOT_TAG_TYPE_APM               10
#define MULTIBOOT_TAG_TYPE_EFI32             11
#define MULTIBOOT_TAG_TYPE_EFI64             12
#define MULTIBOOT_TAG_TYPE_SMBIOS            13
#define MULTIBOOT_TAG_TYPE_ACPI_OLD          14
#define MULTIBOOT_TAG_TYPE_ACPI_NEW          15
#define MULTIBOOT_TAG_TYPE_NETWORK           16
#define MULTIBOOT_TAG_TYPE_EFI_MMAP          17
#define MULTIBOOT_TAG_TYPE_EFI_BS            18
#define MULTIBOOT_TAG_TYPE_EFI32_IH          19
#define MULTIBOOT_TAG_TYPE_EFI64_IH          20
#define MULTIBOOT_TAG_TYPE_LOAD_BASE_ADDR    21

#define MULTIBOOT_HEADER_TAG_END  0
#define MULTIBOOT_HEADER_TAG_INFORMATION_REQUEST  1
#define MULTIBOOT_HEADER_TAG_ADDRESS  2
#define MULTIBOOT_HEADER_TAG_ENTRY_ADDRESS  3
#define MULTIBOOT_HEADER_TAG_CONSOLE_FLAGS  4
#define MULTIBOOT_HEADER_TAG_FRAMEBUFFER  5
#define MULTIBOOT_HEADER_TAG_MODULE_ALIGN  6
#define MULTIBOOT_HEADER_TAG_EFI_BS        7
#define MULTIBOOT_HEADER_TAG_ENTRY_ADDRESS_EFI32  8
#define MULTIBOOT_HEADER_TAG_ENTRY_ADDRESS_EFI64  9
#define MULTIBOOT_HEADER_TAG_RELOCATABLE  10

#define MULTIBOOT_MEMORY_AVAILABLE              1
#define MULTIBOOT_MEMORY_RESERVED               2
#define MULTIBOOT_MEMORY_ACPI_RECLAIMABLE       3
#define MULTIBOOT_MEMORY_NVS                    4
#define MULTIBOOT_MEMORY_BADRAM                 5


#define MULTIBOOT_ARCHITECTURE_I386  0
#define MULTIBOOT_ARCHITECTURE_MIPS32  4
#define MULTIBOOT_HEADER_TAG_OPTIONAL 1

#define MULTIBOOT_LOAD_PREFERENCE_NONE 0
#define MULTIBOOT_LOAD_PREFERENCE_LOW 1
#define MULTIBOOT_LOAD_PREFERENCE_HIGH 2

#define MULTIBOOT_CONSOLE_FLAGS_CONSOLE_REQUIRED 1
#define MULTIBOOT_CONSOLE_FLAGS_EGA_TEXT_SUPPORTED 2
//monster of a list, macros for going through stuff below is some structs (not all) for multiboot stuff

typedef struct basic_tag {
	uint32_t type;                         //this is like a reference for parsing through the info
	uint32_t size;

}__attribute__((packed)) basic_tag;

typedef struct memoryentries {
	uint64_t addr;
	uint64_t len;
	uint32_t type;
	uint32_t zero;

} __attribute__ ((packed)) memoryentries;


typedef struct memorymap {
	uint32_t type;
	uint32_t size;
	uint32_t entry_size;
	uint32_t entry_version;
	memoryentries entries[];                    //will show up at runtime so compiler doesnt panic!
} __attribute__ ((packed)) memorymap;

typedef struct multibootinfo {
	uint32_t total_size;              //4 bytes
	uint32_t reserved;                //4 again, next one is 8 4 plus 4 is the header
} __attribute__ ((packed)) multibootinfo;   //physical address of the struct is used to get entries
//not used 

typedef struct multiboot_basic_mem_info {
	uint32_t type;
	uint32_t size;
	uint32_t mem_low;
	uint32_t mem_high;
}__attribute__ ((packed)) multiboot_basic_mem_info;




typedef struct basic_mem_info {
	uint32_t type;
	uint32_t size;
	uint32_t mem_low;
	uint32_t mem_high;
}__attribute__ ((packed)) basic_mem_info;




void mb2_parse(uint32_t *multibootptr, uint32_t multiboot2_magic, uint64_t _kernel_start, uint64_t _kernel_end);
void m2_mmap(basic_tag *tag);

//great bunch of useless structs here that arent used at all? should prolly clean them up later

#endif