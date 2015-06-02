#include <stdio.h>
#include <time.h>

#define N	1024
#define CUTOFF	(N >> 7)

static inline void swap(int *a, int *b)
{
	int	t;
	t = *a;
	*a = *b;
	*b = t;
}

static void qsort(int *x, int l, int u)
{
	if (u - l < CUTOFF)
		return;

	int	i, j;

	srand((unsigned int)time(NULL));
	swap(x + l, x + l + (rand() % (u - l + 1)));
	
	i = l;
	j = u + 1;
	while (1) {
		do i++; while (i <= u && x[i] < x[l]);
		do j--; while (x[j] > x[l]);
		if (i > j)
			break;
		swap(x + i, x + j);
	}
	swap(x + l, x + j);
	qsort(x, l, j - 1);
	qsort(x, j + 1, u);
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

static void insort(int *x, int n)
{
	if (!x || !n || n == 1)
		return;
	
	int	i, j, t;

	for (i = 1; i < n; i++) {
		t = x[i];
		for (j = i - 1; j >= 0 && x[j] > t; j--)
			x[j + 1] = x[j];
		x[j + 1] = t;
	}
}

int main(void)
{
	int	x[N];

	init(x, N);
	qsort(x, 0, N - 1);
	insort(x, N);
	print(x, N);
	return(0);
}
