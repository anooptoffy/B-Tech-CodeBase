// Readers Writers Problem 

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define p(sem) sem_wait(&sem)
#define v(sem) sem_post(&sem)

sem_t rdblock,writeblock,mutex;

static int data;

void *reader(void *);
void *writer(void *);

int main()
{
	int i;
	pthread_t t;
	sem_init(&mutex,0,1);
	sem_init(&rdblock,0,1);
	sem_init(&writeblock,0,1);
	
	data = 80;
	
	for(i=1;i<=3;i++)
		pthread_create(&t,0,reader,(void *)i);
	for(i=1;i<=3;i++)
		pthread_create(&t,0,writer,(void *)i);
	pthread_join(t,0);
	return 0;		
}

void *reader(void *i)
{
	int id=(int)i;
	int val;
	while(1)
	{
		p(mutex);
		sem_getvalue(&rdblock,&val);
		if(val==1)
			p(writeblock);
		v(rdblock);
		v(mutex);
		printf("reader %d reades data %d \n",id,data);
		p(mutex);
		p(rdblock);
		sem_getvalue(&rdblock,&val);
		if(val==1)
			v(writeblock);
		v(mutex);
		sleep(1);
	}
	
}

void *writer(void *i)
{
	int id = (int) i;
	while(1)
	{
		p(writeblock);
		data++;
		printf("writer %d writes data %d \n",id,data);
		v(writeblock);
		sleep(1);
	}
}
