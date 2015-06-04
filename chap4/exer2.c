#include <stdio.h>
#include <string.h>

static int bin_sch(const char *s, char k)
{
	int	len, l, u, m;

	if ((len = strlen(s)) == 0)
		return(-1);
	l = -1;
	u = len;
	while ((l + 1) != u) {
		/*
		 * s[l] < k <= s[u]
		 */
		m = (l + u) / 2;
		if (k > s[m])
			l = m;
		else 
			u = m;
	}
	if (u >= len || s[u] != k)
		return(-1);
	return(u);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return(0);
	printf("%d\n", bin_sch(argv[1], argv[2][0]));
	return(0);
}
