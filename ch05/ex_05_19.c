#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int tokentype;
int gettoken(void);
char token[MAXTOKEN]; 
char out[1000];

int main(void) {
  int type, ptype;
  char temp[MAXTOKEN];
 
  ptype = 0;
  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n') {
      if (type == PARENS || type == BRACKETS) {
        if (ptype == '*') {
          sprintf(temp, "(%s)", out);
          strcpy(out, temp);
        }
        strcat(out, token);
        ptype = type;
      } 
      else if (type == '*') {
        sprintf(temp, "*%s", out);
        strcpy(out, temp);
        ptype = type;
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
        ptype = type;
      } else {
        printf("invalid input at %s\n", token);
      }
    }
    printf("%s\n", out);
    ptype = 0;
  }
  return 0;
}

int gettoken(void) {
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t') {
    ;
  }
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '('; 
    }
  }
  else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']'; ) {
      ;
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch()); ) {
      *p++ = c;
    }
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}

#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];

int getch(void) {
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: buffer if full\n");
  } else {
    buf[bufp++] = c;
  }
}
