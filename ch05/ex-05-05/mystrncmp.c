#include <stdio.h>

int mystrncmp(char *s, char *t, int n);

int main(void) {
  char *t = "Test string";
  char *s = "Test";

  printf("%d\n", mystrncmp(s, t, 4));

  return 0;
}

int mystrncmp(char *s, char *t, int n) {
  int i = 0;

  while (*s == *t && ++i < n) {
    ++s;
    ++t;
  }

  if (*s == '\0' && i == n) {
    return 0;
  }

  return *s - *t;
}
