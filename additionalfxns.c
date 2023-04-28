#include "main.h"

/**
 * our_putchar - takes a single character c as input and returns integer value
 * @c: the character to be printed
 * Return: -1 on error
 */

int our_putchar(char c)
{
write(STDOUT_FILENO, &c, 1);
return (0);
}
/**
 * our_strcpy - Copies a string from source to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char our_strcpy(char *dest, const char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}

dest[i] = '\0';
return (*dest);
}
/**
 * our_strlen - returns the length of a string
 * @strn: the string
 * @maxl: maximum length of the string
 * Return: string length
 */
size_t our_strlen(char *strn, size_t maxl)
{
size_t i = 0;

while (strn[i] != '\0' && i < maxl)
{
i++;
}
return (i);
}

/**
 * our_strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if the strings are equal, -1 if s1 < s2, 1 if s1 > s2
 */
int our_strcmp(const char *str1, const char *str2)
{
int i = 0;

while (str1[i] == str2[i])
{
if (str1[i] == '\0')
{
return (0);
}
i++;
}

return (str1[i] - str2[i]);
}

/**
 * our_strcat - concatenates two strings
 * @destination: the destination string
 * @source: the source string
 *
 * Return: pointer to the destination string
 */
char our_strcat(char *destination, const char *source)
{
while (*destination != '\0')
{
destination++;
}
while (*source != '\0')
{
*destination = *source;
destination++;
source++;
}
*destination = '\0';
return (0);
}
