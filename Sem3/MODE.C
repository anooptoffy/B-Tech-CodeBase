#include<stdio.h>
float mean_function(float array[],int n)
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
		sum=sum+array[i];
	return (sum/n);
}
float median_function(float a[],int n)
{
	float temp;
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
	if(n%2==0)
		return (a[n/2]+a[n/2-1])/2;
	else
		return a[n/2];
}
void mode_function(float a[],int n)
{
	int b[25],i,j,l=-1;
	for(i=0;i<n-1;i++)
	{
		b[i]=0;
		for(j=i+1;j<n-1;j++)
			if(a[i]==a[j])
				b[i]++;
		if(b[i]>l)
			l=b[i];
	}
	printf("Mode(s) :  ");
	if(l==0)
		printf("NIL");
	else
		for(i=0;i<n;i++)
			if(l==b[i])
				printf("%f  ",a[i]);
}
void main()
{
int i,n;
float array[25];
printf("\n\nEnter No of Elements :");
scanf("%d",&n);
printf("Enter Elements\n");
for(i=0;i<n;i++)
	scanf("%f",&array[i]);
printf("\nMean   = %f",mean_function(array,n));
printf("\nMedian = %f\n",median_function(array,n));
mode_function(array,n);
}