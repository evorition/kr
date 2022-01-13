#include <stdio.h>
#include <limits.h>

int main(void) {
  printf("signed char min: %d, max: %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char min: %hd, max: %hd\n", 0, UCHAR_MAX);

  printf("\n");

  printf("signed short min: %d, max: %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short min: %hd, max: %d\n", 0, USHRT_MAX); 

  printf("\n");

  printf("signed int min: %d, max: %d\n", INT_MIN, INT_MAX);
  printf("unsigned int min: %u, max: %u\n", 0, UINT_MAX);

  printf("\n");

  printf("signed long min: %ld, max: %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long min: %lu, max: %lu\n", 0L, ULONG_MAX);

  return 0;
}
