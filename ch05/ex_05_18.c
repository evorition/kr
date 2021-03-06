#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
int error_state = 0;

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN]; 
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main(void) {
  while (gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if (tokentype != '\n' || error_state == 1) {
      printf("syntax error\n");
      if (tokentype != '\n') {
        while (gettoken() != '\n') {
          ;
        }
      }
      error_state = 0;
    } else {
      printf("%s: %s %s\n", name, out, datatype);
    }
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

void dcl(void) {
  int ns;

  for (ns = 0; gettoken() == '*'; ) {
    ++ns;
  }
  dirdcl();
  while (ns-- > 0) {
    strcat(out, " pointer to");
  }
}

void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')') {
      printf("error: missing )\n");
      error_state = 1;
      return;
    }
  } else if (tokentype == NAME) {
    strcpy(name, token);
  } else {
    printf("error: expected name or (dcl)\n");
    error_state = 1;
    return;
  }
  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(out, " function returning");
    } else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}
