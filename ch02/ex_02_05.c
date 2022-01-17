#include <stdio.h>

int any(char s1[], char s2[]);

int main(void) {
  int position;
  char s1[] = "This is some string!\n";
  char s2[] = "abcdefg";

  position = any(s1, s2);
  printf("%d\n", position);

  return 0;
}

int any(char s1[], char s2[]) {
  int pos = -1;

  for (int i = 0; pos == -1 && s1[i] != '\0'; ++i) {
    for (int j = 0; pos == -1 && s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        pos = i;
      }
    }
  }

  return pos;
}
