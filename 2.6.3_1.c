/*
 * magic algorithm for rotate a array.
 *
 * ./a.out <sequence> <step>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void shift(char *, int);
static int gcd(int, int);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <sequence> <step>\n", stderr);
		exit(0);
	}
	printf("%s\n", argv[1]);
	shift(argv[1], atoi(argv[2]));
	printf("%s\n", argv[1]);
	return(0);
}

static void shift(char *seq, int step)
{
	int	len, j, i, k, l;
	char	tmp;

	len = strlen(seq);
	step %= len;
	j = gcd(len, step);

	for (i = 0; i < j; i++) {
		tmp = seq[i];
		k = i;
		while (1) {
			l = (k + step) % len;
			if (l == i)
				break;
			seq[k] = seq[l];
			k = l;
		}
		seq[k] = tmp;
	}
}

static int gcd(int m, int n)
{
	while (m != n) {
		if (m > n)
			m -= n;
		else 
			n -= m;
	}
	return(m);
}
