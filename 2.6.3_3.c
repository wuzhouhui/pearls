/*
 * block and recursion algorithm for rotate a array.
 *
 * ./a.out <sequence> <step>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void shift(char *, int, int, int);
static void swap(char *, char *, int);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fputs("./a.out <sequence> <step>\n", stderr);
		exit(0);
	}

	int	h = strlen(argv[1]);
	int	b = atoi(argv[2]) % h;

	printf("%s\n", argv[1]);
	shift(argv[1], 0, h - 1, b - 1);
	printf("%s\n", argv[1]);
	return(0);
}

/*
 * l: lower bound
 * h: higher bound 
 * b: middle bound
 */
static void shift(char *seq, int l, int h, int b)
{
	int	l1, l2;

	if (!(l >= 0 && b >= l && b <= h))
		return;
	l1 = b - l + 1;
	l2 = h - b;
	if (l1 < l2) {
		swap(seq + l, seq + h - l1 + 1, l1);
		shift(seq, l, h - l1, b);
	} else if (l1 > l2) {
		swap(seq + l, seq + b + 1, l2);
		shift(seq, l + l2, h, b);
	} else {
		swap(seq + l, seq + b + 1, l1);
	}
}

static void swap(char *seq1, char *seq2, int len)
{
	char	tmp;

	while (len-- > 0) {
		tmp = *(seq1 + len);
		*(seq1 + len) = *(seq2 + len);
		*(seq2 + len) = tmp;
	}
}
