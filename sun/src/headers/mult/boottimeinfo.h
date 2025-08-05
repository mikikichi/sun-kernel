#ifndef BOOTTIMEINFO_H
#define BOOTTIMEINFO_H


typedef struct boot_info {
	uint64_t kernel_end;
	uint64_t kernel_start;
}__attribute__ ((packed)) boot_info;


extern boot_info bootlog;



#endif