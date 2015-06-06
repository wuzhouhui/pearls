
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int commlen(const char *str1, const char *str2)
{
	int	i = 0;
	while (*str1 && (*str1++ == *str2++))
		i++;
	return(i);
}

int main(int argc, char **argv)
{
	int	l1, l2;
	int	i, j, t, maxlen, ind;
	char	**post1, **post2, *str;

	l1 = strlen(argv[1]);
	l2 = strlen(argv[2]);
	post1 = malloc(l1 * sizeof(char *));
	post2 = malloc(l2 * sizeof(char *));
	for (i = 0; i < l1; i++) 
		post1[i] = &argv[1][i];
	for (i = 0; i < l2; i++)
		post2[i] = &argv[2][i];
	qsort(post1, l1, sizeof(char *), (int (*)(const void *, 
					const void *))strcmp);
	qsort(post2, l2, sizeof(char *), (int (*)(const void *, 
					const void *))strcmp);
	i = j = 0;
	maxlen = -1;
	while (i < l1 && j < l2) {
		t = commlen(post1[i], post2[j]);
		if (t > maxlen) {
			maxlen = t;
			str = post1[i];
		}
		if (strcmp(post1[i], post2[j]) < 0)
			i++;
		else 
			j++;
	}
	
	for (i = 0; i < maxlen; i++)
		putchar(str[i]);
	putchar('\n');
	free(post1);
	free(post2);
	return(0);
}
