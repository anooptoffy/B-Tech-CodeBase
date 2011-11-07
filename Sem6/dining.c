// Dining Philosopher's Problem

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define p(sem) sem_wait(&sem)
#define v(sem) sem_post(&sem)
#define num 5

sem_t semid[5],mutex;

void read()
{
	int i;
	for(i=0;i<5;i++)
		sem_init(&semid[i],0,1);
	sem_init(&mutex,0,1);
	
}

void getfork(int i)
{
	int j;
	j=(i+1)%num;
	p(semid[i]);
	p(semid[j]);
}

void putfork(int i)
{
	int j;
	j=(i+1)%num;
	v(semid[i]);
	v(semid[j]);
	
}

void eat(int i)
{
	printf("philosopher %d start eating \n",i);
	sleep(5);
	printf("philosopher %d stops eating \n",i);
}

void *philosopher(void *p)
{
	int i=(int) p;
	while(1)
	{
		getfork(i);
		eat(i);
		putfork(i);
		sleep(2);
	}
}

int main()
{
	int i;
	pthread_t t;
	read();
	for(i=0;i<5;i++)
	{
		pthread_create(&t,0,philosopher,(void *)i);
	}
	pthread_join(t,0);
	return 0;	
	
}
