#include <stdio.h>
#include <string.h>

static int bin_sch(const char *s, int l, int u, char k)
{
	if (l > u)
		return(-1);
	if (l == u)
		return(s[l] == k ? l : -1);
	int	m = (l + u);
	if (k < s[m])
		return(bin_sch(s, l, m - 1, k));
	if (k > s[m])
		return(bin_sch(s, m + 1, u, k));
	return(m);
}

int main(int argc, char *argv[])
{
	if (argc < 3)
		return(0);

	printf("%d\n", bin_sch(argv[1], 0, strlen(argv[1]) - 1, argv[2][0]));
	return(0);
}
