#include <stdio.h>
int f=1,e=0,q[10];
void heap(int b[],int m);
void heapsort(int s[],int l);
main()
{
	int a[10],i,n;
	printf("enter the number of elements\t");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	heap(a,n);
	printf("\n the sorted list\n");
	for(i=n-1;i>=0;i--)
		printf("%d\t",q[i]);	
}
void heap(int b[],int m)
{
	int t[10],j,i,loc,pre,temp;
	for(i=0;i<m;i++)
	{
		t[i]=b[i];
		loc=i;
		while(loc>0)	
		{
			pre=(loc-1)/2;
			if(t[loc]>t[pre])
			{
				temp=t[loc];
				t[loc]=t[pre];
				t[pre]=temp;
			}
			loc=pre;			
		}
	}
	if(f==1)
	{
	printf("the heap is\n");
	for(i=0;i<m;i++)
		printf("%d\t",t[i]);
	f=0;
	printf("\n");
	}
	heapsort(t,m);
}
void heapsort(int s[],int l)
{	int d[10],i;
	if(l>0)
	{	q[e]=s[0];
		e++;
	for(i=1;i<l;i++)
		d[i-1]=s[i];
	heap(d,l-1);
	}
}
