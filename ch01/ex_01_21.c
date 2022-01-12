#include <stdio.h>
#define TABSTOP 8

void entab(void);

int main(void) {
  entab();

  return 0;
}

/* we assume that line that we get consist only out of spaces */
void entab(void) {
  int c, space_count, tab_count;

  space_count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      tab_count = space_count / TABSTOP;
      space_count = space_count - tab_count * TABSTOP;

      while (tab_count > 0) {
        putchar('\t');
        --tab_count;
      }
      while (space_count > 0) {
        putchar(' ');
        --space_count;
      }

      putchar('\n');
      space_count = 0;
    } else {
      ++space_count;
    }
  }
}
