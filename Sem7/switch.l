%{ 
   #include "y.tab.h" 
%} 
num [0-9]+ 
id [a-zA-Z_][a-zA-Z0-9_]* 
%% 
switch {return SWITCH;} 
case {return CASE;} 
break {return BREAK;} 
default {return DEFAULT;} 
{num} {return NUM;} 
{id} {return ID;} 
. {return *yytext;} 
\n {return *yytext;} 
%% 
