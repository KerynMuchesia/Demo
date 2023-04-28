#include "main.h"
/**
 * print_prompt - Function to print the prompt
 * @prompt: A pointer to the character string containing the prompt
 */

void print_prompt(char *prompt)
{
int i;
for (i = 0; prompt[i] != '\0'; i++)
{
our_putchar(prompt[i]);
}
}
