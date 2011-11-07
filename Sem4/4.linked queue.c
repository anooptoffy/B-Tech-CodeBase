/*Implementation of queue operations using linked list*/

#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10

void enqueue();
void dequeue();
void display();

struct node
{
	int info;
	struct node *link;
}*new,*temp,*p,*front=NULL,*rear=NULL;
typedef struct node N;


int main()
{
	int ch;
	do
	{	 printf("\n\t\t\tLinked queue");
 	 printf("\n 1.Enqueue");
	 printf("\n 2.Dequeue");
	 printf("\n 3.Display");
	 printf("\n 4.Exit");
	 printf("\n Enter your choice : ");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
		enqueue();
		break;
		case 2:
		dequeue();
		break;
		case 3:
		display();
		break;
	 }
	}while(ch<=3); 
return 0;
} 

void enqueue() 
{ 
	int item; 
	new=(N*)malloc(sizeof(N)); 
	printf("\nEnter the item : "); 
	scanf("%d",&item); 
	new->info=item;
	new->link=NULL;
	if(front==NULL)
		front=new;
	else
		rear->link=new;
	rear=new;
}

void dequeue()
{
	if(front==NULL)
		printf("\nQueue is empty");
	else
	{
		p=front;
		printf("\nDeleted element is : %d",p->info);
		front=front->link;
		free(p);
	}
}

void display()
{
	if(front==NULL)
		printf("\nQueue is empty");
	else
	{
		printf("\nThe elements are : ");
		temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->link;
		}
	}
}
