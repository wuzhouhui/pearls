/*
 * reversal algorithm for rotate a array.
 *
 * ./a.out <sequence> <step>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void shift(char *, int);
static void reverse(char *, int, int);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <sequence> <step>\n", stderr);
		exit(0);
	}
	printf("%s\n", argv[1]);
	shift(argv[1], atoi(argv[2]));
	printf("%s\n", argv[1]);
	return(0);
}

static void shift(char *seq, int step)
{
	int	len;

	len = strlen(seq);
	if ((step %= len) == 0)
		return;

	reverse(seq, 0, step - 1);
	reverse(seq, step, len - 1);
	reverse(seq, 0, len - 1);
}

static void reverse(char *seq, int l, int h)
{
	if (l == h)
		return;
	
	char	tmp;
	int	i, m;
	

	m = (h - l + 1) / 2 - 1;
	for (i = 0; i <= m; i++) {
		tmp = seq[l + i];
		seq[l + i] = seq[h - i];
		seq[h - i] = tmp;
	}
}
