#include "main.h"

/**
 * execute_builtin - checks for builtins and executes them
 * @args: array of pointers to the arguments
 * Return: 1 if the function is a builtin, 0 otherwise
 */
int execute_builtin(char **args)
{
	builtin_t builtins[] = {
		{"exit", our_exit},
		{"cd", our_cd},
		{"env", our_env},
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return (builtins[i].func(args));
		}
	}

	return (0);
}
