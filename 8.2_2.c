int main(void)
{
	int	i, j;
	const int n = 10;
	int	seq[n + 1];
	int	*seqptr = &seq[1];
	int	max, sum;

	seqptr[-1] = 0;
	for (i = 0; i < n; i++)
		seqptr[i] += seqptr[i - 1];

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			sum = seqptr[j] - seqptr[i - 1];
			max = max > sum ? max : sum;
		}
	}
	return(0);
}
