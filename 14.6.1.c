#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void siftdown(int *, int);
void siftup(int *, int);

int main(int argc, char *argv[])
{
	int	n, i, *x;

	if (argc != 2 || (n = atoi(argv[1])) <= 0)
		n = 32;
	x = malloc((n + 1) * sizeof(int));
	srand((unsigned int)time(NULL));
	for (i = 1; i <= n; i++) {
		x[i] = rand() % n;
		printf("%d\n", x[i]);
		siftup(x, i);
	}
	for (i = 1; i <= n; i++) {
		printf("%d\n", x[1]);
		x[1] = x[n - i + 1];
		siftdown(x, n - i);
	}
	free(x);
}
