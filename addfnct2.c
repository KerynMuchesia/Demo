#include "main.h"
/**
 * our_puts - writes a string to the standard output stream
 * @__s: pointer to a constant character string
 * Return: count
 */

int our_puts(const char *__s)
{
int count = 0;
while (*__s != '\0')
{
count += putchar(*__s++);
}
count += putchar('\n');
return (count);
}
/**
 * our_strdup - a user-defined function that duplicates a given string
 * @str: string to be duplicated
 * Return: new_str
 */

char *our_strdup(const char *str)
{
size_t len = strlen(str) + 1;
char *new_str = malloc(len);
if (new_str != NULL)
{
memcpy(new_str, str, len);
}
return (new_str);
}
