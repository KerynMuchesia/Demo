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

/*additionalfxns.c fucntions - string manipulation functions*/
int our_putchar(char c);
char our_strcpy(char *to_str, char *from_str);
int tokenize_input(char *input_str, char **tokens,
const char *delim, int max_tokens);
size_t our_strlen(const char *strn, size_t maxl);
int our_strcmp(char *string2, char *string1);
char *our_strcat(char *to_str, char *from_str);

#endif