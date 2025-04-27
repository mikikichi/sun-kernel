#include <stdint.h>
#include <sys/types.h>

typedef struct __attribute__((packed)) {
  u_int16_t limit_low;
  u_int8_t limit_high; // remember to mask this!!
  u_int16_t base_low;
  u_int8_t base_mid;
  u_int8_t base_high;
  u_int8_t flags;
  u_int8_t access;

} entry;

// mask the bits here, this should take 64 bits in total. use hex bitmasks!
// prolly best to do this in a helper function...

void gdt_table() // empty for now
{
  // limit
  // base
  // access
  // flags
}
