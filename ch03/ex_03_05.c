#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
  int n = 10;
  int b = 2;
  char s[100];

  itob(n, s, b);
  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int b) {
  int i, remainder;

  i = 0;
  do {
    remainder = n % b;
    s[i++] = (remainder > 9) ? (remainder - 10 + 'A') : remainder + '0';
  } while (n /= b);
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
