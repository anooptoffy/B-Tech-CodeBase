#include<stdio.h>
int a[50],n,p=0;
main()
{
int i;
printf("Enter the no.of elements to be sorted \n");
scanf("%d",&n);
printf("Enter the elements to be sorted into the array:\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("\nThe entered elements are:\n");
for(i=0;i<n;i++)
	printf("%d\t",a[i]);
msort(0,n-1);
printf("\nThe sorted array is:\n");
for(i=0;i<n;i++)
	printf("%d\t",a[i]);
printf("\n");
}

void mergesort(int low,int mid,int high)
{
int i,j,k,temp[50];
i=low;
j=mid+1;
k=low;
while((i<=mid)&&(j<=high))
{
if(a[i]>=a[j])
temp[k++]=a[j++];
else
temp[k++]=a[i++];
}
while(i<=mid)
temp[k++]=a[i++];
while(j<=high)
temp[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=temp[i];
printf("\nArray after %dth pass is ",++p);
for(i=0;i<n;i++)
printf("%d ",a[i]);
}


msort(int low,int high)
{
int mid;
if(low!=high)
{
mid=((low+high)/2);
msort(low,mid);
msort(mid+1,high);
mergesort(low,mid,high);
}
}


