#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);
void ungets(char s[]);

int main(void) {
  char s[] = "Test string!";
  int c;

  ungets(s);
  while ((c = getch()) != EOF) {
    putchar(c);
  }

  return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

void ungets(char s[]) {
  int len = strlen(s);

  while (len >= 0) {
    ungetch(s[len--]);
  }
}
