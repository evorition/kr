#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(char line[], int len); 

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    reverse(line, len);
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

void reverse(char s[], int len) {
  char temp;
  int i, j;

  i = 0;
  j = len - 2;
  while (i < j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    ++i;
    --j;
  }
}
