/*
 * show calendar of month according specified year and month.
 *
 * ./a.out <year> <mon>
 */
#include <stdio.h>
#include <stdlib.h>

#define is_leap(year) ((year % 4 == 0 && year % 100) || (year % 400 == 0))
#define START_YEAR	1900
#define START_DAY	1
///* subscript about cal[] */
//#define FEB_NORM	0
//#define FEB_LEAP	1
//#define MON_30DAY	2
//#define MON_31DAY	3

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
//static char *cal[] = {
//	"Sun Mon Tue Wed Thu Fri Sat\n"
//	" 1   2   3   4   5   6   7 \n"
//	" 8   9   10  11  12  13  14\n"
//	" 15  16  17  18  19  20  21\n"
//	" 22  23  24  25  26  27  28\n"
//	"                             ",
//
//	"Sun Mon Tue Wed Thu Fri Sat\n"
//	" 1   2   3   4   5   6   7 \n"
//	" 8   9   10  11  12  13  14\n"
//	" 15  16  17  18  19  20  21\n"
//	" 22  23  24  25  26  27  28\n"
//	" 29                        \n"
//	"                             ",
//
//	"Sun Mon Tue Wed Thu Fri Sat\n"
//	" 1   2   3   4   5   6   7 \n"
//	" 8   9   10  11  12  13  14\n"
//	" 15  16  17  18  19  20  21\n"
//	" 22  23  24  25  26  27  28\n"
//	" 29  30                    \n"
//	"                             ",
//
//	"Sun Mon Tue Wed Thu Fri Sat\n"
//	" 1   2   3   4   5   6   7 \n"
//	" 8   9   10  11  12  13  14\n"
//	" 15  16  17  18  19  20  21\n"
//	" 22  23  24  25  26  27  28\n"
//	" 29  30  31                \n"
//	"                             ",
//};

static int get_weekday(int, int, int);
static void show_cal(int, int, int);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <year> <mon>\n", stderr);
		exit(0);
	}

	int	year, mon;

	if ((year = atoi(argv[1])) < 1900) {
		fputs("the year must great than 1900\n", stderr);
		exit(0);
	}
	if ((mon = atoi(argv[2])) < 1 || mon > 12) {
		fputs("the month must between 1 and 12\n", stderr);
		exit(0);
	}
	show_cal(year, mon, get_weekday(year, mon, 1));
	exit(0);
}

static int get_weekday(int year, int mon, int day)
{
	if (year < 1900 || !(mon > 0 && mon < 13) || !(day > 0 && day < 32))
		return(-1);

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
	return(days);
}

static void show_cal(int year, int mon, int week_start)
{
	static char *head = "Su Mo Tu We Th Fr Sa\n";
	int	i, wrap, day;

	switch (mon) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		day = 31;
		break;
	case 4: case 6: case 9: case 11:
		day = 30;
		break;
	case 2:
		day = (is_leap(year) ? 29 : 28);
		break;
	default:
		fputs("month illegal\n", stderr);
		return;
	}

	printf("%s", head);
	wrap = 0;
	for (i = 0; i < week_start; i++) {
		printf("   ");
		wrap++;
	}
	for (i = 1; i <= day; i++) {
		printf("%-3d", i);
		if (++wrap % 7 == 0)
			putchar('\n');
	}
	putchar('\n');
}
