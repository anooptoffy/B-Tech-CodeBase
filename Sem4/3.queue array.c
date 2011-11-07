/* Implentation of queue using arrays */

#include <stdio.h>
#define SIZE 10

int arr[SIZE], front = -1, rear = -1, i ;
void enqueue() ;
void dequeue() ;
void display() ;

int main()
{
	int ch;
	do
	{
		printf("Menu\n1.ENQUEUE \n2.DEQUEUE \n3.Display \n4.Exit\n") ;
		printf("Enter your choice : ") ;
		scanf("%d", &ch) ;
		switch(ch)
		{
			case 1 :
			enqueue() ;
			break ;
			case 2 :
			dequeue() ;
			break ;
			case 3 :
			display() ;
			break ;
			case 4 :
			break ;
			default :
			printf("Invalid option\n") ;
		}
	} while(ch != 4) ;
return 0;
}

void enqueue()
{
	if(rear == SIZE - 1)
	{
		printf("Queue is full (overflow)\n") ;
		return ;
	}
	rear++ ;
	printf("Enter the element to ENQUEUE : ") ;
	scanf("%d", &arr[rear]) ;
	if(front == -1)
	front++ ;
}

void dequeue()
{
	if(front == -1)
	{
		printf("Queue is empty (underflow)\n");
		return ;
	}
	printf("The DEQUEUE element is : %d\n", arr[front]) ;
	if(front == rear)
		front = rear = -1 ;
	else
		front++ ;
}

void display()
{
	if(front == -1)
	{
		printf("Queue is empty (underflow)\n") ;
		return ;
	}
	printf("The elements in queue are : ") ;
	for(i = front ; i <= rear ; i++)
		printf("%d ", arr[i]) ;
}
