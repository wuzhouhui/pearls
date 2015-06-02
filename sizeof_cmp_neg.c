/*
 * signed integer casted to unsigned when compare with unsigned.
 */
#include <stdio.h>

int main(void)
{
	int	a = -1;
	
	if (a < sizeof(a))
		printf("-1 less than sizeof(a)\n");
	else if (a > sizeof(a))
		printf("-1 greate than sizeof(a)\n");
	else 
		printf("-1 equals to sizeof(a)\n");
	return(0);
}
