#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
  unsigned x = 0xFF94; 
  int p = 3;
  int n = 3;

  printf("%u\n", invert(x, p, n));

  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  int shift = p + 1 - n;

  return (((x >> shift) ^ ~(~0 << n)) << shift) | (x & ~(~0 << shift));
}
