#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void my_itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
  int n = -2147483648;
  char s[100];

  my_itoa(n, s);
  printf("%s\n", s);

  return 0;
}

// This version doesn't work with the smallest negative number, for example
// -2147483648 because when we check for sign and trying to change number from
// negative to positive with `-n` operation, the number -2147483648 will become
// 2147483648 but it's out of bound because for int type the limits are 
// -2147483648 2147483647.
void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void my_itoa(int n, char s[]) {
  int i, temp;

  i = 0;
  do {
    temp = n % 10;
    s[i++] = ((temp < 0) ? -temp : temp) + '0';
  } while (n /= 10);
  if (temp < 0) {
    s[i++] = '-';
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
