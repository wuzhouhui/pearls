#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void siftup(int *x, int n)
{
	/*
	 * precond: heap(1, n-1)
	 * postcond: heap(1, n)
	 */
	int	i, p;

	x[0] = x[n];	/* sentinel */
	i = n;
	while (1) {
		p = i >> 1;
		if (x[p] >= x[0])
			break;
		x[i] = x[p];
		i = p;
	}
	x[i] = x[0];
}

static void siftdown(int *x, int n)
{
	/*
	 * precond: heap(2, n)
	 * postcond: heap(1, n);
	 */
	if (n < 2)
		return;

	int	i, c;

	i = 1;
	x[0] = x[1];
	while (1) {
		c = i << 1;
		if (c > n)
			break;
		if ((c + 1) <= n && x[c + 1] > x[c])
			c++;
		if (x[0] >= x[c])
			break;
		x[i] = x[c];
		i = c;
	}
	x[i] = x[0];
}
int main(int argc, char *argv[])
{
	int	*x, i, n, t;

	if (argc == 2)
		n = atoi(argv[1]);
	else if (argc != 2 || n <= 0)
		n = 32;
	x = (int *)malloc(sizeof(int) * (n + 1));
	srand((unsigned int)time(NULL));
	for (i = 1; i <= n; i++)
		x[i] = rand() % n;

	/* build heap */
	for (i = 2; i <= n; i++)
		siftup(x, i);

	/* sort */
	for (i = n; i > 1; i--) {
		t = x[i];
		x[i] = x[1];
		x[1] = t;
		siftdown(x, i - 1);
	}

	for (i = 1; i <= n; i++)
		printf("%d\n", x[i]);
	free(x);
	return(0);
}
