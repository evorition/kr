#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
char *getfield(char *, char *, int n);
int revcmp(char *, char *);
int numcmp(char *, char *);
int strfcmp(char *, char *);
int strdcmp(char *, char *);
int strdfcmp(char *, char *);

int field;
int (*basecmp)(void *, void *);
char *lineptr[MAXLINES];
char s1[MAXLEN], s2[MAXLEN];

int main(int argc, char *argv[]) {
  int nlines, numeric, fold, directory, reverse, c, args;
  int fields[argc - 1], nums[argc - 1], folds[argc - 1], dirs[argc - 1],
    revs[argc - 1];
  args = 0;

  while (--argc > 0 && (*++argv)[0] == '-') {
    numeric = fold = directory = reverse = 0;
    field = atoi(++argv[0]);
    while (c = *argv[0]++) {
      switch (c) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        case 'f':
          fold = 1;
          break;
        case 'd':
          directory = 1;
          break;
        default:
          if (!isdigit(c)) {
            printf("unknow argument\n");
            return 1;
          }
      }
    }
    fields[args] = field;
    nums[args] = numeric;
    folds[args] = fold;
    dirs[args] = directory;
    revs[args] = reverse;
    ++args;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
    if (args == 0) {
      myqsort((void **) lineptr, 0, nlines - 1, strcmp);
    } else {
      for (int i = 0; i < args; ++i) {
        field = fields[i];
        numeric = nums[i];
        fold = folds[i];
        directory = dirs[i];
        reverse = revs[i];

        if (numeric) {
          basecmp = (int (*)(void *, void *))(numcmp);
        } else if (directory) {
          basecmp = (int (*)(void *, void *))((fold) ? strdfcmp : strdcmp);
        } else {
          basecmp = (int (*)(void *, void *))((fold) ? strfcmp : strcmp);
        }
        myqsort((void **) lineptr, 0, nlines - 1, (reverse ? revcmp : basecmp));
      } 
    }
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("Input too big to sort\n");
    return 1;
  }
}

int mygetline(char *s, int max) {
  int i, c;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines) {
  char line[MAXLEN], *p;
  int len, nlines;
  char *alloc(int n); 

  nlines = 0;
  while ((len = mygetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int maxlines) {
  while (maxlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int i, int j);

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; ++i) {
    if ((*comp)(getfield(v[i], s1, field), getfield(v[left], s2, field)) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  myqsort(v, left, last - 1, comp);
  myqsort(v, last + 1, right, comp);
}

char *getfield(char *s, char *t, int n) {
  if (n <= 0) {
    return s;
  }

  int i, j;
  i = j = 0;

  while (1) {
    if (s[i] == '\t' || s[i] == '\n' || s[i] == '\0') {
      if (--n == 0) {
        t[j] = '\0';
        return t;
      } else if (s[i] == '\n' || s[i] == '\0') {
        break;
      } else {
        j = 0;
        ++i;
      }
    } else {
      t[j++] = s[i++];
    }
  }

  return s;
}

int revcmp(char *s1, char *s2) {
  return (*basecmp)(s2, s1);
}

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2) {
    return -1;
  } else if (v1 > v2) {
    return 1;
  } else {
    return 0;
  }
}

int strfcmp(char *s1, char *s2) {
  while (tolower(*s1) == tolower(*s2)) {
    ++s1;
    ++s2;
    if (*s1 == '\0' && *s2 == '\0') {
      return 0;
    }
  }

  return tolower(*s1) - tolower(*s2);
}

int strdcmp(char *s1, char *s2) {
  while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') {
    ++s1;
  }
  while (!isalnum(*s2) && *s1 != ' ' && *s2 != '\0') {
    ++s2;
  }

  while (*s1 == *s2) {
    ++s1;
    ++s2;
    while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') {
      ++s1;
    }
    while (!isalnum(*s2) && *s1 != ' ' && *s2 != '\0') {
      ++s2;
    }
    if (*s1 == '\0' && *s2 == '\0') {
      return 0;
    }
  }

  return *s1 - *s2;
}

int strdfcmp(char *s1, char *s2) {
  while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') {
    ++s1;
  }
  while (!isalnum(*s2) && *s1 != ' ' && *s2 != '\0') {
    ++s2;
  }

  while (tolower(*s1) == tolower(*s2)) {
    ++s1;
    ++s2;
    while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') {
      ++s1;
    }
    while (!isalnum(*s2) && *s1 != ' ' && *s2 != '\0') {
      ++s2;
    }
    if (*s1 == '\0' && *s2 == '\0') {
      return 0;
    }
  }

  return tolower(*s1) - tolower(*s2);
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}

void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;
  }
}
