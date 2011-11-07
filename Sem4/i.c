#include<stdio.h>
struct NODE
{
char data;
struct NODE *lchild;
struct NODE *rchild;
};
typedef struct NODE *node;

node exptree(char[]);
void push_cha(node);
void push_op(char);
node pop_cha();
char pop_op();
int prec(char);


node create()
{
	return((node)malloc(sizeof(node)));
}

node newnode=NULL,root,temp,nstack[50];
int optop=-1,ntop=-1,p,i,opstack[50];

main()
{
	char str[50];	
	int z;
	printf("\nENTER EXPRESSION");	
	scanf("%s",str);
	root=exptree(str);
	z=evaluate(root);
	printf("\nThe result is %d\n",z);
}

node exptree(char str[])
{
	for(i=0;str[i]!='\0';i++)
	{
		if(isalnum(str[i]))
		{
			newnode=create();
			newnode->data=str[i];
			newnode->lchild=NULL;
			newnode->rchild=NULL;
			push_cha(newnode);
		}
		else if(str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(str[i]=='('||(optop==-1))
			push_op(str[i]);
			else if(prec(str[i])>prec(opstack[optop]))
				push_op(str[i]);
			else
			{
				while((prec(str[i])<=prec(opstack[optop])&&(opstack[optop]!='('))&&(optop>=0))
				{
					newnode=create();
					newnode->data=pop_op();
					newnode->rchild=pop_cha();
					newnode->lchild=pop_cha();
					push_cha(newnode);	
				}
				push_op(str[i]);
			}
		}
		else if(str[i]==')')
		{
			while(opstack[optop]!='(')
			{
				newnode=create();
				newnode->data=pop_op();
				newnode->rchild=pop_cha();
				newnode->lchild=pop_cha();
				push_cha(newnode);
			}
			pop_op();
		}
		else
			printf("\nInvalid character");
	}
	while(optop!=-1)
	{
		newnode=create();
		newnode->data=pop_op();
		newnode->rchild=pop_cha();
		newnode->lchild=pop_cha();
		push_cha(newnode);
	}
	return pop_cha();
}

void push_cha(node ptr)
{
	ntop=ntop+1;
	nstack[ntop]=ptr;
}


void push_op(char str)
{
	opstack[++optop]=str;
}

node pop_cha()
{
	node ptr;
	ptr=nstack[ntop];
	ntop=ntop-1;
	return ptr;
}

int prec(char k)
{
	int p;
	switch(k)
	{
		case '^':p=3;break;
		case '*':p=2;break;
		case '/':p=2;break;
		case '+':p=1;break;
		case '-':p=1;break;
		case '(':p=0;break;
	}
	return p;
}

char pop_op()
{
	char d;
	d=opstack[optop];
	optop=optop-1;
	return(d);
}

int evaluate(node str)
{
	int x,y,z;
	if(str!=NULL)
	{
		if((str->data=='+')||(str->data=='-')||(str->data=='*')||(str->data=='/'))
		{
			x=evaluate(str->lchild);
			y=evaluate(str->rchild);
			switch(str->data)
			{
				case '+':z=x+y;break;
				case '-':z=x-y;break;
				case '*':z=x*y;break;
				case '/':z=x/y;break;
			}
			return z;	
		}
		return str->data-48;
	}
	return(0);
}

