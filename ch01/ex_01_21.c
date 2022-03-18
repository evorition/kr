#include <stdio.h>
#define TABSTOP 8

void entab(void);

int main(void) {
  entab();

  return 0;
}

void entab(void) {
  int c, count, blanks, tabstop;

  count = blanks = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar(c);
      count += TABSTOP - count % TABSTOP;
      blanks = 0;
    } else if (c == ' ') {
      ++blanks;
    } else if (c == '\n') {
      putchar(c);
      count = blanks = 0;
    } else {
      if (blanks > 0) {
        while ((tabstop = TABSTOP - count % TABSTOP) <= blanks) {
          putchar('\t');
          count += tabstop;
          blanks -= tabstop;
        }
        while (blanks > 0) {
          putchar(' ');
          ++count;
          --blanks;
        }
      }
      putchar(c);
      ++count;
    }
  }
}
