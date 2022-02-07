#include <stdio.h>
#define swap(t, x, y) {\
  t temp;\
  temp = x;\
  x = y;\
  y = temp;\
}

int main(void) {
  int x, y;
  x = 2;
  y = 3;

  swap(int, x, y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
