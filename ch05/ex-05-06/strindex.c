#include <stdio.h>

int strindex(char *s, char *t);

int main(void) {
  char *s = "This is string";
  char *t = "is";

  printf("%d\n", strindex(s, t));

  return 0;
}

int strindex(char *s, char *t) {
  char *k, *p, *q;
  k = s;

  while (*s != '\0') {
    p = s;
    q = t;
    while (*q != '\0' && *p == *q) {
      ++p;
      ++q;
    }
    if ((q - t) > 0 && *q == '\0') {
      return s - k;
    }
    ++s;
  }
  return -1;
}
