#include <stdio.h>
void main()
{
int n,k,i,j;
float a[5][6],x;
clrscr();
printf("Enter the number of unknowns : ");
scanf("%d",&n);
printf("\nEnter the augmented matrix of order %dx%d\n\n",n,n+1);
for(i=0;i<n;i++)
	for(j=0;j<n+1;j++)
		scanf("%f",&a[i][j]);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		x=a[j][i]/a[i][i];
		if(i!=j)
			for(k=0;k<(n+1);k++)
				a[j][k]-=(a[i][k]*x);
	}
}
printf("\nA Possible Solution :\n\n");
for(i=0;i<n;i++)
	printf("%f   ",(a[i][n]/a[i][i]));
getch();
}