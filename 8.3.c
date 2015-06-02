static int max_seq_sum(int *seq, int l, int u)
{
	if (l > u)
		return(0);
	if (l == u)
		return(0 > seq[l] ? 0 : seq[l]);
	int	m, lmax, rmax, sum;
	int	i;
	int	left, right;

	m = (l + u) / 2;

	lmax = sum = 0;
	for (i = m; i >= l; i--) {
		sum += seq[i];
		lmax = lmax > sum ? lmax : sum;
	}

	rmax = sum = 0;
	for (i = m; i <= u; i++) {
		sum += seq[i];
		rmax = rmax > sum ? rmax : sum;
	}
	lmax += rmax;
	
	left = max_seq_sum(seq, l, m);
	right = max_seq_sum(seq, m + 1, u);
	
	left = left > right ? left : right;
	return(left > lmax ? left : lmax);
}

int main(void)
{}
