#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
  char t_1[] = "Tabs\t tab!\t \n tabs!\t\n";
  char t_2[] = "String with\\t \\t\\t   \\n \\n lot of this";
  char s[100];

  printf("%s\n", t_1);
  escape(s, t_1);
  printf("%s\n", s);

  printf("%s\n", t_2);
  unescape(s, t_2);
  printf("%s\n", s);

  return 0;
}

void escape(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
      case '\t':
        s[j++] = '\\';
        s[j] = 't';
        break;
      case '\n':
        s[j++] = '\\';
        s[j] = 'n';
        break;
      default:
        s[j] = t[i];
        break;
    }
    ++i;
    ++j;
  }
  s[j] = t[i];
}

void unescape(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
      case '\\':
        switch (t[i + 1]) {
          case 't':
            s[j] = '\t';
            ++i;
            break;
          case 'n':
            s[j] = '\n';
            ++i;
            break;
          default:
            s[j] = t[i];
            break;
        }
        break;
      default:
        s[j] = t[i];
    }
    ++i;
    ++j;
  }
  s[j] = t[i];
}
