#include <stdio.h>

char *mystrncat(char *s, char *t, int n);

int main(void) {
  char s[100] = "Test string";
  char t[] = " very long";

  printf("%s\n", mystrncat(s, t, 5));

  return 0;
}

char *mystrncat(char *s, char *t, int n) {
  char *p = s;
  int i = 0;

  while (*s) {
    ++s;
  }
  while ((*s++ = *t++) && ++i < n) {
    ;
  }
  *s = '\0';
  return p;
}
