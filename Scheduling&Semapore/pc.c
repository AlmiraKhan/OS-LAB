#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5
#define BufferSize 5

sem_t empty; 
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno)
{
    int item;

    item = rand();
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[in] = item;
    printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in], in);
    in = (in + 1) % BufferSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}
void *consumer(void *cno)
{

    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    int item = buffer[out];
    printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, out);
    out = (out + 1) % BufferSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main()
{

    pthread_t pro[5], con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BufferSize);
    sem_init(&full, 0, 0);

    int a[5] = {1, 2, 3, 4, 5};
    

    while (1)
    {
        printf("Enter Option \n 1.Producer \n 2.Consumer \n");

        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            
            pthread_create(&pro[0], NULL, (void *)producer, (void *)&a[0]);
            pthread_join(pro[0], NULL);
            // pthread_join(con[0], NULL);
            break;
        case 2:

            pthread_create(&con[0], NULL, (void *)consumer, (void *)&a[0]);
            pthread_join(pro[0], NULL);
            pthread_join(con[0], NULL);
            break;
        }
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}