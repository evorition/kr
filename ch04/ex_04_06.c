#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define VARS 26
#define NUMBER '0'

int getop(char s[]);
int getvar(void);
void push(double);
double pop(void);
double top(void);
void duplicate(void);
void swtch(void);
void clear(void);

int main(void) {
  int type;
  double op2;
  char s[MAXOP];
  double var[VARS];

  while ((type = getop(s)) != EOF) {
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
      case '%':
        op2 = pop();
        if (op2 != 0.0) {
          push((int) pop() % (int) op2);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      case 's':
        push(sin(pop()));
        break;
      case 'e':
        push(exp(pop()));
        break;
      case 'p':
        op2 = pop();
        if (top() == 0.0 && op2 <= 0) {
          printf("error: math error\n");
        } else if (top() < 0 && fmod(op2, 1.0) != 0.0) {
          printf("error: math error\n");
        } else {
          push(pow(pop(), op2));
        }
        break;
      case '@':
        printf("\t%.8g\n", top());
        break;
      case '#':
        duplicate();
        break;
      case '$':
        swtch();
        break;
      case '~':
        clear();
        break;
      // set variable
      case '?':
        if ((type = getvar()) != -1) {
          var[type - 'a'] = top();
        }
        break;
      // get variable
      case '!':
        if ((type = getvar()) != -1) {
          push(var[type - 'a']);
        }
        break;
      case '\n':
        printf("\t%.8g\n", (var['z' - 'a'] = pop()));
        break;
      default:
        printf("error: unknown command %c\n", type);
        break;
    }
  }
  return 0;
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

double top(void) {
  if (sp > 0) {
    return val[sp - 1];
  } else {
    printf("error: stack is empty\n");
  }
}

void duplicate(void) {
  if (sp > 0) {
    double op = pop();
    push(op);
    push(op);
  } else {
    printf("error: not enough elements in stack\n");
  }
}

void swtch(void) {
  if (sp >= 2) {
    double op1 = pop();
    double op2 = pop();
    push(op2);
    push(op1);
  } else {
    printf("error: not enugh elements in stack\n");
  }
}

void clear(void) {
  if (sp > 0) {
    sp = 0;
  }
}

#include <ctype.h> 

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch())  == ' ' || c == '\t') {
    ;
  }
  s[1] = '\0';
  if (!isdigit(c) && (c != '.' && c != '-')) {
    return c;
  }
  i = 0;
  if (c == '-') {
    if (!isdigit(s[++i] = c = getch()) && c != '.') {
      if (c != EOF) {
        ungetch(c);
      }
      return '-';
    }
  }
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}

int getvar(void) {
  int c;

  if ((c = getch()) >= 'a' && c <= 'z') {
    return c;
  } else {
    ungetch(c);
    return -1;
  }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
