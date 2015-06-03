#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void reverse(char *str, int s, int e)
{
	char *ptr = malloc(e - s + 1);
	int	i, j;

	i = 0;
	j = e;
	while (j >= s) {
		ptr[i++] = str[j--];
	}
	memcpy(str + s, ptr, e - s + 1);
	free(ptr);
	return;
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return(0);

	int	k = atoi(argv[2]);
	int	l = strlen(argv[1]);

	if (k %= l) {
		reverse(argv[1], 0, k - 1);
		reverse(argv[1], k, l - 1);
		reverse(argv[1], 0, l - 1);
	}
	printf("%s\n", argv[1]);
	return(0);
}
