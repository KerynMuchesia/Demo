#include "main.h"

/**
 * my_putchar - takes a single character c as input and returns an integer value
 * @c: the character to be printed
 * Return -1 on error
 */

int my_putchar(char c)
{
	return(write(STDOUT_FILENO, &c, 1));
}

