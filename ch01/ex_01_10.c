#include <stdio.h>

int main(void) {
  int c, inside;

  inside = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      inside = 1;
      putchar('\\');
      putchar('t');
    }
    if (c == '\b') {
      inside = 1;
      putchar('\\');
      putchar('b');
    }
    if (c == '\\') {
      inside = 1;
      putchar('\\');
      putchar('\\');
    }

    if (inside == 0) {
      putchar(c);
    }

    inside = 0;
  }

  return 0;
}
