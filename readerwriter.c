/*
    Mateus David de Souza (U93384434)

*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct rwLock
{
    sem_t mutex;
    sem_t writer;
    sem_t entryMutex;
    int readCount;
} rwLock;

void readerProcess(rwLock *lock)
{
    sem_wait(&lock->entryMutex);
    sem_wait(&lock->mutex);
    lock->readCount++;
    printf("Create reader\n");

    if (lock->readCount == 1)
    {
        sem_wait(&lock->writer);
    }

    sem_post(&lock->mutex);
    sem_post(&lock->entryMutex);

    printf("Reader's is in... reading\n");

    sleep(1);

    sem_wait(&lock->mutex);
    printf("Finished reading\n");
    lock->readCount--;
    sem_post(&lock->mutex);

    if (lock->readCount == 0)
    {
        sem_post(&lock->writer);
    }
}

void writerProcess(rwLock *lock)
{
    sem_wait(&lock->entryMutex);
    sem_wait(&lock->writer);
    printf("Create writer\n");

    printf("Writer's in... writing\n");

    sleep(1);

    sem_post(&lock->entryMutex);
    sem_post(&lock->writer);
    printf("Finished writing\n");
}