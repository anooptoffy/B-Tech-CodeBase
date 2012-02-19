%{
#include <stdio.h>
%}

id	[a-zA-Z0-9_]+
sp	[#%{<>}()]
op	[+\-/*]
comment	\/\*.*\*\/
no	[0-9]+
%%
"if"|"while"|"do"|"for"|"switch"|"case"|"break"|"return"|"main"|"printf"		{printf("Keyword - %s \n",yytext);}
{id}	{printf("Identifier - %s \n",yytext);}
{op}	{printf("Operator - %s \n",yytext);}
{sp}	{printf("Special Character - %s \n",yytext);}
{no}	{printf("Number - %s \n",yytext);}
{comment}	{printf("Comment - %s \n",yytext);}
.	{;}
%%

int main()
{
	yyin = fopen("test.c","r");
	yylex();
	return 0;
}
