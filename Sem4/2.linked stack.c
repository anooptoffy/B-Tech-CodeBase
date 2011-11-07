/*Implementation of stack using linked list*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct node
{
	int info;
	struct node *link;
}*start=NULL, *new,*temp,*p;
typedef struct node N;


int main()
{
	int ch,a;
	do
	{
	 printf("\t\t\tLinked stack");
	 printf("\n 1.Push");
	 printf("\n 2.Pop");
	 printf("\n 3.Display");
	 printf("\n 4.Exit");
	 printf("\n Enter your choice : ");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
		push();
		break;
		case 2:
		pop();
		break;
		case 3:
		display();
		break;
		case 4:
		exit(0);
		default:
		printf("\nInvalid choice");
		break;
	 }
}while(ch<=3);
return 0;
}

void push()
{
	new=(N*)malloc(sizeof(N));
	printf("\nEnter the item : ");
	scanf("%d",&new->info);
	new->link=NULL;
	if(start==NULL)
		start=new;
	else
	{
	 p=start;
 	 while(p->link!=NULL)
	 p=p->link;
	 p->link=new;
	}
}


void pop()
{
	if(start==NULL)
		printf("\nStack is empty");
	else if(start->link==NULL)
	{
	 printf("\nThe deleted element is : %d",start->info);
	 free(start);
	 start=NULL;
	}

	else
	{
	 p=start;
	 while(p->link!=NULL)
	 {
		temp=p;
		p=p->link;
	 }
	 printf("\nDeleted element is : %d\n", p->info);
	 temp->link=NULL;
	 free(p);
	}
}

void display()
{
	if(start==NULL)
	printf("\nStack is empty");
	else
	{
		printf("\nThe elements are : ");
		p=start;
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
		}
		printf("\n");
	}
}
