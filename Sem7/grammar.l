%{
#include<stdio.h>
#include"y.tab.h"
%}
%%
[a-zA-Z][a-zA-Z0-9]*	{return ID;}
[0-9]+			{return NUM;}
[+*\-/\{\}\[\];,()\n]	{return *yytext;}
.	{;}
%%
int yywrap()
{
return 1;
}

