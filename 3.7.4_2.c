/*
 * return the week day of a specified date. the 1900-1-1 is Monday.
 *
 * ./a.out <year> <month> <day>
 */
#include <stdio.h>
#include <stdlib.h>

#define is_leap(year) ((year % 4 == 0 && year % 100) || (year % 400 == 0))
#define START_YEAR	1900
#define START_DAY	1

static char *weekdays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
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

static char *get_weekday(int, int, int);

int main(int argc, char *argv[])
{
	if (argc != 4) {
		fputs("./a.out <year> <month> <day>\n", stderr);
		exit(0);
	}

	int	year, mon, day;

	if ((year = atoi(argv[1])) < 1900) {
		fputs("the year must great than 1900\n", stderr);
		exit(0);
	}
	if ((mon = atoi(argv[2])) < 1 || mon > 12) {
		fputs("the month must between 1 and 12\n", stderr);
		exit(0);
	}
	if ((day = atoi(argv[3])) < 1 || day > 31) {
		fputs("the day must between 1 and 31\n", stderr);
		exit(0);
	}

	printf("%d-%d-%d is %s\n", year, mon, day, get_weekday(year, mon, day));
	exit(0);
}

static char *get_weekday(int year, int mon, int day)
{
	if (year < 1900 || !(mon > 0 && mon < 13) || !(day > 0 && day < 32))
		return(NULL);

	int	days, i;

	days = (year - START_YEAR) * 365;
	for (i = START_YEAR; i < year; i++)
		if (is_leap(i))
			days++;
	days += mon_day_accu[mon - 1];
	if (mon > 2 && is_leap(year))
		days++;
	days += day - START_DAY;
	if ((days = days % 7 + 1) == 7)
		days = 0;
	return(weekdays[days]);
}
