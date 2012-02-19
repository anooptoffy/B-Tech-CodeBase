%{
#include <stdio.h>
%}
%token ID
%token NUM
%%
SS:E'\n'{printf("Accepted\n"); return 0;};
E:E '+' T|E '-' T|T;
T:T '/' F|T '*' F|F;
F:ID|NUM|'(' E ')';
%%
int main()
{
	if(yyparse())
		printf("Rejected\n");	
}

int yyerror(char *s)
{
	puts(s);
}
