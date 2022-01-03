#include <stdio.h>
#define MAXLEN 10

int main(void) {
  int c, nc, max_height;
  int wlen[MAXLEN];

  for (int i = 0; i < MAXLEN; ++i)
    wlen[i] = 0;

  nc = max_height = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      ++nc;
    }
    else if (nc > 0) {
      if (++wlen[nc - 1] > max_height) {
        max_height = wlen[nc - 1];
      }
      nc = 0;
    }
  }

  /* Plot vertical histogram */
  for (int i = max_height; i > 0; --i) {
    printf("%2d|", i);
    for (int j = 0; j < MAXLEN; ++j) {
      if (wlen[j] >= i) {
        printf("  *");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }

  for (int i = 0; i < 2; ++i) {
    printf("   ");
    for (int j = 0; j < MAXLEN; ++j) {
      if (i == 0) {
        printf("---");
      } else {
        printf("%3d", j + 1);
      }
    }
    printf("\n");
  }

  return 0;
}
