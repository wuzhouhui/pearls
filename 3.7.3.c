/*
 * ./a.out <letters>
 */
#include <stdio.h>
#include <stdlib.h>

static char *banner(char);
static void parse(char *);

static char *banners[] = { 
	" \002A\004 \002\n"
	" \001A\001 \004A\001 \001\n"
	" \001A\001 \004A\001 \001\n"
	" \001A\006 \001\n"
	" \001A\006 \001\n"
	" \001A\001 \004A\001 \001\n"
	" \001A\001 \004A\001 \001\n"
	" \001A\001 \004A\001 \001\n"
};

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fputs("./a.out <uppercases>\n", stderr);
		exit(0);
	}

	int	i;

	for (i = 0; 'A' <= argv[1][i] && argv[1][i] <= 'Z'; i++)
		parse(banner(argv[1][i]));

	return(0);
}

static char *banner(char c)
{
	return(banners[c - 'A']);
}

static void parse(char *code) 
{
	char	c, l;

	while (*code) {
		if ((c = *code++) == '\n') {
			putchar('\n');
			continue;
		}

		l = *code++;
		while (l-- > 0)
			putchar(c);
	}
}
