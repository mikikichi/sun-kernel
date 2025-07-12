#ifndef GDTHEADERS_H
#define GDTHEADERS_H


#include "lib/log.h"
#include <stdint.h>



void set_entries(void);
extern struct gdtr gdtr;
extern unsigned int gdtinc; //should i get rid of this file??

#endif