#define SHIFT	5
#define MASK	0x1f

#define setbit(x, i)	(x[i >> SHIFT] |= 1 << (i & MASK))
#define clrbit(x, i)	(x[i >> SHIFT] &= ~(1 << (i & MASK)))
#define getbit(x, i)	(x[i >> SHIFT] & (1 << (i & MASK)))
