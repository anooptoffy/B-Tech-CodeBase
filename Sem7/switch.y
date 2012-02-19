%{ 
   #include<stdio.h> 
%} 
%token SWITCH 
%token CASE 
%token ID 
%token NUM 
%token BREAK 
%token DEFAULT 
%% 
SS:S'\n' {printf("Accepted");return 0;} 
S:SWITCH '('ID')' line BLK; 
BLK:'{'line BODY '}'|; 
BODY:CASE ' 'NUM':' line expr line BODY 
|DEFAULT ':' line expr line; 
expr:E';'line expr 
|ID'='E ';'line expr 
|BREAK';' 
|; 
E:T'+'E 
|T'-'E 
|T; 
T:T'*'F; 
|T'/'F 
|F; 
F:ID 
|NUM 
|'('E')'; 
line:'\n'|; 
%% 
  int yywrap() 
 { 
  return 1; 
 } 
 void yyerror(char *s) 
 { 
 } 
 main() 
 { 
  if(yyparse()) 
   { 
     printf("Not accepted"); 
   } 
 }
