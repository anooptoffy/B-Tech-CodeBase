#include<stdio.h>
#include<stdlib.h>

#define Operator 1
#define notOperator 0
#define empty -1

void formatting(void);
void getInput(void);
int chkElement(char);
void opFunc(char);
void varFunc(char);
struct node* pop(void);
void dispTree(void);
void infix(struct node*);
void prefix(struct node*);
void postfix(struct node*);

char equation[25];
struct node* stack[25];
int stackPtr = -1;

	struct node{
			char item;
			struct node* leftChild;
			struct node* rightChild;
			};
	struct node* root;
void push(struct node*);
main(void)
{
	int count;
	formatting();
	getInput();
	printf("\nYou have entered: ");
	puts(equation);
	for(count = 0; equation[count] != '\0'; count++)
	{
		switch(chkElement(equation[count]))
		{
			case Operator:
					opFunc(equation[count]);
					break;
			case notOperator:
					varFunc(equation[count]);
					break;
			default:
					printf("\nSorry unrecognized entry");
		}
	}

	dispTree();
}

void dispTree(void)
{
	char choice;
	printf("\nSelect the output form: [i]nfix, p[r]efix, p[o]stfix: ");
	choice = getchar();
	printf("\n");
	switch(choice)
	{
		case 'i':
			printf("\nInorder representation of output is: ");
			infix(stack[stackPtr]);
			break;

		case 'r':
			printf("\nPreorder representation of output is: ");
			prefix(stack[stackPtr]);
			break;

		case 'o':
			printf("\nPostorder representation of output is: ");
			postfix(stack[stackPtr]);
			break;

		default:
			printf("\nYou have pressed the button other than given choices");
	}
}

void infix(struct node* root)
{
	if(root->leftChild != NULL) infix(root->leftChild);
	printf("%c", root->item);
	if(root->rightChild !=NULL) infix(root->rightChild);
}

void prefix(struct node* root)
{
	printf("%c", root->item);
	if(root->leftChild != NULL) prefix(root->leftChild);
	if(root->rightChild !=NULL) prefix(root->rightChild);
}

void postfix(struct node* root)
{
	if(root->leftChild != NULL) postfix(root->leftChild);
	if(root->rightChild !=NULL) postfix(root->rightChild);
		printf("%c", root->item);
}

void opFunc(char optr)
{
	root = (struct node*)malloc(sizeof(struct node));
	root->item = optr;
	root->rightChild = pop();
	root->leftChild = pop();
	push(root);
}

struct node* pop(void)
{
	return(stack[stackPtr--]);
}
void varFunc(char var)
{
	root = (struct node*)malloc(sizeof(struct node));
	root->item = var;
	root->rightChild = NULL;
	root->leftChild = NULL;
	push(root);
}

void push(struct node* root)
{
	stack[++stackPtr] = root;
}

int chkElement(char element)
{
	switch(element)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			return(Operator);

		default:
			return(notOperator);
	}
}

void getInput(void)
{
	printf("\n\nEnter equation in the form of postfix: ");
	gets(equation);
}

void formatting(void)
{
	int i;
	printf("\n");
	for(i =0; i<=79 ; i++)
		printf("*");

	printf("\n......... Prgogram title\t\t# Binary Tree");
	printf("\n......... Created by\t\t        # Romasa Qasim");
	printf("\n......... Description\t\t 	# Creation of Expression Tree\n");

	for( i =0; i<=79 ; i++)
		printf("*");
}
