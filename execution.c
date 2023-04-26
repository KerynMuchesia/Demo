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
int i;
char *holder = NULL, *holder2[1010];

/* checking if command is a built-in */
if (our_strcmp(argv[0], "exit") == 0)
{
/* check if an argument was provided */
if (argv[1] != NULL)
{
/* convert argument to integer and exit with that status */
exit(atoi(argv[1]));
}
else
{
/* exit with status 0 */
exit(0);
}
}
else if (our_strcmp(argv[0], "env") == 0)
{
/* print current environment */
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
}
else
{
holder2[0] = get_location(argv[0]);
printf("add: %s", holder);

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
/*Output the tokens using putchar*/
for (i = 0; i < tkn_count; i++)
{
char *current_tkn = tkns[i];
while (*current_tkn != '\0')
{
our_putchar(*current_tkn);
current_tkn++;
}
our_putchar(' '); /*prints the space between tokens*/
}
our_putchar('\n'); /*print a newline character at the end*/

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