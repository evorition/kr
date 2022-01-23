#include <stdio.h>

int lower(int c);

int main(void) {
  int c;

  while ((c = getchar()) != '\n') {
    printf("%c", lower(c));
  }
  printf("\n");

  return 0;
}

int lower(int c) {
  return (c >= 'A' && c < 'Z') ? c + 'a' - 'A' : c;
}
