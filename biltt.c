#include "main.h"

/**
 * builtinss - changes the current working directory
 * @argv: refers to the array of pointers to the arguments
 * Return: 1
*/
int builtinss(char **argv)
{
int i;

if (our_strcmp(argv[0], "exit") == 0)
{
if (argv[1] != NULL)
{
exit(atoi(argv[1]));
}
else
{
exit(0);
}
}
else if (our_strcmp(argv[0], "env") == 0)
{
char **env = environ;
while (*env != NULL)
{
for (i = 0; (*env)[i] != '\0'; i++)
{
our_putchar((*env)[i]);
}
our_putchar('\n');
env++;
}
return (0);
}
return (1);
}
