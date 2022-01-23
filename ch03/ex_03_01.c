#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
  int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("%d\n", binsearch(10, num, 10));

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low + high) / 2;

    if (x > v[mid]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return (v[low] == x) ? low : -1;
}
