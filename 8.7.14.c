#define abs(x) (x < 0 ? -x : x)

static int zeroest(const float *, int, int);

int main(void)
{}

static int zeroest(const float *x, int n, int m)
{
	if (n < (m + 1))
		return(-1);

	int	i, res;
	float	sum, min_sum;

	/* min_sum = x[0] + ... + x[m] */
	for (i = 0, min_sum = .0; i <= m; i++)
		min_sum += x[i];

	res = 0;
	for (sum = min_sum, i = m + 1; i < n; i++) {
		sum += x[i] - x[i - m - 1];
		if (abs(sum) < abs(min_sum)) {
			min_sum = sum;
			res = i - m;
		}
	}
	return(res);
}
