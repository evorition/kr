#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void) {
  int day, month;

  printf("day of the year: %d\n", day_of_year(1996, 8, 31));
  month_day(1996, 244, &month, &day);
  printf("month: %d day: %d\n", month, day);

  return 0;
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
  char leap, *p;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = *(daytab + leap);
  while (--month) {
    day += *++p;
  }
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  char leap, *p;

  leap = year % 4 == 0 && year % 100 != 100 || year % 400 == 0;
  p = *(daytab + leap);

  while (yearday > *++p) {
    yearday -= *p;
  }
  *pmonth = p - *(daytab + leap);
  *pday = yearday;
}
