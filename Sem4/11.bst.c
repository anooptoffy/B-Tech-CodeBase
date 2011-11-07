#include <stdio.h>
#include <stdlib.h>
struct bst
{
	int n;
	struct bst *left,*right;
}*new,*root=0;
typedef struct bst node;
int val;
node *create()
{
	new=(node *)malloc(sizeof(node));
	new->left=new->right=0;
	new->n=val;
	return(new);
}
node *ins(node *tree)
{
	if(tree==0)
		tree=create();
	else if (val==tree->n)
		printf("duplication");
	else if (val>tree->n)
		tree->right=ins(tree->right);
	else 
		tree->left=ins(tree->left);
	return(tree);
}
void scr(node *tree)
{
	if(tree==0)
		printf("search unsuccessful");
	else if (tree->n==val)
		printf("search successful");
	else if (val>tree->n)
		scr(tree->right);
	else
		scr(tree->left);
}
void preorder(node *tree)
{
	if(tree!=0)
	{
		printf("%d\t",tree->n);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(node *tree)
{
	if(tree!=0)
	{
		inorder(tree->left);
		printf("%d\t",tree->n);
		inorder(tree->right);
	}
}

void postorder(node *tree)
{
	if(tree!=0)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\t",tree->n);
	}
}

node *del(node *tree)
{
	int t;
	node *temp;
	if(tree==0)
	{
		printf("element not found,tree empty deletion not possible");
		return (tree);
	}
	else if(val>tree->n)
	{
		tree->right=del(tree->right);
		return(tree);
	}
	else if(tree->left==0&&tree->right==0)
		return 0;
	else if(tree->left==0)
		return (tree->right);
	else if(tree->right==0)
		return (tree->left);
	else
	{
		temp=tree->left;
		if(temp->right==0)
		{
			temp->right==tree->right;
			tree=temp;
		}
		else
		{
			while(temp->right!=0)
				temp=temp->right;
			t=val=temp->n;
			root=del(root);
			tree->n=t;
		}
		return (tree);
	}
}
main()
{
	int choice;
	printf("\nfirst root");
	printf("\nmenu\n1.ins\n2.src\n3.del\n4.in\n5.pre\n6.post\n7.exit");
	do
	{
		printf("\nchoice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nenter the new value\t");
			scanf("%d",&val);
			root=ins(root);
			break;
			case 2:printf("to be src");
			scanf("%d",&val);
			scr(root);
			break;
			case 3:printf("to be del");
			scanf("%d",&val);
			if(root==0)
				printf("tree is empty");
			else
				root=del(root);
			break;
			case 4:inorder(root);
			break;
			case 5:preorder(root);
			break;
			case 6: postorder(root);
			break;
		}
	}while(choice!=7);
}

