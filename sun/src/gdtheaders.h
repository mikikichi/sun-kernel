#ifndef GDTHEADERS_H
#define GDTHEADERS_H


#include "libs/log.h"
#include <stdint.h>

typedef struct __attribute__((packed)) {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_mid;
  uint8_t access;
  uint8_t limit_high;
  uint8_t flags;
  uint8_t base_high;

} entry;

void set_entries(void);
extern struct gdtr gdtr;
extern unsigned int gdtinc;

#endif