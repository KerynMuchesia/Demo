#include "main.h"

char *get_location(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length;
    struct stat buffer;

    path = getenv("PATH");

    if (path)
    {
        /*Duplicating the path string while keeping in mind to free up memory as strdup allocates memory that requires freeing*/
        path_copy = strdup(path);

        /*Fetch the length of the command that was passed*/
        command_length = our_strlen(command);

        /*Breaking down the path variables and get all the directories present*/
        path_token = strtok(path_copy, ":");

        while(path_token != NULL){
            /*getting the lengthof the directory*/
            directory_length = strlen(path_token);
            /*allocating memory to store both the command name and the directory name*/
            file_path = malloc(command_length + directory_length + 2);
            /*NB the 2 was added for the slash and the null character*/
            /*Let's duplicate the directory path and merge it with the command to create the pathway for the command*/
            our_strcpy(file_path, path_token);
            our_strcat(file_path, "/");
            our_strcat(file_path, command);
            our_strcat(file_path, "\0");

            /*testing if the path actually exists and return it if it does, try the next directory*/
            if (stat(file_path, &buffer) == 0)
            {
            /*returning the value 0 means succes implying that the file_lane is valid*/
            /*freeing up the allocated memory before returning my file_lane*/
            free(path_copy);

            return (file_path);
            }
            else
            {
            /*free up the file_path memory so we can check for another path*/
            free(file_path);
            path_token = strtok(NULL, ":");
        }
        
        }
        /*incase we don't get any file_path that exists for the command, we return NULL but still need to free up memory for path_copy*/
        free(path_copy);

        /*before exiting without luck, we check if the command itself is a file_path tha exists*/
        if (stat(command, &buffer) == 0)
        {
            return (command);
        }

        return (NULL);

    }

    return (NULL);
}