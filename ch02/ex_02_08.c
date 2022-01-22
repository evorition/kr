#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);
short bitcount(void);

int main(void) {
  unsigned x = 0xFF94;
  int n = 3;

  printf("%u\n", rightrot(x, n));

  return 0;
}

unsigned rightrot(unsigned x, int n) {
  short nbits = bitcount(); 

  return (x >> n) | (x << (nbits - n));
}

short bitcount(void) {
  short count = 0;
  unsigned n = UINT_MAX;

  while (n) {
    n = n >> 1;
    ++count;
  }

  return count;
}
