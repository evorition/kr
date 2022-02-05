#include <stdio.h>

int getch(void);
void ungetch(int);

int main(void) {
  ungetch(EOF);
  printf("%d\n", getch());
  return 0;
}

#define BUFSIZE 100

// All we need to do for this exercise is to change type of buf array from char 
// to int, because EOF is essentially just -1.
int buf[BUFSIZE];
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
