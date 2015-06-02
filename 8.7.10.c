#include <stdlib.h>

static int cmp_fun(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}
static float closest(float *x, int n, float t)
{
	if (!n)
		return(.0);
	if (n == 1)
		return(x[0]);

	float	cum[n + 1], *cumptr, min_diff, diff;
	int	i, j;

	cum[0] = .0;
	cumptr = &cum[1];
	for (i = 0; i < n; i++)
		cumptr[i] = cumptr[i - 1] + x[i];

	qsort(cumptr, n, sizeof(float), cmp_fun);
	min_diff = x[0];
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			diff = cumptr[j] - cumptr[i - 1] - t;
			if (diff < min_diff)
				min_diff = diff;
		}
	}
	return(min_diff);
}

int main(void)
{}
