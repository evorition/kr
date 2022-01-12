#include <stdio.h>
#define TABSTOP 8

void detab(void);

int main(void) {
  detab();

  return 0;
}

void detab(void) {
  int c, char_count, next_tabstop;

  char_count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      next_tabstop = char_count - char_count / TABSTOP * TABSTOP;
      char_count = char_count + (TABSTOP - next_tabstop);
      while (next_tabstop < 8) {
        putchar(' ');
        ++next_tabstop;
      }
    } else if (c == '\n') {
      putchar(c);
      char_count = 0;
    } else {
      putchar(c);
      ++char_count;
    }
  }
}
