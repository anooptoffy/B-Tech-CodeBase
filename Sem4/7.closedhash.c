#include <stdio.h>

int ar[10],i,g=0,key;

void insert();
void search();
void delete();
void display();

main()
{
int ch;
for(i=0;i<10;i++) //to initialise every element as '-1'
ar[i]=-1;
do
{
p1:
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
goto p1;
break;
}
}while(ch!=5);
}



void insert()
{
	int item,f=0; 
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&item);
	key=(item%10)-1;
	if(ar[key]==-1)
	{
		ar[key]=item;
		f=1;
	}
	else 
	{
		if(key<9)
		{
			for(i=key+1;i<10;i++)
			{
				if(ar[i]==-1)
				{
					f=1;
					ar[i]=item;
					break;
				}
			}
		}
		if(f==0)
		{
			for(i=0;i<key;i++)
			{
				if(ar[i]==-1)
				{
					f=1;
					ar[i]=item;
					break;
				}
			}
		}
	}

	if(f==0)
	printf("\nHashTable is Full\n");

}

void display()
{
for(i=0;i<10;i++)
if(ar[i]!=-1)
{
g=1;
break;
}
if(g==1)
{
for(i=0;i<10;i++)
{
if(ar[i]==-1)
printf("\n---");
else
printf("\n%d",ar[i]);
}
}
else
printf("\nThe HashTable is empty !!!");
printf("\n");
}

void search()
{
int item,f=0;
g=0;
printf("\nEnter the element to be searched :: ");
scanf("%d",&item);
key=(item%10)-1;
for(i=0;i<10;i++)
{
if(ar[i]!=-1)
{ 
g=1;
break;
}
}
if(g==1)
{
if(ar[key]==item)
{
f=1;
}
else
{
if(key<9)
{
for(i=key+1;i<10;i++)
{
if(ar[i]==item)
{ 
f=1;
key=i;
break;
}
}
}
if(f==0)
{
for(i=0;i<key;i++)
{
if(ar[i]==item)
{
f=1;
key=i;
break;
}

}
}

}

if(f==1)
printf("\nThe item searched was found in the hash table at position %d !",key+1);
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
search();
if(g!=0)
{
if(key!=-1)
{
printf("\nThe element deleted is %d ",ar[key]);
ar[key]=-1;
}
} 
}
