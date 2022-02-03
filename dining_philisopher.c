#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
#define HUNGRY 1
#define EATING 2
#define THINKING 3
#define LEFT (phnum + 4) % N
#define RIGHT (phnum +1) % N

int states[N];
int phil[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];


void test(int phnum){
    if(states[LEFT] != EATING && states[RIGHT] != EATING && states[phnum] == HUNGRY){
        states[phnum] = EATING;
        printf("Philosopher %d is taking the fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1);
        printf("Philosopher %d is eating\n", phnum + 1);

        sem_post(&S[phnum]);

    }
}
void take_fork(int phnum){
    sem_wait(&mutex);

    states[phnum] = HUNGRY;
    printf("Philosopher %d is hungry\n", phnum + 1);
    sleep(1);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&S[phnum]);
}

void put_fork(int phnum){
    sem_wait(&mutex);
    states[phnum] = THINKING;
    printf("Philosopher %d is putting the fork %d and %d down\n", phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is thinking\n", phnum + 1);

    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void * philosopher(void *num){
    while(1){
        int *i = num;
        take_fork(*i);
        sleep(1);
        put_fork(*i);
        sleep(1);
    }
}

int main(void){

    pthread_t thread_ids[N];
    sem_init(&mutex, 0, 1);
    for(int i = 0; i < N; i++){
        sem_init(&S[i], 0, 0);
    }

    for(int i = 0; i < N; i++){
        pthread_create(&thread_ids, NULL, philosopher, &phil[i]);
        printf("philosopher %d is thinking\n", i+1 );
    }

    for(int i = 0; i < N; i++){
        pthread_join(thread_ids[i], NULL);
    }
}