#ifndef MAIN_H
#define MAIN_H
#define TMAX 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void execmd(char **argv);
char *get_location(char *command);
char *ourstr_tok(char *str, const char *delim);
extern char **environ;

/*our builtin execution functions*/
int our_exit(char **args);
int our_cd(char **args);
int our_env(char **args);

/*our builtin objects*/
typedef struct builtin
{
char *name;
int (*func)(char **args);
} builtin_t;

int execute_builtin(char **args);
int builtinss(char **argv);

/*additionalfxns.c fucntions - string manipulation functions*/
int our_putchar(char c);
char our_strcpy(char *dest, const char *src);
size_t our_strlen(char *strn, size_t maxl);
int our_strcmp(const char *str1, const char *str2);
char our_strcat(char *destination, const char *source);
int our_puts(const char *__s);
char *our_strdup(const char *str);
void our_putstr(char *str);
char **split_input(char *input, const char *delim, int *num_tokens);
#endif
