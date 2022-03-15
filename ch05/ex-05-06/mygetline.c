#include <stdio.h>

#define MAXSIZE 100

int mygetline(char *s, int lim);

int main(void) {
  char line[MAXSIZE];
  int len;

  while ((len = mygetline(line, MAXSIZE)) > 0) {
    printf("%s", line);
  }

  return 0;
}

int mygetline(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = '\n';
    ++i;
  }
  *s = '\0';
  return i;
}
