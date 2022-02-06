#include <stdio.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);

int main(void) {
  int type;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    printf("%s", s);
  }

  return 0;
}

#include <ctype.h> 

int getop(char s[]) {
  static int temp = -1;
  int i, c;

  if (temp != -1) {
    s[0] = c = temp;
    temp = -1;
  } else {
    s[0] = c = getchar();
  }
  while (c == ' ' || c == '\t') {
    s[0] = c = getchar();
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c;
  }
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getchar())) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getchar())) {
      ;
    }
  }
  s[i] = '\0';
  temp = c;
  return NUMBER;
}
