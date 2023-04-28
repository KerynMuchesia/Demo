#include "main.h"

/**
 * main - Main entry point for the shell program
 * Return: The exit status of the last executed command.
 */

int main(void)
{
char *prompt = "(Wood) $ ";
char *lineptr = NULL;
size_t m = 0;
ssize_t read_chars;
const char *delim = " \n";
int num_tokens = 0;
char **argv;
int status = 0;
int i;

while (1)
{
for (i = 0; prompt[i] != '\0'; i++)
our_putchar(prompt[i]);

read_chars = getline(&lineptr, &m, stdin);
/* checking if the getline function failed or reached EOF or CTRL + D */
if (read_chars == -1)
{
return (0);
}
/* checking if the user input is "Exiting...." */
if (our_strcmp(lineptr, "EXITING\n") == 0)
{
break;
}
/* splitting the string (lineptr) into an array of words */
argv = split_input(lineptr, delim, &num_tokens);
if (argv == NULL)
{
return (-1);
}
for (i = 0; i < num_tokens; i++)
{
free(argv[i]);
}
free(argv);
}
free(lineptr);
return (status);
}
