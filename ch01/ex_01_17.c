#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 80

int my_getline(char line[], int maxline);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (len > THRESHOLD) {
      printf("%s", line);
    }
  }

  return 0;
}

int my_getline(char s[], int lim) {
  int i;
  int c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';

  return i;
}
