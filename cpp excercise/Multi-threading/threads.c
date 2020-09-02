#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

#define NUM_RANGE 1000000
#define PRODUCERS_NUM 3
#define CONSUMERS_NUM 4
#define BOX_SIZE 6
int g_full = 0;
int g_box[BOX_SIZE];
int g_count_pro = 120;
int g_count_con = 120;
pthread_mutex_t lock_producer = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_consumer = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_pro = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_con = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t wait_for_fill = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_for_empty = PTHREAD_COND_INITIALIZER;
sem_t sem_pro, sem_con;



void* producer(void* args)
{
    while (g_count_pro > 0)
    {
        sem_wait(&sem_pro);
        sem_getvalue(&sem_pro, &g_count_pro);
        pthread_mutex_lock(&lock_producer);
        while (g_full >= BOX_SIZE) {
            pthread_cond_wait(&wait_for_empty, &mutex_pro);
        }

        g_box[g_full++] = rand() % NUM_RANGE;
        printf("produce %d\n", g_box[g_full-1]);
        pthread_cond_signal(&wait_for_fill);
        pthread_mutex_unlock(&lock_producer);

    }
}


void* consumer(void* args)
{
    while (g_count_con > 0)
    {
        sem_wait(&sem_con);
        sem_getvalue(&sem_con, &g_count_con);
        pthread_mutex_lock(&lock_consumer);
        while (g_full == 0)
        {
            pthread_cond_wait(&wait_for_fill, &mutex_con);
        }
        printf("consume %d \n", g_box[--g_full]);
        g_box[g_full] = -1;
        pthread_cond_signal(&wait_for_empty);
        pthread_mutex_unlock(&lock_consumer);
    }
}

int main()
{
    sem_init(&sem_con, 0, 120);
    sem_init(&sem_pro, 0, 120);
    pthread_t pro_arr[PRODUCERS_NUM];
    pthread_t con_arr[CONSUMERS_NUM];
    for (int i=0;i<sizeof(pro_arr)/ sizeof(pthread_t);i++)
    {
        pthread_create(&pro_arr[i], NULL, producer, NULL);
    }

    for (int i=0;i<sizeof(con_arr)/ sizeof(pthread_t);i++)
    {
        pthread_create(&con_arr[i], NULL, consumer, NULL);
    }

    for (int i=0;i<sizeof(pro_arr)/ sizeof(pthread_t);i++)
    {
        pthread_join(pro_arr[i], NULL);
    }
    for (int i=0;i<sizeof(con_arr)/ sizeof(pthread_t);i++)
    {
        pthread_join(con_arr[i], NULL);
    }
    sem_destroy(&sem_con);
    sem_destroy(&sem_pro);
    return 0;
}