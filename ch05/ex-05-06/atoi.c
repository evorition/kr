#include <stdio.h>
#include <ctype.h>

int atoi(char *s);

int main(void) {
  char *s = "-123456789";

  printf("%d\n", atoi(s));

  return 0;
}

int atoi(char *s) {
  int sign, val;
  val = 0;

  while (isspace(*s)) {
    ++s;
  }
  sign = (*s == '-') ? -1 : 1;
  if (*s == '-' || *s == '+') {
    *s++;
  }
  while (isdigit(*s)) {
    val = 10 * val + (*s - '0');
    ++s;
  }
  return sign * val;
}
