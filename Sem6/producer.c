// Producer Consumer problem . 

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define p(sem) sem_wait(&sem)
#define v(sem) sem_post(&sem)

sem_t semfull,semempty;
int buffer[10];
void *producer(void *p)
{
	int rear=0;
	while(1)
	{
		p(semempty);
		buffer[rear]=100+rear;
		printf("producer produced %d\n",buffer[rear]);
		rear= (rear+1)%10;
		v(semfull);
		sleep(1);
	}
}
void *consumer(void *p)
{
	int front=0;
	while(1)
	{
		p(semfull);
		printf("consumer consumed %d \n",buffer[front]);
		front=(front+1)%10;
		v(semempty);
		sleep(2);
	}
	
}

main()
{
	pthread_t t;
	sem_init(&semfull,0,0);
	sem_init(&semempty,0,10);
	pthread_create(&t,0,producer,(void *)0);
	pthread_create(&t,0,consumer,(void *)0);
	pthread_join(t,0);
}
