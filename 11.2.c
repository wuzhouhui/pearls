/*
 * a test program for dead loop when x[l] is the greatest element.
 * page 129, footnote 1.
 *
 * carefully, this program would results in dead loop.
 */

#include <stdio.h>

static void qsort(int *, int, int);
static inline void swap(int *x, int *y)
{
	int	tmp = *x;
	*x = *y;
	*y = tmp;
}

static void print(const int *x, int n)
{
	if (!x || !n)
		return;

	int	i, wrap;

	for (i = wrap = 0; i < n; i++, wrap++) {
		if (wrap % 8 == 0)
			putchar('\n');
		printf("%6d", x[i]);
	}
	putchar('\n');
}

int main(void)
{
	int	x[10];
	int	i;

	for (i = 0; i < 10; i++)
		x[i] = 9 - i;
	qsort(x, 0, 9);
	print(x, 10);
	return(0);
}

static void qsort(int *x, int l, int u)
{
	if (l >= u)
		return;

	int	i, m;

	m = l;
	for (i = l + 1; i <= u; i++) {
		if (x[i] < x[l])
			swap(x + i, x + (++m));
	}
	qsort(x, l, m);	/* result in dead loop */
	qsort(x, m + 1, u);
}
