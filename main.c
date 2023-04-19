/*
    Mateus David de Souza (U93384434)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "readerwriter.c"

void readerProcess(rwLock *lock);
void writerProcess(rwLock *lock);

void initLock(rwLock *rwLock)
{
    rwLock->readCount = 0;
    sem_init(&rwLock->mutex, 0, 1);
    sem_init(&rwLock->writer, 0, 1);
    sem_init(&rwLock->entryMutex, 0, 1);
}

rwLock lock;

void *readerThr(void *readerNum)
{
    readerProcess(&lock);
    return NULL;
}

void *writerThr(void *writerNum)
{
    writerProcess(&lock);
    return NULL;
}

int main()
{
    pthread_t threads[150];

    char word[150];
    FILE *ptr = fopen("scenarios.txt", "r");
    initLock(&lock);

    if (ptr == NULL)
    {
        printf("No existing file.");
        exit(1);
    }

    while (fgets(word, sizeof(word), ptr))
    {
        printf("\nScenario Starts: %s\n", word);

        for (int i = 0; i < strlen(word); i++)
        {

            if (word[i] == 'r')
            {
                pthread_create(&threads[i], NULL, readerThr, NULL);
            }

            else
            {
                pthread_create(&threads[i], NULL, writerThr, NULL);
            }
        }

        for (int i = 0; i < strlen(word); i++)
        {

            pthread_join(threads[i], NULL);
        }
    }

    fclose(ptr);

    return 0;
}