#ifndef RANGES_H
#define RANGES_H

#include <stdint.h>

typedef struct mm_range {
	uint64_t av_base;
	uint64_t av_end;
	uint64_t re_base;
	uint64_t re_end;
	uint64_t ac_base;
	uint64_t ac_end;
	uint64_t nv_base;
	uint64_t nv_end;
	uint64_t bad_base;
	uint64_t bad_end;
} __attribute__ ((packed)) mm_range;

typedef struct mm_count {
	int av_count;         
	int re_count;
	int ac_count;
	int nv_count;
	int bad_count;
} __attribute__ ((packed)) mm_count;




extern mm_range ranges;
extern mm_count counts;


#endif