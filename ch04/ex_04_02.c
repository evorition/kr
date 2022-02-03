#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main(void) {
  char s[] = "123.45e6";

  printf("%f\n", atof(s));

  return 0;
}

double atof(char s[]) {
  double val, power;
  int i, exp, exp_sign, sign;

  for (i = 0; isspace(s[i]); ++i) {
    ;
  }

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    ++i;
  }

  for (val = 0.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') {
    ++i;
  }

  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    ++i;
  }

  exp_sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') {
    ++i;
  }

  for (exp = 0; isdigit(s[i]); ++i) {
    exp = 10 * exp + (s[i] - '0');
  }
  while (exp > 0) {
    --exp;
    if (exp_sign < 0) {
      power *= 10;
    } else {
      power /= 10;
    }
  }

  return sign * val / power;
}
