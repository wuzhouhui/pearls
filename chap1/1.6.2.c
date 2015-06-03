#define BITS_PER_WORD	(sizeof(int) * 8)
#define set_bit(a, i) \
	(a[i / BITS_PER_WORD] |= (1 << (i % BITS_PER_WORD)))
#define clr_bit(a, i) \
	(a[i / BITS_PER_WORD] &= ~(1 << (i % BITS_PER_WORD)))
#define get_bit(a, i) \
	(a[i / BITS_PER_WORD] & (1<< (i % BITS_PER_WORD)))
