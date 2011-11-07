#include<stdio.h>
#include<stdlib.h>
void adjlist(int,int);
void bfs(int);
void queue(int);
struct bfs
{
 int data;
 struct bfs *next;
}
*vx[20]={0},*temp;
int vi[20]={0},j=0,c=0,qu[20],c1=-1;
typedef struct bfs node;
main()
{
 int i,v1,v2,v,e,sv;
 printf("Enter the no of vertex:");
 scanf("%d",&v);
 printf("Enter the no of edges:");
 scanf("%d",&e);
 for(i=0;i<e;i++)
 {
   printf("Enter the pair of vertices for edge no%d:-",i+1);
   scanf("%d %d",&v1,&v2);
   adjlist(v1,v2);
   adjlist(v2,v1);
 }
 printf("The adjacency list is:\n");
 for(i=1;i<=v;i++)
  {
   printf("V%d",i);
   temp=vx[i];
   while(temp!=0)
    {
     printf(" %d",temp->data);
     temp=temp->next;
    }
    printf("\n");
  }
  printf("Enter the source vertex the traversal to be start:");
  scanf("%d",&sv);
  printf("Traversed list is:");
  bfs(sv);
  printf("\n");
}
void adjlist(int ind,int num)
{
 node *temp1;
 temp=(node*)malloc(sizeof(node));
 temp->data=num;
 temp->next=0;

 if(vx[ind]==0)
   vx[ind]=temp;
 else
  {
   temp1=vx[ind];
   while(temp1->next!=0)
     temp1=temp1->next;
   temp1->next=temp;
  }
}
void bfs(int n)
{
 node *temp1;
 int count=0,x;
 temp1=vx[n];
 if(vi[n]!=1)
  {
   vi[n]=1;
   printf(" %d  ",n);
  }    
 while(temp1!=0)
  {
    n=temp1->data;
    if(vi[n]!=1)
     {
       vi[n]=1;
       printf("-> %d ",n);
       queue(n);
       count++;
     }
       temp1=temp1->next;
   }
   int i;
for(i=0;i<count;i++)
 bfs(qu[i]);
}
void queue(int x)
{
 qu[c]=x;
 c++;
}
   
   
   
 
