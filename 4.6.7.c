/*
 * ./a.out <key> <sequence>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int bin_sear(char, const char *, char *, char *);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <key> <sequence>\n", stderr);
		exit(0);
	}

	char	l, u;

	if (!bin_sear(argv[1][0], argv[2], &l, &u))
		printf("%c, %c\n", l, u);
	exit(0);
}

static int bin_sear(char key, const char *str, char *l, char *u)
{
	int	lb, ub, m, n;

	lb = 0;
	ub = n = strlen(str) - 1;
	while (1) {
		m = (lb + ub) / 2;
		if (str[m] <= key) {
			if (m == n)
				return(-1);
			if (str[m + 1] >= key) {
				*l = str[m];
				*u = str[m + 1];
				return(0);
			}
			lb = m + 1;
			continue;
		}
		if (str[m] >= key) {
			if (m == 0)
				return(-1);
			if (str[m - 1] <= key) {
				*l = str[m - 1];
				*u = str[m];
				return(0);
			}
			ub = m - 1;
		}
	}
}
