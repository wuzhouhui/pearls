/*
 * date function. return month and day within the month according a
 * specified year and day within the year.
 *
 * programming pears 2nd edition, page 29, section 3.3
 *
 * ./a.out <year> <day_within_year>
 */
#include <stdio.h>
#include <stdlib.h>

static void month_day(int, int);

static int feb_day[] = { 28, 29 };
static int day_per_mon[] = {
	31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static int mon_day_accu[] = {
	0,
	31,
	31 + 0,
	31 + 0 + 31,
	31 + 0 + 31 + 30,
	31 + 0 + 31 + 30 + 31,
	31 + 0 + 31 + 30 + 31 + 30,
	31 + 0 + 31 + 30 + 31 + 30 + 31,
	31 + 0 + 31 + 30 + 31 + 30 + 31 + 31,
	31 + 0 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	31 + 0 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	31 + 0 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
};

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <year> <day_within_year>\n", stderr);
		exit(0);
	}
	month_day(atoi(argv[1]), atoi(argv[2]));
	return(0);
}

static void month_day(int year, int day_within_year)
{
	if (year <= 0 || day_within_year <= 0 || day_within_year > 366) {
		printf("the year and day_within_year both great then 0\n");
		return;
	}

	int leap = 0, i, day;

	if ((year % 4 == 0 && year % 100) || (year % 400 == 0))
		leap = 1;

	for (i = 1; i <= 12; i++)
		if ((day = day_within_year - mon_day_accu[i - 1] -
					(i < 3 ? 0 : feb_day[leap]))
				<= (i == 2 ? feb_day[leap] : day_per_mon[i - 1]))
			break;

	printf("month %d, day %d\n", i, day);
}
