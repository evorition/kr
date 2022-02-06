#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j);

int main(void) {
  char s[] = "desreveR";
  int i, j;

  i = 0;
  j = strlen(s) - 1;
  reverse(s, i, j);

  printf("%s\n", s);

  return 0;
}

void reverse(char s[], int i, int j) {
  int c;

  if (i < j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverse(s, ++i, --j);
  }
}
