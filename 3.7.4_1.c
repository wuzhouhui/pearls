/*
 * print the number of days bwtween two date.
 *
 * demo:
 *	./a.out 1934 3 3 2015 4 25
 */
#include <stdio.h>
#include <stdlib.h>

#define is_leap(year) ((year % 4 == 0 && year % 100) || (year % 400 == 0))

static int mon_day_accu[] = {
	0,
	31,
	31 + 28,
	31 + 28 + 31,
	31 + 28 + 31 + 30,
	31 + 28 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
};

static int diff_days(const int *, const int *);

int main(int argc, char *argv[])
{
	if (argc != 7) {
		fputs("demo: ./a.out 1934 3 3 2015 4 25\n", stderr);
		exit(0);
	}
	int	date1[3], date2[3];

	date1[0] = atoi(argv[1]);
	date1[1] = atoi(argv[2]);
	date1[2] = atoi(argv[3]);
	date2[0] = atoi(argv[4]);
	date2[1] = atoi(argv[5]);
	date2[2] = atoi(argv[6]);
	printf("the diff days is %d\n", diff_days(date1, date2));
	exit(0);
}

static int diff_days(const int *date1, const int *date2)
{
	int	days1, days2;

	days1 = (date1[0] - 1) * 365 + mon_day_accu[date1[1] - 1] + date1[2];
	days2 = (date2[0] - 1) * 365 + mon_day_accu[date2[1] - 1] + date2[2];

	if (is_leap(date1[0]) && date1[1] >= 2)
		days1++;
	if (is_leap(date2[0]) && date2[1] >= 2)
		days2++;
	days1 += (date1[0] - 1) / 4 - (date1[0] - 1) / 100 + (date1[0] - 1) / 400;
	days2 += (date2[0] - 1) / 4 - (date2[0] - 1) / 100 + (date2[0] - 1) / 400;

	days1 = days1 - days2;
	return(days1 > 0 ? days1 : -days1);
}
