#include <stdio.h>
#include <time.h>

#define N	1024

static void ins_sort(int *, int);
static void init(int *, int);
static void print(const int *, int);

int main(void)
{
	int	x[N];
	
	init(x, N);
	ins_sort(x, N);
	print(x, N);
	return(0);
}

static void ins_sort(int *x, int n)
{
	int	i, t, j;

	if (!x || !n)
		return;

	for (i = 1; i < n; i++) {
		t = x[i];
		for (j = i - 1; j >= 0 && x[j] > t; j--)
			x[j + 1] = x[j];
		x[j + 1] = t;
	}
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
