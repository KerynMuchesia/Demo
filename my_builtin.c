#include "main.h"
/**
 * our_exit - exits our shell
 * Return: 0
*/


int our_exit(char **args)
{
    (void) args;
    puts("*EXITING*\n");
    exit(EXIT_SUCCESS);
}


/**
 * our_cd - changes the current working directory
 * @args: refers to the array of pointers to the arguments
 * Return: 1
*/

int our_cd(char **args)
/*if path is NULL*/
{
    if (args[1] == NULL)
    {
        chdir(getenv("HOME"));
    }
    else
    {
        if (chdir(args[1]) != 0)
    {
        puts(args[TMAX]);
        puts(": ");
        puts(args[0]);
        puts(": ");
        puts(args[1]);
    /*if chdir() fails print error message*/
        puts(": No such file or directory\n");
    }
    }
    return (1);
}
/**
 * our_env - command used to print a list of environment variables
 * @args: an array of pointers to the arguments
 * Return: 1
*/

int our_env(char **args)
/* An array of environment variables*/
{
extern char **environ;
int i;
(void) args;
for (i = 0; environ[i] != NULL; i++)
{
    char *env_var = environ[i];
/*printing each  character in the environment variable*/
    while (*env_var)
    {
        puts(env_var);
        env_var++;
    }
/*printing a new line after each environment variable*/ 
    puts("\n");
    }
    return (1);
}