#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void) {
  int day, month;

  printf("day of the year: %d\n", day_of_year(1996, 13, 31));
  month_day(2007, 366, &month, &day);
  printf("month: %d day: %d\n", month, day);

  return 0;
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
  int leap;

  if (year < 0) {
    printf("error: day_of_year incorrect year\n");
    return -1;
  } else if (month < 1 || month > 12) {
    printf("error: day_of_year incorrect month\n");
    return -1;
  }

  leap = year % 4 == 0 && year != 100 || year % 400 == 0;

  if (day < 1 || day > daytab[leap][month]) {
    printf("error day_of_year incorrect day\n");
    return -1;
  }

  for (int i = 1; i < month; ++i) {
    day += daytab[leap][i];
  }
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap, i;
  *pmonth = -1;
  *pday = -1;

  if (year < 0) {
    printf("error: month_day incorrect year\n");
    return;
  }

  leap = year % 4 == 0 && year != 100 || year % 400 == 0;

  if ((leap == 1 && yearday > 366) || (leap == 0 && yearday > 365)) {
    printf("error: month_day incorrect yearday\n");
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; ++i) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}
