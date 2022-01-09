#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0

int my_getline(char line[], int maxline);
void trailing(char line[], int len);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    printf("%s", line);
    trailing(line, len);
    printf("%s", line);
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

void trailing(char s[], int len) {
  int i, j, state;

  state = OUT;
  i = 0;
  while (i <= len) {
    if (s[i] == ' ' || s[i] == '\t') {
      if (state == OUT) {
        j = i;
        state = IN;
      }
    } else if (state == IN) {
      if (s[i] == '\n') {
        s[j] = '\n';
        s[j + 1] = '\0';
        i = len;
      } else if (s[i] == '\0') {
        s[j] = '\0';
        i = len;
      } else {
        state = OUT;
      }
    }
    ++i;
  }
}
