#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define LINESLEN 1000

char *lineptr[MAXLINES];

int mygetline(char *s, int maxline);
int readlines(char *lineptr[], char *lines, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main(void) {
  int nlines;
  char lines[LINESLEN * MAXLINES];

  if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

int mygetline(char *s, int maxline) {
  int c;
  char *p = s;

  while (s - p < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = '\n';
  }
  *s = '\0';

  return s - p;
}

#define MAXLEN 1000

int readlines(char *lineptr[], char *lines, int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  p = lines;

  while ((len = mygetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || lines + LINESLEN * MAXLINES - p < len) {
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

void writelines(char *lineptr[], int maxlines) {
  while (maxlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, left + 1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
