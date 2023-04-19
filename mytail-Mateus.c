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
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int lines;
    int readLines;
    int count = 0;

    char file[280];
    char buffer[280];

    int ptr = open(file, O_RDONLY);
    int offset = 0;

    bool isStillBeingRead = true;

    lines = atoi(argv[1]);

    strcpy(file, argv[2]);
    
    // Counting lines
    for (int j = 0; j < strlen(buffer); j++)
        {
            if (buffer[j] == '\n')
            {
                count++;
            }
        }
    
    // While the file is being read
    while (isStillBeingRead)
    {
        readLines = lseek(ptr, offset, SEEK_END);
        readLines = read(ptr, buffer, 280);
        
        if (count == lines)
        {
            printf("Last %d line(s) of %s:%s\n\n", lines, file, buffer);
            isStillBeingRead = false;
        }

        offset--;
    }

    close(ptr);

    return 0;
}