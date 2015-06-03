#include <stdio.h>
#include <string.h>

static swap(char *s, int l1, int r1, int l2, int r2)
{
	while (l1 <= r1) {
		r2 = s[l1];
		s[l1] = s[l2];
		s[l2] = (char)r2;
		l1++;
		l2++;
	}
}

static void swap_requr(char *s, int l, int m, int r)
{
	int	l1 = m - l + 1;
	int	l2 = r - m;
	if (l1 == l2) {
		swap(s, l, m, m + 1, r);
		return;
	}
	if (l1 > l2) {
		swap(s, l, r - m + l - 1, m + 1, r);
		swap_requr(s, r - m + l, m, r);
	} else {
		swap(s, l, m, r - m + l, r);
		swap_requr(s, l, m, r - m + l - 1);
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return(0);

	int	k = atoi(argv[2]);
	int	l = strlen(argv[1]);
	if (k %= l)
		swap_requr(argv[1], 0, k - 1, l - 1);
	printf("%s\n", argv[1]);
}
