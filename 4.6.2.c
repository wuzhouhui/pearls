/*
 * binary search, return the subscript of key in first occurence.
 *
 * ./a.out <key> <sequence>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int bin_sear_1st(char, const char *);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <key> <sequence>\n", stderr);
		exit(0);
	}
	printf("%d\n", bin_sear_1st(argv[1][0], argv[2]));
	exit(0);
}

static int bin_sear_1st(char key, const char *str)
{
	int	l, u;
	int	m, p, n;

	l = -1;
	u = n = strlen(str);
	while (l + 1 != u) {
		/* invariant: x[l] < t && x[u] >= t && l < u */
		m = (l + u) / 2;
		if (str[m] < key)
			l = m;
		else 
			u = m;
		/* assert l + 1 <= u && x[l] < t && x[u] >= t */
		p = u;
		if (p >= n || str[p] != key)
			p = -1;
	}
	return(p);
}
