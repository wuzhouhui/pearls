/*
 * binary search of recursion.
 *
 * ./a.out <key> <sequence>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int bin_sear(char, const char *, int, int);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <key> <sequence>\n", stderr);
		exit(0);
	}
	printf("%d\n", bin_sear(argv[1][0], argv[2], 0, strlen(argv[2]) - 1));
	exit(0);
}

static int bin_sear(char key, const char *str, int lb, int hb)
{
	if (lb > hb)
		return(-1);
	int	m;

	m = (lb + hb) / 2;
	if (key < str[m])
		bin_sear(key, str, lb, m - 1);
	else if (key > str[m])
		bin_sear(key, str, m + 1, hb);
	else 
		return(m);
}
