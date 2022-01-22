#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
  unsigned x = 0xFF94;
  unsigned y = 0xFF95;
  int p = 6;
  int n = 3;
  
  printf("%u\n", setbits(x, p, n, y));

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  int shift = p + 1 - n;

  // I know that it's overcomplicated solution but I just can't come up with 
  // something better at the moment.
  return x & (~0 << p + 1) | (((y & ~(~0 << n)) << shift) | x & ~(~0 << shift));
}
