#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#define N	10000000
#define K	1000000
#define SHIFT	5
#define MASK	0x1f

#define setbit(x, i)	(x[i >> SHIFT] |= (1 << (i & MASK)))
#define clrbit(x, i)	(x[i >> SHIFT] &= ~(1 << (i & MASK)))
#define getbit(x, i)	(x[i >> SHIFT] & (1 << (i & MASK)))

/* priority of plus higher than shift */
static int	arr[(N >> SHIFT) + 1];

int main(void)
{
	int	i, t;
	FILE	*fp;

	bzero(arr, sizeof(arr));
	fp = fopen("./uniq_rand.txt", "r");
	for (i = 0; i < K; i++) {
		fscanf(fp, "%d", &t);
		setbit(arr, t);
	}
	fclose(fp);

	fp = fopen("./sort.txt", "w");
	for (i = 0; i < N; i++) {
		if (getbit(arr, i))
			fprintf(fp, "%d\n", i);
	}
	fclose(fp);
	return(0);
}
