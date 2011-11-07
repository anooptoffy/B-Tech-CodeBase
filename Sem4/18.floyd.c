#include <stdio.h>
int a[10][10],n,i,j,k;

void floyd()
{
	printf("enter the size of the matrix");
	scanf("%d",&n);
	printf("enter the cost matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	scanf("%d",&a[i][j]);
			if(i==j)
			{
				a[i][j]=0;
			}
		}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][k]+a[k][j]<a[i][j])
					a[i][j]=a[i][k]+a[k][j];
	printf("shortest distance between all pair is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("  %d  ",a[i][j]);
		printf("\n");
	}
}

void warshall()
{
	printf("enter the size of matrix");
	scanf("%d",&n);
	printf("enter the adjacent matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][j]<a[i][k]&a[k][j])
					a[i][j]=a[i][k]&a[k][j];
	printf("the path matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("   %d    ",a[i][j]);
		printf("\n");
	}
}


main()
{
	int ch;
	do
	{
	printf("enter the choice \n1.floyd \n2.warshall\n3.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			floyd();
			break;
		case 2:
			warshall();
			break;
		case 3: 
			break;
		default:
			printf("invalid");
			break;
	}
	}while(ch!=3);
	
}

