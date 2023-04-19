/*
    Mateus David de Souza
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// Function to display file properties
void fileProperties(struct stat properties)
{
    printf("\nFile Size: %lld Bytes\n", properties.st_size);
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
    struct stat properties;

    printf("\nFile Information of %s", argv[1]);

    if (stat(argv[1], &properties) == 0)
    {
        fileProperties(properties);  // calling the function
    }
    else
    {
        printf("No success displaying file properties.");
        exit(-1);
    }

    return 0;
}