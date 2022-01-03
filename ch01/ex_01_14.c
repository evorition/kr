#include <stdio.h>
#define SIZE 94

int main(void) {
  int c;
  int symbols[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    symbols[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '!' && c <= '~') {
      ++symbols[c - '!'];
    }
  }

  /* Plot horizontal histogram. */
  for (int i = 0; i < SIZE; ++i) {
    printf("%c| ", i + '!');
    for (int j = 0; j < symbols[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
