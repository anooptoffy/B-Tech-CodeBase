#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char infix[60];
int paran[20];
struct bst
{
char op;int or;
struct bst *left,*right;
}
*nw,*root=0;
typedef struct bst node;
node *ins(node *tree,int i)
{
if(tree==0)
{
tree=(node *)malloc(sizeof(node));
tree->left=tree->right=0;
tree->op=infix[i];
tree->or=i;
}
else if(i>tree->or)
tree->right=ins(tree->right,i);
else 
tree->left=ins(tree->left,i);
return(tree);
}
int par(int i)
{
int j;
for(j=0;;j=j+2)
if(paran[j]=i)
return(paran[j+1]);
}
void disp(node *tree)
{
if(tree!=0)
{
disp(tree->left);
disp(tree->right);
printf("%c",tree->op);
}
}
void scan(int k,int l)
{
int i;
for(i=k;i<l;i++)
if(infix[i]=='+'||infix[i]=='-')
root=ins(root,i);
else if(infix[i]=='(')
i=par(i);
for(i=k;i<l;i++)
if(infix[i]=='*'||infix[i]=='/')
root=ins(root,i);
else if(infix[i]=='(')
i=par(i);
}
int evl(node *tree)
{
int i;
if(tree->op>64)
{
printf("\nEnter the value of %c:",tree->op);
scanf("%d",&i);
return(i);
}
else if(tree->op=='+')
return(evl(tree->left)+evl(tree->right));
else if(tree->op=='-')
return(evl(tree->left)-evl(tree->right));
else if(tree->op=='*')
 return(evl(tree->left)*evl(tree->right));
 else if(tree->op=='/')
 return(evl(tree->left)/evl(tree->right));
}
main()
{
int i,j,m=0,n=0;
printf("Enter the infix expression:\n");
scanf("%s",infix);
for(i=0;infix[i]!=0;i++)
{
if(infix[i]=='(')
{
paran[n]=i;
n++;
for(j=i+1;infix[j]!=0;j++)
if(infix[j]=='(')
m++;
else if(infix[j]==')'&&m==0)
{
paran[n]=j;
n++;
break;
}
else if(infix[j]==')'&&m!=0)
m--;
}
m=0;
}
scan(0,strlen(infix));
for(i=0;i<n-1;i=i+2)
scan(paran[i]+1,paran[i+1]);
for(i=0;i<strlen(infix);i++)
if(infix[i]>=65)
root=ins(root,i);
printf("The expression tree in postorder is:");
disp(root);
printf("\nExpression Evaluation");
i=evl(root);
printf("\nFinal value is:%d\n",i);
}
































