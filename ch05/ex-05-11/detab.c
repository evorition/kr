#include <stdio.h>

void parse_tabstops(int argc, char *argv[]);
int get_tabstop(int column);
void detab(void);

int main(int argc, char *argv[]) {
  parse_tabstops(argc, argv);
  detab();

  return 0;
}

void detab(void) {
  int c, char_count, next_tabstop;

  char_count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      next_tabstop = get_tabstop(char_count);
      char_count += next_tabstop;
      while (next_tabstop > 0) {
        --next_tabstop;
        putchar(' ');
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
