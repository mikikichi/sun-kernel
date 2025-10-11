#ifndef MEMORYINFO_H
#define MEMORYINFO_H


typedef struct usableram {
	uint64_t addr;
	uint64_t len;
	uint32_t type;
	uint32_t zero;

} __attribute__ ((packed)) usableram;

typedef struct acpi {
	uint64_t addr;
	uint64_t len;
	uint32_t type;
	uint32_t zero;

} __attribute__ ((packed)) acpi;

typedef struct reservedmem {
	uint64_t addr;
	uint64_t len;
	uint32_t type;
	uint32_t zero;

} __attribute__ ((packed)) reservedmem;

typedef struct nvs {
	uint64_t addr;
	uint64_t len;
	uint32_t type;
	uint32_t zero;

} __attribute__ ((packed)) nvs;


typedef struct defectmem {
	uint64_t addr;
	uint64_t len;
	uint32_t type;
	uint32_t zero;

} __attribute__ ((packed)) defectmem;


extern usableram usable[250];
extern reservedmem reserved[64];
extern acpi acpi_reclaim[64];
extern nvs nvs_memory[64];
extern defectmem bad_mem[64];


#endif