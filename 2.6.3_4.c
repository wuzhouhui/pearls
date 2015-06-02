/*
 * block and iteration algorithm for rotate a array.
 *
 * ./a.out <sequence> <step>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void shift(char *, int);
static void swap(char *, char *, int);

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

static void shift(char *seq, int rotdist)
{
	int	n = strlen(seq);
	int	i, j, p;

	if ((rotdist %= n) == 0)
		return;
	i = p = rotdist;
	j = n - p;
	while (i != j) {
		if (i > j) {
			swap(seq + p - i, seq + p, j);
			i -= j;
		} else {
			swap(seq + p - i, seq + p + j - i, i);
			j -= i;
		}
	}
	swap(seq + p - i, seq + p, i);
}

static void swap(char *seq1, char *seq2, int l)
{
	char	tmp;

	while (l-- > 0) {
		tmp = *(seq1 + l);
		*(seq1 + l) = *(seq2 + l);
		*(seq2 + l) = tmp;
	}
}
