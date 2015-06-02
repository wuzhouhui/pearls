#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void siftdown(int *x, int l, int u)
{
	if (l >= u)
		return;

	int	i, t, c;

	i = l, t = x[l];
	while (1) {
		c = i << 1;
		if (c > u)
			break;
		if (c + 1 <= u && x[c + 1] < x[c])
			c++;
		if (x[c] >= t)
			break;
		x[i] = x[c];
		i = c;
	}
	x[i] = t;
}

int main(int argc, char *argv[])
{
	int	n, i, *x;

	if (argc != 2 || (n = atoi(argv[1])) <= 0)
		n = 32;
	x = malloc((n + 1) * sizeof(int));
	srand((unsigned int)time(NULL));
	for (i = 1; i <= n; i++)
		x[i] = rand() % n;
	for (i = n - 1; i >= 1; i--)
		siftdown(x, i, n);
	for (i = 1; i <= n; i++) {
		printf("%d\n", x[1]);
		x[1] = x[n - i + 1];
		siftdown(x, 1, n - i);
	}

	free(x);
}
