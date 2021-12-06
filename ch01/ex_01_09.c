#include <stdio.h>

int main(void) {
  int c, ns;

  ns = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++ns;
    }
    if (c != ' ') {
      if (ns > 0) {
        putchar(' ');
      }
      putchar(c);
      ns = 0;
    }
  }

  return 0;
}
