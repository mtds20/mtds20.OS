/*
    Mateus David de Souza
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define MAX_BUFFER 1500

// Function to print the current path and the filenames/directories
void search(char *dir)
{
    struct stat fProperties;

    DIR *directory;
    struct dirent *dirProperties;

    char path[MAX_BUFFER];
    
    directory = opendir(dir);  // opening directory

    printf("\nCurrent Path %s/ \n", dir);

    while ((dirProperties = readdir(directory)) != NULL)
    {
        if (strcmp(dirProperties->d_name, ".") != 0 && strcmp(dirProperties->d_name, "..") != 0)
        {
            printf("Filename: %s\n", dirProperties->d_name);
            stat(dirProperties->d_name, &fProperties);
            // if it is a directory
            if (S_ISDIR(fProperties.st_mode))
            {

                strcpy(path, dir);
                strcat(path, "/");
                strcat(path, dirProperties->d_name);
                printf("Directory: %s:", path);
                search(path);
            }
        }
        // Reading directory
        dirProperties = readdir(directory);
    }
    //Closing directory
    closedir(directory);
}

int main(int argc, char **argv)
{
    char* dir;
    char* buffer;
    
    // if "command"
    if (argc == 1)
    {
        dir = getcwd(buffer, MAX_BUFFER);  // getting current dir
        search(dir);  // calling the function with current dir
    }
    else  // if more than 1 command ex: command "directory"
    {
         search(argv[1]);  // calling the function with second element of argv
    }

    printf("Search has finished!\n");
    return 0;
}