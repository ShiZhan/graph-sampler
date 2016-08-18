#ifndef utils_h
#define utils_h
#include <string>

#ifdef _MSC_VER
#define SSCANF(X) sscanf_s X
#else
#define SSCANF(X) sscanf X
#endif

uint32_t hash32(uint32_t a) {
  a = (a + 0x7ed55d16) + (a << 12);
  a = (a ^ 0xc761c23c) ^ (a >> 19);
  a = (a + 0x165667b1) + (a << 5);
  a = (a + 0xd3a2646c) ^ (a << 9);
  a = (a + 0xfd7046c5) + (a << 3);
  a = (a ^ 0xb55a4f09) ^ (a >> 16);
  return a;
}

uint64_t hash64(uint64_t a) {
  a = (~a) + (a << 21); // a = (a << 21) - a - 1;
  a = a ^ (a >> 24);
  a = (a + (a << 3)) + (a << 8); // a * 265
  a = a ^ (a >> 14);
  a = (a + (a << 2)) + (a << 4); // a * 21
  a = a ^ (a >> 28);
  a = a + (a << 31);
  return a;
}

uint64_t hash64(uint64_t a, uint64_t salt) {
  a = (~a) + (a << 21) + salt; // a = (a << 21) - a - 1;
  a = a ^ (a >> 24);
  a = (a + (a << 3)) + (a << 8); // a * 265
  a = a ^ (a >> 14);
  a = (a + (a << 2)) + (a << 4); // a * 21
  a = a ^ (a >> 28);
  a = a + (a << 31);
  return a;
}

#endif
