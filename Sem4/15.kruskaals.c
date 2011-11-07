#include<stdio.h>
struct edge
{
	int vs,vd,wt,used;
}s[20];
int g[20][20];
void kruskal(int n);

main()
{
	int n,i,j;
	printf("ENTER THE NO. OF VERTICES");
	scanf("%d",&n);
	printf("ENTER THE WEIGHTED ADJACENCY MATRIX\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	printf("THE ADJACENCY MATRIX IS\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf(" %d ",g[i][j]);
		printf("\n");
	}
	kruskal(n);
}
void kruskal(int n)
{
	int p,par[20],k=0,i,j,q,sum=0;
	struct edge t;
	for(p=1;p<=n;p++)
		par[p]=p;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(g[i][j]>0)
			{
				k++;
				s[k].vs=i;
				s[k].vd=j;
				s[k].wt=g[i][j];
				s[k].used=0;
			}
		}
	for(i=1;i<=k;i++)
		for(j=i+1;j<=k;j++)
		{
			if(s[i].wt>s[j].wt)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	for(i=1;i<=k;i++)
	{
		if(par[s[i].vs]!=par[s[i].vd])
		{
			s[i].used=1;
			q=par[s[i].vs];
			par[s[i].vs]=par[s[i].vd];
			for(j=1;j<=k;j++)
			{
				if(par[j]==q)
					par[j]=par[s[i].vd];
			}
		}
	}
	for(i=1;i<=k;i++)
		if(s[i].used==1)
		{
			printf(" \nV%d->V%d =%d",s[i].vs,s[i].vd,s[i].wt);
			sum+=s[i].wt;
		}
	printf("total cost=%d",sum);
}

