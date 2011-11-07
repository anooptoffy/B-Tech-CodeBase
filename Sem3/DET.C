#include<stdio.h>
float detrm(float a[10][10],int n)
{
	float b[10][10],sum=0;
	int i,j,k,x,u=1;
	if(n==1)
		return a[0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			x=0;
			for(k=0;k<n-1;k++)
			{
				if(k==i)
					x++;
				b[j][k]=a[j+1][x+k];
			}
		}
		sum+=u*a[0][i]*detrm(b,n-1);
		u*=-1;
	}
	return sum;
}
void main()
{
	float a[10][10];
	int i,j,order;
	printf("\n\nEnter order of matrix :");
	scanf("%d",&order);
	printf("\nEnter the square matrix :\n");
	for(i=0;i<order;i++)
		for(j=0;j<order;j++)
			scanf("%f",&a[i][j]);
	printf("Determinent Value :%f\n",detrm(a,order));
}