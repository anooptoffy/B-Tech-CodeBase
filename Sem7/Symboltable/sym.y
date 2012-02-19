%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define INT 0;
#define CHAR 1;
#define FLOAT 2;
#define DOUBLE 3;
int i=0,flag=0;
struct node
{
	char name[20];
	int varType;
	struct node *next;
};
int type;
struct node *table[10]={NULL};
void print(int);
void insert(int t,char *name);
void printResult(void);
void yyerror(char *s);
%}

%union
{
	int ival;	
	char name[20];
}
%token <ival>tINT;
%token <ival>tCHAR;
%token <ival>tFLOAT;
%token <ival>tDOUBLE;
%token <ival>tNAME;
%type <name>name;
%token NL
%token SC
%token COMMA
%token RCB
%token LCB
%token RAB
%token LAB
%token RB
%token LB
%token MAIN
%token HEAD
%token HNAME

%%

statement:stmt NL	{ if(flag==0)
			{
			   printf("\n            SYMBOL TABLE\n\n");
			   printf("VARIABLE\t TYPE \n");
                                       printf("***********************\n");
                                       printResult();
			   printf("\n");
			   printf("****************************\n");
			}
			return;

	                       }
              | RCB NL    { if(flag==1)
               
			{i--;
			if(i==0)
		               {
			       printf("\n               SYMBOL TABLE\n\n");
			       printf("VARIABLE \t TYPE\n");
			       printf("********************\n");
			       printResult();
			       printf("\n");
			      exit(0);
			      flag=0;
   			    }
			return;
			}}
	|LCB NL		{ i++;
			return;
			}
	|LCB		{ i++;
			return;}
	|tINT MAIN LB RB NL 	{return;}
	| HEAD LAB HNAME RAB NL	{return;}
        ;
stmt:type namelist SC stmt	{}
        |{}
	;
type:tINT			{ type=INT; }
        |tCHAR			{ type=CHAR; }
         |tFLOAT		{ type=FLOAT; }
         |tDOUBLE		{ type=DOUBLE; } ;
namelist:name			{ insert(type,$1) ; }
              |name COMMA namelist	{ insert(type,$1); }
		;
name:tNAME { strcpy($$,yylval.name); }
     ;
%%

void insert(int t,char *name)
{
	struct node *p,*q;
	int k,m=10;
	k=(int)name[10];
	k=k%m;
	q=table[k];
	while(q!=NULL)
	{
		if(strcmp(q->name,name)==0)
		{
			printf("error:multiple declaration\n");
			exit(0);
		}
		q=q->next;
	}
	q=table[k];
	p=(struct node *)malloc(sizeof(struct node));
	strcpy(p->name,name);
	p->varType=t;
	p->next=q;
	table[k]=p;
}

void printResult()
{
	int i;
	for(i=0;i<10;i++)
		print(i);
}

void print(int k)
{
	struct node *p=table[k];
	while(p!=NULL)
	{
		printf("\n%s\t\t",p->name);
		if(p->varType==0)
			printf("int");
		else if(p->varType==1)
			printf("char");
		else if(p->varType==2)
			printf("float");
		else
			printf("double");
		p=p->next;
	}
}

main(int argc,char **argv)
{
	extern yyin;
	argc--;
	argv++;
	if(argc>0)
	{
		yyin=(int)fopen(argv[0],"r");
		flag=1;	
	}
	
	while(1)
	{
		yyparse();
	}
}

void yyerror(char *s)
{
}
