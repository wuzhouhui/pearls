void siftdown(int *x, int n)
{
	if (n < 2)
		return;

	int	t, c, i;

	t = x[1];
	i = 1;
	while (1) {
		c = i << 1;
		if (c > n)
			break;
		if (c + 1 <= n && x[c + 1] < x[c])
			c++;
		if (t <= x[c])
			break;
		x[i] = x[c];
		i = c;
	}
	x[i] = t;
}
