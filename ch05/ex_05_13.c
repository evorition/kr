#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINES 5000

int mygetline(char line[], int max);
int readlines(char *lineptr[], char lines[], int maxlines);
void mytail(char *lineptr[], int maxlines, int n);

char *lineptr[MAXLINES];

int main(int argc, char *argv[]) {
  int nlines, n;
  char lines[MAXLEN * MAXLINES];

  n = 5;

  if (argc > 2) {
    printf("error: to many arguments\n");
    return 1;
  }

  if (--argc > 0) {
    if ((*++argv)[0] == '-') {
      n = atoi(++argv[0]);
    }
  }

  if ((nlines = readlines(lineptr, lines, MAXLINES)) > 0) {
    mytail(lineptr, nlines, n);
  }
  return 0;
}

int mygetline(char line[], int max) {
  int i, c;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}


int readlines(char *lineptr[], char lines[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  p = lines;

  while ((len = mygetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || lines + MAXLEN * maxlines - p < len) {
      return -1;
    } else {
      line[len - 1] = '\0'; // remove `\n` symbol from the end of the string
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  }

  return nlines;
}

void mytail(char *lineptr[], int maxlines, int n) {
  int lines = (n >= maxlines) ? 0 : maxlines - n;

  while (lines < maxlines) {
    printf("%s\n", *(lineptr + lines++));
  }
}
