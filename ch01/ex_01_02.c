#include <stdio.h>

/* Programm will compile with a warning about unknown escape sequence: '\w' */
int main(void) {
  printf("Hello, world!\w");

  return 0;
}
