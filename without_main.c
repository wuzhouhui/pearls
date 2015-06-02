/*
 * gcc -nostartfiles
 */
#include <stdio.h>
#include <stdlib.h>

int my_main(void)
{
	printf("this is a program without main!\n");
	return(0);
}

void _start(void)
{
	(void)my_main();
	exit(0); /* must be exit(), not return */
}
