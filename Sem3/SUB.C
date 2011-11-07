#include<stdio.h>
#include<string.h>
void main()
{
char *p,*ch,*s;
printf("\n\nEnter the main string : ");
scanf("%s",ch);
printf("\nEnter the substring : ");
scanf("%s",s);
while(p=strstr(ch,s))
{
	ch[strlen(ch)-strlen(p)]=NULL;
	p+=strlen(s);
	strcat(ch,p);
}
printf("\nMain string after deletion : %s\n",ch);
}