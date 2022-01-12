#include <stdio.h>
#define TABSTOP 8
#define FOLDCOLUMN 80
#define IN_BLANK 1
#define OUT_BLANK 0

void fold(void);

int main(void) {
  fold();

  return 0;
}

void fold(void) {
  int c, char_count, blank_count, next_tabstop, state;

  char_count = blank_count = 0;
  state = OUT_BLANK;
  while ((c = getchar()) != EOF) {
    if (char_count >= FOLDCOLUMN - 1) {
      state = OUT_BLANK;
      char_count = blank_count = 0;
      putchar('\n');
    }

    if (c == ' ' || c == '\t') {
      state = IN_BLANK;
      if (c == ' ') {
        ++blank_count;
        ++char_count;
      } else {
        next_tabstop = char_count - char_count / TABSTOP * TABSTOP;
        char_count = char_count + (TABSTOP - next_tabstop);
        blank_count = blank_count + (TABSTOP - next_tabstop);
      }
    } else {
      if (state == IN_BLANK && char_count - blank_count != 0) {
        while (blank_count > 0) {
          putchar(' ');
          --blank_count;
        }
      } else {
        blank_count = 0;
      }
      state = OUT_BLANK;
      putchar(c);
      ++char_count;
    }
  }
}
