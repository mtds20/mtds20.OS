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

// Properties from mystat file
void fileProperties(char *file)
{

    struct stat properties;

    stat(file, &properties);

    printf("\nFile Information of %s\n", file);

    printf("File Size: %lld Bytes\n", properties.st_size);
    printf("Number of Blocks Allocated: %lld\n", properties.st_blocks);
    printf("Number of Links: %d\n", properties.st_nlink);

    printf("File Permissions: ");

    if (S_ISDIR(properties.st_mode))
    {
        printf("d");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    if (properties.st_mode & S_IXOTH)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    printf("\nFile Inode: %llu\n", properties.st_ino);
    printf("\n");
}

int main(int argc, char **argv)
{
    struct dirent *dir;
    
    // opening root
    DIR *directory = opendir(".");
    
    if (argc == 2)  // if command "dir"
    {
        if (strcmp(argv[1], "-l") != 0) // if second element of argv is not "-l"
        {
            directory = opendir(argv[1]);
        }
    }
    else if (argc > 2)  // if command -l "dir" for example
    {
        if (strcmp(argv[2], "-l") != 0)  // if third element of argv is not "-l"
        {
            directory = opendir(argv[2]);
        }
    }

    dir = readdir(directory);

    while (dir != NULL)
    {
        if (argc > 2)  // if command -l "dir" for example
        {
            if (strcmp(argv[1], "-l") == 0)  // if second element of argv is "-l"
            {
                fileProperties(dir->d_name);  // calling the function to print properties of the dir
            }
        }
        else
        {
            printf("%s\n", dir->d_name);  // if there is no "-l" print only the name of the dir
        }
        
        dir = readdir(directory);  // reading directory
    }

    closedir(directory);  // closing directory

    return 0;
}