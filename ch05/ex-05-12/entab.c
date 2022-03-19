#include <stdio.h>

void entab(void);
void parse_tabstops(int argc, char *argv[]);
int get_tabstop(int column);
int is_tabstop(int column, int blanks);

int main(int argc, char *argv[]) {
  parse_tabstops(argc, argv);
  entab();

  return 0;
}

void entab(void) {
  int c, count, blanks, tabstop;

  count = blanks = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar(c);
      count += get_tabstop(count);
      blanks = 0;
    } else if (c == ' ') {
      ++blanks;
    } else if (c == '\n') {
      putchar(c);
      count = blanks = 0;
    } else {
      if (blanks > 0) {
        while ((tabstop = is_tabstop(count, blanks)) != -1) {
          putchar('\t');
          blanks -= tabstop;
          count += tabstop;
        }
        while (blanks > 0) {
          putchar(' ');
          --blanks;
          ++count;
        }
      }
      putchar(c);
      ++count;
    }
  }
}
