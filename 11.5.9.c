/*
 * wrong
 */
#include <stdio.h>
#include <time.h>

#define N	1024

static inline void swap(int *, int *);

static int select(int *x, int len, int n)
{
	int	i, k, j;

	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < len; j++)
			if (x[j] < x[k])
				k = j;
		swap(x + k, x + i);
	}
	return(x[n - 1]);
}

static inline void swap(int *a, int *b)
{
	int	t;
	t = *a;
	*a = *b;
	*b = t;
}

static void init(int *x, int n)
{
	if (!x || !n)
		return;

	int	i;

	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++)
		x[i] = rand() % n;
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

static int pick_by_sort(int *x, int l, int u, int n)
{
	if (l >= u)
		return(l);

	int	m, i;

	m = l;
	for (i = l + 1; i <= u; i++) {
		if (x[i] < x[l])
			swap(x + (++m), x + i);
	}
	swap(x + l, x + m);
	if (m == (n - 1))
		return(x[m]);
	if (m < (n - 1))
		return(pick_by_sort(x, m + 1, u, n));
	return(pick_by_sort(x, l, m - 1, n));
}

static int pick(int *x, int len, int n)
{
	if (n < 1 || n > len)
		return(-1);
	if (n < 8)
		return(select(x, len, n));
	return(pick_by_sort(x, 0, len - 1, n));
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return(0);

	int	x[N];

	init(x, N);
	printf("%d\n", pick(x, N, atoi(argv[1])));
	print(x, N);
	return(0);
}
