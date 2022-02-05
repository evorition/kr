#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 200
#define MAXOP 100
#define NUMBER '0'

int mygetline(void);
int getop(char s[]);
void push(double);
double pop(void);

char line[MAXLINE];

int main(void) {
  int type, len;
  double op2;
  char s[MAXOP];

  while ((len = mygetline()) > 0) {
    while ((type = getop(s)) != '\0') {
      switch(type) {
        case NUMBER:
          push(atof(s));
          break;
        case '+':
          push(pop() + pop());
          break;
        case '*':
          push(pop() * pop());
          break;
        case '-':
          op2 = pop();
          push(pop() - op2);
          break;
        case '/':
          op2 = pop();
          if (op2 != 0.0) {
            push(pop() / op2);
          } else {
            printf("error: zero divisor\n");
          }
          break;
        case '\n':
          printf("\t%.8g\n", pop());
          break;
        default:
          printf("error: unknown command %c\n", type);
          break;
      }
    }
  }
  return 0;
}

int pos;
int mygetline(void) {
  int i, c;

  pos = 0;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i++] = '\n';
  }
  line[i] = '\0';
  return i;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
  }
}

#include <ctype.h> 

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = line[pos++])  == ' ' || c == '\t') {
    ;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c;
  }
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = line[pos++])) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = line[pos++])) {
      ;
    }
  }
  --pos;
  s[i] = '\0';
  return NUMBER;
}
