#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define	N	10000000
#define K	1000000 

static int	x[N];

int main(void)
{
	FILE	*fp;
	int	i, j, tmp;

	fp = fopen("./uniq_rand.txt", "w");
	srand(time(NULL));

	for (i = 0; i < N; i++)
		x[i] = i;
	for (i = 0; i < K; i++) {
		j = rand() % (N - i) + i;
		tmp = x[j];
		x[j] =  x[i];
		x[i] = tmp;
		fprintf(fp, "%d\n", x[i]);
	}

	fclose(fp);
	return(0);
}
