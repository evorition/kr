#include <stdio.h>
#include <ctype.h>

unsigned int htoi(char s[]);

int main(void) {
  char hex_s[] = "0xABCD4";

  printf("%u\n", htoi(hex_s));

  return 0;
}

unsigned int htoi(char s[]) {
  int i;
  unsigned int n;
  char c;

  // Check if string starts with '0x' or '0X' and skip it
  i = 0;
  if (s[i] == '0') {
    ++i;
    if (s[i] == 'x' || s[i] == 'X') {
      ++i;
    } else {
      i = 0;
    }
  }

  n = 0;
  for (; s[i] != '\0' && s[i] != '\n'; ++i) {
    c = tolower(s[i]);

    if (c >= 'a' && c <= 'f') {
      n = 16 * n + (c - 'a' + 10);
    } else if (c >= '0' && c <= '9') {
      n = 16 * n + (c - '0');
    }
  }

  return n;
}
