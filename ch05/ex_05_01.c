#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 5

int bufp = 0;
int buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getint(int *);

int main(void) {
  int n, array[SIZE];

  for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n) {
    ;
  }

  printf("Results:\n");

  for (int i = 0; i < SIZE; ++i) {
    printf("%d\n", array[i]);
  }

  return 0;
}

int getint(int *pn) {
  int c, sign;
  while (isspace(c = getch())) {
    ;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c) && c != EOF) {
      ungetch((sign == -1) ? '-' : '+');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}

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
