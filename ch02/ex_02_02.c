#include <stdio.h>
#define MAXLINE 10
#define IN_CYCLE 1
#define OUT_OF_CYCLE 0

int my_getline(char line[], int maxline);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    printf("%s", line); 
  }

  return 0;
}

int my_getline(char s[], int lim) {
  int i, c, state;

  // This is one of my solutions. It has one fatal flaw. If line exceeds lim,
  // than following character will be lost.
  //for (i = 0; (i < lim - 1) == (((c = getchar()) != '\n') == (c != EOF)); ++i) {
  //  s[i] = c;
  //}

  state = IN_CYCLE;
  i = 0;
  while (state == IN_CYCLE) {
    if (i >= lim - 1) {
      state = OUT_OF_CYCLE;
    } else if ((c = getchar()) == '\n') {
      state = OUT_OF_CYCLE;
    } else if (c == EOF) {
      state = OUT_OF_CYCLE;
    } else {
      s[i] = c;
      ++i;
    }
  }

  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';

  return i;
}
