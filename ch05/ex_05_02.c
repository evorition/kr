#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 100

int bufp = 0;
int buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getfloat(float *);

int main(void) {
  float array[SIZE];
  int n;

  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; ++n) {
    ;
  }

  for (int i = 0; i < SIZE; ++i) {
    printf("%g\n", array[i]);
  }

  return 0;
}

int getfloat(float *pn) {
  float power;
  int c, sign;
  while (isspace(c = getch())) {
    ;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
  }
  for (*pn = 0.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
  }
  if (c == '.') {
    c = getch();
  }
  for (power = 1.0; isdigit(c) ; c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }
  *pn = sign * *pn / power;
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
