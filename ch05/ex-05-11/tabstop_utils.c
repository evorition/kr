#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8
#define SIZE 100

int get_tabstop(int column);

static int tabstops[100], tabcount;

void parse_tabstops(int argc, char *argv[]) {
  tabcount = argc - 1;
  if (tabcount > SIZE) {
    printf("error: too many arguments\n");
    return;
  }
  for (int i = 0; i < tabcount; ++i) {
    tabstops[i] = atoi(*++argv);
  }
}

int is_tabstop(int column, int blanks) {
  int tabstop;

  return ((tabstop = get_tabstop(column)) <= blanks) ? tabstop : -1;
}

int get_tabstop(int column) {
  for (int i = 0; i < tabcount; ++i) {
    if (column < tabstops[i]) {
      return tabstops[i] - column;
    }
  }
  return TABSTOP - column % TABSTOP;
}
