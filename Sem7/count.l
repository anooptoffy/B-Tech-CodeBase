id	[A-Za-z][A-Za-z0-9]* 
num	[0-9]+ 
op	[+\-*/] 
%{ 
#include<string.h> 
int a=0,b=0,c=0,d=0,i; 
char iden[100][50]; 
int num[50]; 
char oper[50][2]; 
char key[100][50]; 
%} 
%option noyywrap 
%% 
"if"|"while"|"do"|"else"|"for"|"int"|"char"|"main"|"float"|"double"|"void"	{ if(a==0) 
              { 
                strcpy(key[a],yytext); 
                a++; 
              } 
             else 
             {for(i=0;i<a;i++) 
              if( strcmp(yytext,key[i]) == 0 ) 
               break; 
               if(i==a) 
               { strcpy(key[a],yytext); 
                a++; 
               } 
            }} 
 						 
{id}   	   { 
             if(b==0) 
              { 
                strcpy(iden[b],yytext); 
                b++; 
              } 
             else 
             {for(i=0;i<b;i++) 
              if( strcmp(yytext,iden[i]) == 0 ) 
               break; 
               if(i==b) 
               { 
                strcpy(iden[b],yytext); 
                b++; 
               } 
            }} 
{num}		{ 
            if(c==0) 
              { 
                 num[c]=atoi(yytext); 
                 c++; 
              } 
             else 
             {for(i=0;i<c;i++) 
              if(num[i]==atoi(yytext)) 
               break; 
               if(i==c) 
               { 
                 num[c]=atoi(yytext); 
                 c++; 
               } 
            }} 
{op}	{ 
            if(d==0) 
              { 
                strcpy(oper[d],yytext); 
                d++; 
              } 
             else 
             {for(i=0;i<d;i++) 
              if( strcmp(yytext,oper[i]) == 0 ) 
               break; 
               if(i==d) 
               { 
              strcpy(oper[d],yytext); 
              d++; 
               } 
            }} 
.		{;} 
%% 
int main(void) 
{ 
    char name[20];   
    printf("Enter file name\n"); 
    scanf("%s",name); 
    yyin=fopen(name,"r"); 
    /* Call the lexer, then quit. */ 
    yylex(); 
    printf("\nKeyword count is %d",a); 
    if(a) 
    { 
      printf("\nkeywords are"); 
      for(i=0;i<a;i++) 
       printf("\n%s",key[i]);
    } 
    printf("\n\nIdentifier count is %d",b); 
    if(b) 
    { 
    printf("\nidentifiers are"); 
    for(i=0;i<b;i++) 
     printf("\n%s",iden[i]); 
    } 
    printf("\n\nNumber count is %d",c); 
    if(c) 
    {printf("\nnumbers are"); 
    for(i=0;i<c;i++) 
     printf("\n%d",num[i]); 
   } 
    printf("\n\nOperator count is %d",d); 
    if(d) 
   { 
    printf("\noperators are"); 
    for(i=0;i<d;i++) 
     printf("\n%s",oper[i]); 
   } 
    return 0; 
} 
