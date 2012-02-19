
%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID    
%token NUM
%token DO
%token WHILE
%token LE
%token GE
%token EQ 
%token NE 
%token OR 
%token AND
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%left '!'

%%
SS: S {printf("Input accepted.\n");exit(0);}
S : ST1 | ST2 
ST1    :    DO '{' ST '}' WHILE'(' E2 ')' ';'
ST      : ST1
          | ST2
	  | ST
          | E';'
          |
          ;
E       : ID'='E
         | E'+'E
         | E'-'E
         | E'*'E
         | E'/'E
         | E'<'E
         | E'>'E
         | E LE E
         | E GE E
         | E EQ E
         | E NE E
         | E OR E
         | E AND E
         | ID
         | NUM
         |
         ;
E2     :   E'<'E
         | E'>'E
         | E LE E
         | E GE E
         | E EQ E
         | E NE E
         | E OR E
         | E AND E
         | ID
         | NUM
         |
         ;
ST2    :WHILE'(' E2 ')' '{' ST '}'
%%
int yywrap()
 {
     return 1;
  }

void yyerror(char *s)
{
		printf("%s\n",s);
}

main()
{
   printf("Enter the exp: ");
   yyparse();
}
