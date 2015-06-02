/*
 * ./a.out <n>
 *
 * 0 <= n <= 65535
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN	5
#define MAX_VAL	65535

static char *get_7(int);

static char code_predef[10] = { 
	(char)0b11111110,	/* 0 */
	(char)0b00001010,	/* 1 */
	(char)0b11101100,	/* 2 */
	(char)0b11101010,	/* 3 */
	(char)0b01011010,	/* 4 */
	(char)0b11110010,	/* 5 */
	(char)0b11110110,	/* 6 */
	(char)0b00101010,	/* 7 */
	(char)0b11111110,	/* 8 */
	(char)0b01111010,	/* 9 */
};

int main(int argc, char *argv[])
{
	if (argc != 2)
		exit(0);
	(void)get_7(atoi(argv[1]));
	exit(0);
}

static char *get_7(int val)
{
	if (val < 0 || val > MAX_VAL)
		return(NULL);

	int	i;
	static char code_7[LEN];

	memset(code_7, code_predef[0], sizeof(code_7));
	i = LEN - 1;
	while (val) {
		code_7[i--] = code_predef[val % 10];
		val /= 10;
	}
	return code_7;
}
