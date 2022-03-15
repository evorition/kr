#include <stdio.h>

char *mystrncpy(char *s, char *t, int n);

int main(void) {
  char s[100];
  char *t = "Test string";

  printf("%s\n", mystrncpy(s, t, 4));

  return 0;
}

char *mystrncpy(char *s, char *t, int n) {
  char *p = s;
  int i = 0;

  while ((*s++ = *t++) && ++i < n) {
    ;
  }
  *s = '\0';
  return p;
}
