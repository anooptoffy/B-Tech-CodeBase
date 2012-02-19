%{
#include <stdio.h>
%}
%token NUM
%left '+' '-' '*' '/'
%right '='
%%
S: E '\n' {printf("=%d\n",$1); return 0;}
E: T '+' E {$$ = $1 +$3;}
     | T '-' E {$$ = $1 -$3;}
    | T {$$ = $1;}
    ;
T : F '*' T {$$ = $1 *$3;}
   | F '/' T {$$ = $1 /$3;}
    | F {$$ = $1;}
 ;
F : NUM {$$ = $1;}
| '(' E ')' {$$=$2;}
;
%%
void yyerror(char *s){}
main(){
if(yyparse())
{
printf("not accepted \n");
}
return 0;
}
int yywrap()
{
return 1;
}
