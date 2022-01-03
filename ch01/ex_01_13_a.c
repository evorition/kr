#include <stdio.h>
#define MAXLEN 10

int main(void) {
  int c, nc;
  int wlen[MAXLEN];

  for (int i = 0; i < MAXLEN; ++i) {
    wlen[i] = 0;
  }

  nc = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      ++nc;
    } else if (nc > 0) {
      ++wlen[nc - 1];
      nc = 0;
    }
  }

  /* Plot horizontal histogram. */
  for (int i = 0; i < MAXLEN; ++i) {
    printf("%2d| ", i + 1);
    for (int j = 0; j < wlen[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
