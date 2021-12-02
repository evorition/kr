#include <stdio.h>

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = -30;
  upper = 30;
  step = 10;

  celsius = lower;
  printf("Celsius Fahrenheit\n");
  while (celsius <= upper) {
    fahr = (celsius * 9.0) / 5.0 + 32.0;
    printf("%2.0f %10.2f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
