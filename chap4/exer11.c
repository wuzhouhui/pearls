/*
 * uncorrect.
 */
#include <stdio.h>
#include <string.h>

static int binarysearch(const char *x, int n, char k)
{
	if (n <= 0)
		return(-1);
	if (n == 1)
		return(x[0] == k ? 0 : -1);

	int	m = n >> 1;
	if (k < x[m])
		return(binarysearch(x, m, k));
	if (k > x[m])
		return(binarysearch(x + m + 1, n - m - 1, k));
	return(m);
}

int main(int argc, char **argv)
{
	printf("%d\n", binarysearch(argv[1], strlen(argv[1]), argv[2][0]));
	return(0);
}
