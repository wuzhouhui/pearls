int main(void)
{
	int	i, j, k;
	const int n = 10;
	int	seq[n];
	int	sum, max;

	max = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			sum = 0;
			for (k = i; k <= j; k++)
				sum += seq[k];
			max = max > sum ? max : sum;
		}
	}
	return(0);
}
