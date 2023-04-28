#include "main.h"
/**
 * get_location - writes a string to the standard output stream
 * @command: pointer to a constant character string
 * Return: count
 */
char *get_location(char *command)
{
char *path, *path_copy, *path_token, *file_path;
int command_length, directory_length;
struct stat buffer;

path = getenv("PATH");
if (path)
{
path_copy = our_strdup(path);
command_length = our_strlen(command, 1024);
path_token = strtok(path_copy, ":");
while (path_token != NULL)
{
directory_length = strlen(path_token);
file_path = malloc(command_length + directory_length + 2);
our_strcpy(file_path, path_token);
our_strcat(file_path, "/");
our_strcat(file_path, command);
our_strcat(file_path, "\0");

if (stat(file_path, &buffer) == 0)
{
free(path_copy);

return (file_path);
}
else
{
free(file_path);
path_token = strtok(NULL, ":");
}
}
free(path_copy);
if (stat(command, &buffer) == 0)
{
return (command);
}

return (NULL);
}
return (NULL);
}
