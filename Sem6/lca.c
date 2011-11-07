// Lowest common ancestor

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int lca_ind,check[20]={0},tree[20];
pthread_mutex_t mutex;

void *lca(void *ind)
{
	int p=(int)ind;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(check[p]==1)
		{
			lca_ind = p;
			pthread_mutex_unlock(&mutex);
			return ;
		}
		check[p]=1;
		p/=2;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t t1,t2;
	int i,id1,id2,nos;
	printf(" Enter the no:of elements in the binary tree\n");
	scanf("%d",&nos);
	printf("enter the nodes of the binary tree\n");
	for(i=1;i<=nos;i++)
		scanf("%d",&tree[i]);
	printf("enter the nodes for which LCA Has to be find out \n");
	scanf("%d%d",&id1,&id2);
	for(i=1;i<=nos;i++)
	{
		if(tree[i]==id1)
			id1=i;
		if(tree[i]==id2)
			id2=i;
	}
	pthread_create(&t1,0,lca,(void *)id1);
	pthread_create(&t2,0,lca,(void *)id2);
	pthread_join(t1,0);
	pthread_join(t2,0);
	printf("lca is %d \n",tree[lca_ind]);
	
	return 0;
}
