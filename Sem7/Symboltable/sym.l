%{
#include "y.tab.h"
#include<string.h>
int recog=0;
%}

%%
"#include" 			{ return HEAD;}
"<" 				{ return LAB;}
">" 			{ return RAB; }
")"		 	{ return RB; }
"("			{return LB; }
"{"			{ return LCB; }
"}"			{ return RCB; }
","			{ return COMMA; }
";"			{ recog=0; return SC;  }
"main"			{ return MAIN; }
"int"			{ recog=1; return tINT; }
"char"			{ recog=1; return tCHAR; }
"float"			{ recog=1; return tFLOAT; }
"double"		{ recog=1;return tDOUBLE; }
[a-z][a-zA-Z0-9]*	{ if(recog){ strcpy(yylval.name,yytext);return(tNAME); }}
[a-z]+[\.h]		{ return HNAME;  }
"\n"			{ return NL; }
[\t]			 ;
.
%%

int yywrap(void)
{
return 0;
}
