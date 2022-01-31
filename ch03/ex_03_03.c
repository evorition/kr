#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main(void) {
  char s1[] = "-a-z0-9A-Z-";
  char s2[100];

  printf("%s\n", s1);
  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

enum hyphen_state{OUT_OF_RANGE, IN_RANGE};
void expand(char s1[], char s2[]) {
  int i, j, el, state;

  state = OUT_OF_RANGE;
  j = 0;
  for (i = 0; s1[i] != '\0'; ++i) {
    if (s1[i] == '-') {
      if (i == 0 || i == strlen(s1) - 1) {
        s2[j++] = s1[i];
      } else {
        state = IN_RANGE;
      }
    } else if (state == 1) {
      for (; el <= s1[i]; ++el) {
        s2[j++] = el;
      }
      state = OUT_OF_RANGE;
    } else {
      el = s1[i];
    }
  }
  s2[j] = s1[i];
}
