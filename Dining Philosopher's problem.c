#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];

void *philosopher(void *num)
{
    int id = *(int *)num;

    printf("Philosopher %d is THINKING\n", id);
    sleep(1);

    if (id == N - 1)
    {
        sem_wait(&chopstick[(id + 1) % N]);
        printf("Philosopher %d picked RIGHT chopstick %d\n",
               id, (id + 1) % N);

        sem_wait(&chopstick[id]);
        printf("Philosopher %d picked LEFT chopstick %d\n",
               id, id);
    }
    else
    {
        sem_wait(&chopstick[id]);
        printf("Philosopher %d picked LEFT chopstick %d\n",
               id, id);

        sem_wait(&chopstick[(id + 1) % N]);
        printf("Philosopher %d picked RIGHT chopstick %d\n",
               id, (id + 1) % N);
    }

    printf("Philosopher %d is EATING\n", id);
    sleep(2);

    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % N]);

    printf("Philosopher %d finished EATING\n", id);

    return NULL;
}

int main()
{
    pthread_t ph[N];
    int id[N];

    for (int i = 0; i < N; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }

    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(ph[i], NULL);
    }

    return 0;
}
