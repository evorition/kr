#include <stdio.h>
#include <stdlib.h>

int get_tabstop(int column);

static int tabstop_start = 0;
static int tabstop = 8;

void parse_tabstops(int argc, char *argv[]) {
  for (int i = 0; i < argc - 1; ++i) {
    if ((*++argv)[0] == '-') {
      tabstop_start = atoi(++argv[0]);
    } else if ((*argv)[0] == '+') {
      tabstop = atoi(++argv[0]);
    }
  }
}

int is_tabstop(int column, int blanks) {
  int tabstop;

  return ((tabstop = get_tabstop(column)) <= blanks) ? tabstop : -1;
}

int get_tabstop(int column) {
  if (column < tabstop_start) {
    return tabstop_start - column;
  }
  return tabstop - column % tabstop;
}
