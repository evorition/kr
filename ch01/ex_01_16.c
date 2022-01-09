#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
  int c;
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (len == MAXLINE - 1 && line[len - 1] != '\n') {
      while ((c = getchar()) != '\n' && c != EOF) {
        ++len;
      }
      if (c == '\n') {
        ++len;
      }
    }
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("Length is: %d\n", max);
    printf("%s", longest);
    if (max > MAXLINE) {
      printf("...\n");
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
