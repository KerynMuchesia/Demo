#include "main.h"

/**
 * execmd - executes a command
 * @argv: an array of pointers to the arguments
 * Return: returns the value of the last executed command
 */
void execmd(char **argv)
{
pid_t pid;
int status;
char *holder = NULL, *holder2[1010];
int worked;

worked = builtinss(argv);
if (worked == 0)
{
return;
}
holder2[0] = get_location(argv[0]);

if (access(holder2[0], X_OK) == -1)
{
perror("access");
return;
}
pid = fork();
if (pid == 0)
{
holder = get_location(argv[0]);
execve(holder, argv, NULL);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("pid");
return;
}
else
{
waitpid(pid, &status, 0);
}
}

/**
* p_prompt - prints the prompt
* @prompt: the prompt "wood" to be printed out
* Return void
*/
void p_prompt(char *prompt)
{
int i;

for (i = 0; prompt[1] != '\0'; i++)
{
our_putchar(prompt[i]);
}
}

/**
 * tkn_input - tokenizes the input string
 * @input_str: input string
 * @tkns: array of pointers to the tokens
 * @delim: delimiter
 * @max_tkns: maximum number of tokens
 * Return: number of tokens
 */
int tkn_input(char *input_str, char **tkns, const char *delim, int max_tkns)
{
char *tkn;
int tkn_count = 0;
int i;

tkn = strtok(input_str, delim);
while (tkn != NULL && tkn_count < max_tkns)
{
tkns[tkn_count] = tkn;
tkn = strtok(NULL, delim);
tkn_count++;
}
for (i = 0; i < tkn_count; i++)
{
char *current_tkn = tkns[i];
while (*current_tkn != '\0')
{
our_putchar(*current_tkn);
current_tkn++;
}
our_putchar(' ');
}
our_putchar('\n');
return (tkn_count);
}

/**
 * modecheck - checks if the program is being run in interactive mode
 * Return: void
 */
void modecheck(void)
{
	char *prompt = "Wood";
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		p_prompt(prompt);
	}
	{
		return;
	}
}

