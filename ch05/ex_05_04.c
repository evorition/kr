#include <stdio.h>

int strend(char *s, char *t);

int main(void) {
  char *s = "This is a string";
  char *t = "string";

  printf("%d\n", strend(s, t));

  return 0;
}

int strend(char *s, char *t) {
  char *p = t;

  while (*s) {
    while (*s == *t && *s != '\0') {
      ++s;
      ++t;
    }
    if (*s == '\0' && *t == '\0') {
      return 1;
    } else {
      t = p;
    }
    ++s;
  }
  return 0;
}
