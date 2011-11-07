#include<stdio.h>
int a[50],n,i,q;
q=1;
void quick_sort(int [],int,int);

int main()
{
	printf("RANGE : ");
	scanf("%d",&n);
	printf("ELEMENTS \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("AFTER QUICK SORT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void quick_sort(int a[],int low,int high)
{
	int l,h,key,temp,t;
	key=a[low];
	l=low;
	h=high;
	while(low<high)
	{
		if(a[low]<key)
		{
			low=low+1;
		}
		else
		{
			if(a[high]>=key)
			{
				high=high-1;
			}
			else
			{
				temp=a[low];
				a[low]=a[high];
				a[high]=temp; 
				key=a[low];
			}
		}
	}
	t=key;
	key=a[high];
	a[high]=t;
	printf("after %d pass\t",q);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	q++;
	if(l<high)
	{
		quick_sort(a,0,high-1);
	}
	if(low<h)
	{
		quick_sort(a,high+1,n-1);
	}
} 
