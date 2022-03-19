#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'

int getop(char *s);
void push(double f);
double pop(void);

int main(int argc, char *argv[]) {
  double op2;
  int type;

  if (argc == 1) {
    printf("Usage: expr operators and operands as separate arguments\n");
    return 1;
  }

  while (--argc > 0) {
    switch (type = getop(*++argv)) {
      case NUMBER:
        push(atof(*argv));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      default:
        printf("error: unknow command %c\n", type);
        break;
    }
  }

  printf("%f\n", pop());
  return 0;
}

#include <ctype.h>

int getop(char *s) {
  int c;

  if (!isdigit(c = *s++) && c != '.' && c != '-') {
    return c;
  }
  if (c == '-') {
    if (!isdigit(c = *s) && c != '.') {
      return '-';
    }
  }
  if (isdigit(c)) {
    while (isdigit(c = *++s)) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(c = *++s)) {
      ;
    }
  }
  return NUMBER;
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
