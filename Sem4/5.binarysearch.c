#include <stdio.h>
#define max 5
int nsearch(int b[max],int n);
void rsearch(int c[max],int m,int n,int p);



main()

{
	int a[max],i,c,l,h,s,j,temp;
	printf("enter the elements\t");
	for(i=0;i<max;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<max;i++)
	{
		for(j=i+1;j<max;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	printf("\n\tSORTED ARRAY");
	for(i=0;i<max;i++)
	printf("\n\t%d",a[i]);
	do
	{	printf("\n\t\tBINARY SEARCH IMPLIMENTATION\n");
		printf("\nMENU\n1.NON RECRUSIVE SEARCHING\n2.RECRUSIVE SEARCHING\n3.EXIT\n");
		printf("enter the choice\t");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				nsearch(a,max);
				break;
			case 2:
				printf("enter the item to be searched\t");
				scanf("%d",&s);
				l=0;
				h=max-1;
				rsearch(a,l,h,s);
				break;
			case 3:
				break;
				
			default:
				printf("wrong choice");
		}
	}while(c!=3);
}

int nsearch(int b[max],int n)
{
	int a,low,high,mid;
	printf("enter the item to be searched\n");
	scanf("%d",&a);
	low=0;
	high=max-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(a==b[mid])
		{	printf("element found");
			return -1;
		}
		else 
			if(a<b[mid])
			high=mid-1;
		else
			if(a>b[mid])
			low=mid+1;
	}
	printf("not found");
	return -1;
}	

void rsearch(int c[max],int m,int n,int p)
{
	int mid;
	if(m>n)
	{
		printf("not found");
	}
	else
	{
		mid=(m+n)/2;
		if(p==c[mid])
			printf("element found");
		else 
			if(p<c[mid])
			rsearch(c,m,mid-1,p);
		else
			rsearch(c,mid+1,n,p);
	}
}
		
