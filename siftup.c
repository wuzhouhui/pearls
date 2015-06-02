void siftup(int *x, int n)
{
	if (n <= 1)
		return;

	int	i, p, t;

	i = n;
	x[0] = x[n];
	t = x[n];
	while (1) {
		p = i >> 1;
		if (x[p] <= t)
			break;
		x[i] = x[p];
		i = p;
	}
	x[i] = t;
}
