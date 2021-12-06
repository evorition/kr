#include <stdio.h>

int main(void) {
  int c, ns;

  ns = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      ++ns;
    }
    else {
      if (ns > 0) {
        putchar('\n');
      }
      ns = 0;
      putchar(c);
    }
  }

  return 0;
}
