#include <stdlib.h>
#include <stdio.h>

#define N	100000
static int	x[N];

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int main(void)
{
	FILE	*fp;
	int	i;

	fp = fopen("./random.txt", "r");
	for (i = 0; i < N; i++)
		fscanf(fp, "%d", &x[i]);
	fclose(fp);

	fp = fopen("./sort.txt", "w");
	qsort(x, N, sizeof(int), intcmp);
	for (i = 0; i < N; i++) 
		fprintf(fp, "%d\n", x[i]);
	fclose(fp);
	return(0);
}
