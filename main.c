#include "main.h"

void execmd(char **argv);

int main(void)
{
char *prompt = "(Wood) $ ";
char *lineptr = NULL, *lineptr_copy = NULL;
size_t m = 0;
ssize_t read_chars;
const char *delim = " \n";
int num_tokens = 0;
char *token;
int i;
char **argv;

/*creating a loop for the prompt*/
while (1)
{
/*printing the prompt character by character*/
for (i = 0; prompt[i] != '\0'; i++)
{
our_putchar(prompt[i]);
}
read_chars = getline(&lineptr, &m, stdin);
/*checking if the getline function failed or reached EOF or CTRL + D*/
if (read_chars == -1)
{
for (i = 0; "Exiting....\n"[i] != '\0'; i++)
{
our_putchar("Exiting....\n"[i]);
}
break;
}
/*checking if the user input is "Exiting...."*/
if (our_strcmp(lineptr, "Exiting....\n") == 0)
{
break;
}
/*allocating space for a copy of the lineptr */
lineptr_copy = malloc(sizeof(char) * (read_chars + 1));
if (lineptr_copy == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}
/*copying the lineptr to lineptr_copy*/
our_strcpy(lineptr_copy, lineptr);

/** splitting the string (lineptr) into an array of words **/
/*calculating the total number of tokens*/
token = strtok(lineptr, delim);

while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;
/*Allocating space to hold the array of strings*/
argv = malloc(sizeof(char *) * num_tokens);
if (argv == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}
/*storing each token in the argv array*/
token = strtok(lineptr_copy, delim);

for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * our_strlen(token, 1024) + 1);
our_strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
/*execution command*/
execmd(argv);
}
/*freeing up the allocated memory*/
for (i = 0; i < num_tokens; i++)
{
free(argv[i]);
}
free(lineptr_copy);
free(lineptr);
return (0);
}
