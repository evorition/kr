#include <stdio.h>

int main(void) {
  int c, ns, nl, nt;

  ns = 0;
  nl = 0;
  nt = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++ns;
    }
    if (c == '\n') {
      ++nl;
    }
    if (c == '\t') {
      ++nt;
    }
  }

  printf("Number of spaces: %d, lines: %d, tabs: %d", ns, nl, nt);

  return 0;
}
