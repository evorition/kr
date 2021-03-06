#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) {
  int n = -1234;
  char s[100];
  int w = 10;

  itoa(n, s, w);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[], int w) {
  int i, sign;

  if (n < 0) {
    sign = -1;
  } else {
    sign = 1;
  }
  i = 0;
  do {
    s[i++] = (n % 10 * sign) + '0';
  } while (n /= 10);
  if (sign == -1) {
    s[i++] = '-';
  }

  while (i < w) {
    s[i++] = ' ';
  }

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c;

  for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
