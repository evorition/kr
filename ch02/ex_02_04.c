#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {
  char s1[] = "This is some string";
  char s2[] = "abcdefghij";

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  squeeze(s1, s2);
  printf("%s\n", s1);

  return 0;
}

enum found{NOT_FOUND, FOUND};
void squeeze(char s1[], char s2[]) {
  int j = 0;
  signed short state;

  for (int i = 0; s1[i] != '\0'; ++i) {
    state = NOT_FOUND;
    for (int k = 0; s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k]) {
        state = FOUND;
      }
    }
    if (state == NOT_FOUND) {
      s1[j++] = s1[i];
    }
  }

  s1[j] = '\0';
}
