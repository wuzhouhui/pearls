/*
 * ./a.out <m> <k> <a1, a2, ... ,ak> <c1, c2, ... ,c(k+1)>
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc <= 5) {
		fputs("./a.out <k> <m> <a1, a2, ... ,ak> "
			"<c1, c2, ... ,c(k+1)>", stderr);
		exit(0);
	}

	int	k, m;
	int	i, j;
	long long *as, *cs;

	m = atoi(argv[1]);
	k = atoi(argv[2]);
	if (m <= k) {
		fputs("noting to do\n", stderr);
		exit(0);
	}

	as = malloc((m + 1) * sizeof(long long));
	cs = malloc((k + 2) * sizeof(long long));

	for (i = 1; i <= k; i++)
		as[i] = atoll(argv[i + 2]);
	for (i = 1; i <= (k + 1); i++)
		cs[i] = atoll(argv[i + k + 2]);

	for (i = 1; i <= m; i++) {
		if (i <= k) {
			printf("a[%d]\t= %lld\n", i, as[i]);
			continue;
		}

		as[i] = 0;
		for (j = 1; j < i; j++)
			as[i] += cs[j] * as[i - j];
		as[i] += cs[k + 1];
		printf("a[%d]\t= %lld\n", i, as[i]);
	}

	return(0);
}
