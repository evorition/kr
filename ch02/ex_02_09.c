#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
  unsigned x = 0xFF94;

  printf("%d\n", bitcount(x));

  return 0;
}

int bitcount(unsigned x) {
 int count = 0; 

 while (x) {
   x &= x - 1;
   ++count;
 }

 return count;
}
