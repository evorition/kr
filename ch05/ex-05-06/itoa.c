#include <stdio.h>

void itoa(char *s, int n);
int mystrlen(char *s); 
void reverse(char *s);

int main(void) {
  char s[100];
  int n = -123456789;

  itoa(s, n);
  printf("%s\n", s);

  return 0;
}

void itoa(char *s, int n) {
  int temp;
  char *p = s;

  do {
    temp = n % 10;
    *s = ((temp < 0) ? -temp : temp) + '0';
    ++s;
  } while (n /= 10);
  if (temp < 0) {
    *s = '-';
    ++s;
  }
  *s = '\0';
  reverse(p);
  s = p;
}

int mystrlen(char *s) {
  char *p = s;

  while (*s != '\0') {
    ++s;
  }

  return s - p;
}

void reverse(char *s) {
  int temp;
  int len = mystrlen(s) - 1; 
  char *p = s + len;

  while (s < p) {
    temp = *s;
    *s++ = *p;
    *p-- = temp;
  }
}
