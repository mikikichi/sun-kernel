#ifndef GDTHEADERS_H
#define GDTHEADERS_H


#include "libs/log.h"
#include <stdint.h>



void set_entries(void);
extern struct gdtr gdtr;
extern unsigned int gdtinc;

#endif