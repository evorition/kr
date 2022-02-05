#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);

int main(void) {
  return 0;
}

int buf;

int getch(void) {
  int ret;

  if (buf != -1) {
    ret = buf;
    buf = -1;
    return ret;
  } else {
    return getchar();
  }
}

void ungetch(int c) {
  if (buf != -1) {
    printf("ungetch: too many characters\n");
  } else {
    buf = c;
  }
}
