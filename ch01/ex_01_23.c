#include <stdio.h>
#define IN_COMMENT 1
#define OUT_OF_COMMENT 0

void remove_comments(void);

int main(void) {
  remove_comments();

  return 0;
}

void remove_comments(void) {
  int c, next_char, state;

  next_char = 0;
  state = OUT_OF_COMMENT;
  while ((c = getchar()) != EOF) {
    if (c == '/' || next_char == '/') {
      if (state == OUT_OF_COMMENT && (next_char = getchar()) == '*') {
        state = IN_COMMENT;
        next_char = 0;
      } else if (state == OUT_OF_COMMENT) {
        putchar(c);
        putchar(next_char);
        next_char = 0;
      }
    } else if (c == '*' || next_char == '*') {
      if (state == IN_COMMENT && (next_char = getchar()) == '/') {
        state = OUT_OF_COMMENT;
        next_char = 0;
      } else if (state == OUT_OF_COMMENT) {
        putchar(c);
        putchar(next_char);
        next_char = 0;
      }
    } else if (state == OUT_OF_COMMENT) {
      putchar(c);
    }
  }
}
