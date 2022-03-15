#include <stdio.h>

void mystrcat(char *s, char *t);

int main(void) {
  char s[100] = "Start of this string";
  char t[] = " end of the another string";

  mystrcat(s, t);
  printf("%s\n", s);

  return 0;
}

void mystrcat(char *s, char *t) {
  while (*s) {
    ++s;
  }
  while (*s++ = *t++) {
    ;
  }
}
