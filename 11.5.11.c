
#include <stdio.h>
#include <time.h>

#define N	1024

static void qsort(int *, int, int);
static void init(int *, int);
static void print(const int *, int);
static inline void swap(int *a, int *b)
{
	int	t;
	t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	int	x[N];

	init(x, N);
	qsort(x, 0, N - 1);
	print(x, N);
	return(0);
}

static void qsort(int *x, int l, int u)
{
	if (l >= u)
		return;

	int	i, m1, m2;

	m1 = l;
	m2 = -1;
	for (i = l + 1; i <= u; i++) {
		if (x[i] == x[l]) {
			if (m2 < 0) {
				m2 = m1 + 1;
				swap(x + m2, x + i);
			} else {
				swap(x + (++m2), x + i);
			}
		} else if (x[i] < x[l]) {
			if (m2 < 0) {
				swap(x + (++m1), x + i);
			} else {
				swap(x + (++m1), x + i);
				swap(x + (++m2), x + i);
			}
		}
	}
	swap(x + m1, x + l);
	qsort(x, l, m1 - 1);
	if (m2 > 0)
		qsort(x, m2 + 1, u);
	else 
		qsort(x, m1 + 1, u);
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
