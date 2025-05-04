#include "lgdt.s"
#include "libs/log.h"
#include <stdint.h>
#include <sys/types.h>

typedef struct __attribute__((packed)) {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_mid;
  uint8_t access;
  uint8_t limit_high;
  uint8_t flags;
  uint8_t base_high;

} entry;

entry segment_add;
uint8_t *target = (uint8_t *)&segment_add;

// gdtr has a base address to the gdt table function add that. and then the
// entries!!

void gdt_table(uint8_t *target, uint16_t limit_low, uint16_t base_low,
               uint8_t base_mid, uint8_t access, uint8_t limit_high,
               uint8_t flags, uint8_t base_high) {
  if ((limit_low >> 2) | limit_high > 0xFFFFF) {
    fatal("GDT can't encode limit fields larger than 20 bits (0xFFFFF)");
    return;
  }

  // limit
  target[0] = limit_low & 0x0F;
  target[2] = limit_high;
  // base
  target[1] = base_low;
  target[3] = base_mid;
  target[4] = base_high;
  // access
  target[5] = access;
  // flags
  target[6] = flags & 0x0F;
}

// set the actual entries!!
// high is what is left after lower bits are counted for!!!
void set_entries() {
  // null entry
  gdt_table(target, 0x00000000, 0, 0, 0x00, 0, 0x0, 0);
  gdt_table(target, 0xFFFF, 0, 0, 0x9A, 0xF, 0xA, 0);
  gdt_table(target, 0xFFFF, 0, 0, 0x92, 0xF, 0xC, 0);

  typedef struct __attribute__((packed)) {
    uint16_t length;
    uint64_t base;
  } gdtr;
  gdtr g;
  g.length = 23;
  g.base = (uint64_t)target;

  extern void lgdtset(g); // make your assembly function match this
}
