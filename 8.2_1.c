int main(void)
{
	int	i, j;
	const int n = 10;
	int	seq[n], sum, max;

	max = 0;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = i; j < n; j++) {
			sum += seq[j];
			max = max > sum ? max : sum;
		}
	}
	return(0);
}
