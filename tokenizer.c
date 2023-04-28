#include "main.h"

/**
 * split_input - tokenizes a string input into an array of strings
 * @input: string input to tokenize
 * @delim: delimiter used to split the input into tokens
 * @num_tokens: pointer to an integer to store the number of tokens
 *
 * Return: array of strings containing the tokens
 */
char **split_input(char *input, const char *delim, int *num_tokens)
{
char *token;
int i;
char *input_copy = strdup(input);
char **argv;
*num_tokens = 0;

/* calculating the total number of tokens */
token = strtok(input, delim);
while (token != NULL)
{
(*num_tokens)++;
token = strtok(NULL, delim);
}
(*num_tokens)++;

/* Allocating space to hold the array of strings */
argv = malloc(sizeof(char *) * (*num_tokens));
if (argv == NULL)
{
perror("tsh: memory allocation error");
return (NULL);
}

/* storing each token in the argv array */
token = strtok(input_copy, delim);

for (i = 0; token != NULL; i++)
{
argv[i] = strdup(token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
free(input_copy);

return (argv);
}
