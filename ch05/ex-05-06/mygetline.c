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
  char *p = s;
  int c, i;

  while (s - p < lim - 1 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = '\n';
  }
  *s = '\0';
  return s - p;
}
