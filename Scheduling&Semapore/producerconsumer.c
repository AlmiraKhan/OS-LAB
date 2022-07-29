#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define BufferSize 5

sem_t empty;
sem_t full;
int in = -1;
int x, y,z;
int buffer[BufferSize];
sem_t mutex;

void *producer()
{
    int item;

    item = rand();
    sem_wait(&empty);
    sem_wait(&mutex);
    
    in = (in + 1) % BufferSize;
    buffer[in] = item;
    printf("Producer : Insert Item %d at %d\n", buffer[in], in);
    
    
    sem_post(&mutex);
    sem_post(&full);
}
void *consumer()
{

    sem_wait(&full);
    sem_wait(&mutex);
    
    int item = buffer[in];
    printf("Consumer : Remove Item %d from %d\n", item, in);
    in = (in - 1) % BufferSize;
    sem_post(&mutex);
    sem_post(&empty);
}

int main()
{

    pthread_t pro[5], con[5];
    sem_init(&empty, 0, BufferSize);    
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    while (1)
    {
        printf("Enter Option \n 1.Producer \n 2.Consumer \n");

        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            sem_getvalue(&empty, &x);
            sem_getvalue(&mutex, &y);
           
            if (x != 0 && y == 1)
            {
                pthread_create(&pro[0], NULL, (void *)producer,NULL);
                pthread_join(pro[0], NULL);
            }
            else
            {
                printf("Buffer is Full!");
            }

            break;
        case 2:

            sem_getvalue(&full, &z);
            sem_getvalue(&mutex, &y);
            if (z != 0 && y == 1)
            {
                pthread_create(&con[0], NULL, (void *)consumer,NULL);
                pthread_join(con[0], NULL);
            }
            else
            {
                printf("Buffer is Empty!");
            }


            break;
        }
    }
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}