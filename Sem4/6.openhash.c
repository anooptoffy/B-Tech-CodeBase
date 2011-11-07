#include<stdio.h>
#include<malloc.h>

void insert();
void display();
void search();
void delete();

struct node
{
int info;
int *next;
}*start[10];

typedef struct node N;
int i,g,key;

main()
{


int ch;
do
{
printf("\n\t\t\t\t\tMENU \n1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
break;
case 2: search();
break;
case 3: delete();
break;
case 4: display();
break;
case 5:
break;
default:printf("\nInvalid choice entry!!!\n");
break;
}
}while(ch!=5);


}



void insert()
{
N *p,*loc;
int item;
p=(N*)malloc(sizeof(N));
loc=(N*)malloc(sizeof(N));
printf("\nEnter the item to be inserted : ");
scanf("%d",&item);
key=item%10;
loc=start[key];
p->info=item;
p->next=NULL;

if(start[key]==NULL)
start[key]=p;
else
{
while(loc->next!=NULL)
{
loc=loc->next;
}
loc->next=p;
}

}


void display()
{

N *p;
p=(N*)malloc(sizeof(N));
for(key=0;key<10;key++)
{
if(start[key]==NULL) 
printf("\n----");
else 
{
p=start[key];
while(p!=NULL)
{
printf("%d\t",p->info);
p=p->next;
}
}
printf("\n");
} 
}


void search()
{
	int item,f=0;g=0;
	N *p;
	p=(N*)malloc(sizeof(N));
	printf("\nEnter the element to be searched :: ");
	scanf("%d",&item);
	key=(item%10);
	for(i=0;i<10;i++)
	{
		if(start[i]!=NULL)
		{
			g=1;
			break;
		}
	}
	if(g==1)
	{
		if(start[key]!=NULL)
		{
			if(start[key]->info==item)
			{
				f=1;
			}
			else
			{
				p=start[key];
				while(p->next!=NULL)
				{
					p=p->next;
					if(p->info==item)
					{
//						printf("%d",p->info);
						f=1;
						break;
					}

				}
			}
		}
		if(f==1)
			printf("\nThe item searched was found !");
		else
		{
			key=-1;
			printf("\nThe item searched was not found in the hash table");
		}
	}		
	else
		printf("\nHashTable is empty!!\n");
}



void delete()
{


int item,f=0;g=0;
N *p,*t;
p=(N*)malloc(sizeof(N));
t=(N*)malloc(sizeof(N));
printf("\nEnter the element to be deleted :: ");
scanf("%d",&item);
key=(item%10);
for(i=0;i<10;i++)
{
if(start[i]!=NULL)
{
g=1;
break;
}
}
if(g==1)
{
if(start[key]!=NULL)
{
if(start[key]->info==item)
{
p=start[key];
t=p->next;
start[key]=t;
free(p);
f=1;
if(start[key]==NULL)
goto q;
}
p=start[key];
while(p->next!=NULL)
{
t=p;
p=p->next;
if(p->info==item)
{
t->next=p->next;
free(p);
p=t; 
f=1;
}

}
}
q:
if(f==1)
printf("\nThe item searched was deleted !");
else
{
key=-1;
printf("\nThe item searched was not found in the hash table");
}

}
else
printf("\nHashtable is empty!!!!\n");

}
