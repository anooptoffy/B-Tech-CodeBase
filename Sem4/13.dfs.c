#include<stdio.h>
#include<stdlib.h>
#define MAX 15
struct dfs
{
int num;
struct dfs *next;
}
*temp,*t,*v[MAX]={0};
typedef struct dfs node;
int visit[MAX]={0};
void adj(int index,int vx)
{
temp=(node *)malloc(sizeof(node));
temp->num=vx;
temp->next=0;
if(v[index]==0)
v[index]=temp;
else {
t=v[index];
while(t->next!=0)
t=t->next;
t->next=temp;
}
}
void dfs(int n)
{
node *te;
if(visit[n]!=1)
{
visit[n]=1;
printf("%d",n);
te=v[n];
while(te!=0)
{
dfs(te->num);
te=te->next;
}
}
}
main()
{
int en,vn,i,a,b;
printf("Enter the no of vertices:");
scanf("%d",&vn);
printf("Enter the no of edges:");
scanf("%d",&en);
printf("Enter the edges:");
for(i=0;i<en;i++)
{
printf("Enter the pair of vertices for edge %d:",i+1);
scanf("%d%d",&a,&b);
adj(a,b);
adj(b,a);
}
printf("Adjacency list coresponding to each vertex:\n");
for(i=0;i<vn;i++)
{
printf("v%d:",i);
temp=v[i];
while(temp!=0)
{
printf("v%d->",temp->num);
temp=temp->next;
}
printf("\n");
}
printf("Enter the vertex from which the traversal should be started:");
scanf("%d",&en);
printf("DFS traversal is:");
dfs(en);
}

