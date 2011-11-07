#include <stdio.h>
#define max 10
int top,a[max];
top= max + 1;
main()
{
	int c,e;
	do
	{
		printf("\nMENU\n1.push\n2.pop\n3.display\n4.makenull\n5.empty\n6.EXIT\n\t");
		printf("enter the choice: \t");
		scanf("%d",&c);
		switch(c)
		{
			case 1: push(); break;
			case 2: pop();  break;
			case 3: display(); break;
			case 4: makenull(); break;
			case 5: e=empty();
				if(e==1)
					printf("\n                                               stack empty");
				else
					printf("\n                                               stack not empty");
				break;
			case 6: break;
			default: printf("\n                                                      wrong choice\n");
		}
	}while(c!=6);
}

push()
{
	int num;
	if(top==1)
	{
		printf("                                                                         stack full-needs deletion to continue\t");
		return -1;
	}
	else
	{
		printf("                   enter the element\t");
		scanf("%d",&num);
		top=top-1;
		a[top]=num;
	}
}

pop()
{
	if(empty()==1)
	{
		printf("                                                                          stack empty");
		return -1;
	}
	else
		top=top+1;
	printf("                                                                                   one element poped");
}

empty()
{
	if(top>max)
		return 1;
	else
		return 0;
}

makenull()
{
	top=max+1;
}
display()
{
	int i;
	printf("\t\t\t\t\t <------------top \n");
	for(i=top;i<=max;i++)
	{
		printf("\t    %d\n",a[i]);
	}
	printf("\t\t\t\t\t <-----------max \n");
}

	
