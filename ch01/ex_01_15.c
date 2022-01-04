#include <stdio.h>

float fahr_to_celsius(float fahr);

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahrenheit Celsius\n");
  while (fahr <= upper) {
    celsius = fahr_to_celsius(fahr);
    printf("%3.0f %13.2f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}

float fahr_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
