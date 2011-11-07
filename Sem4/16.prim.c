#include <stdio.h>
int m,n,v,a[10][10],b[10];
void prim(int k,int c)
{
	int i,j,t;
	m=100;
	for(i=1;i<=n;i++)
	{
		t=0;
		for(j=1;j<=c;j++)
			if(i!=b[j])
				t++;
		if((t==c)&&(a[k][i]!=0)&&(a[k][i]<m))
		{
			m=a[k][i];
			v=i;
		}
	}
}

main()
{
	int i,j,k,c,min,s,sum=0;
	printf("enter the size of the matrix\t");
	scanf("%d",&n);
	printf("enter the cost matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	b[1]=1;
	printf("the minimum cost spanning tree is\n");
	printf("\nnode - weight - node\n");
	for(c=2;c<=n;c++)
	{
		min=100;
		for(i=1;i<=c;i++)
		{
			prim(b[i],c);
			if(min>m)
			{
				min=m;
				k=b[i];
				s=v;
			}
		}
		sum+=min;
		b[c]=s;
		printf("%d   -   %d   -   %d\n",k,min,s);
	}
	printf("the minimum weight is %d\n",sum);
}

