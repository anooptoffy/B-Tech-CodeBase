#include<stdio.h>
#include<string.h>
void main(void)
{
int i,j=0;
char t[30],c[50],s[50],l[30]="\0";
clrscr();
gets(c);
strcpy(s,c);
printf("\n\nString\n%s\n\n",c);
for(i=0;i<=strlen(c);i++)
{
	if(c[i]!=' ' && c[i]!='\0')
	{
		t[j]=c[i];
		j++;
	}
	else
	{
		t[j]=NULL;
		if(strlen(t)<strlen(s))
			strcpy(s,t);
		if(strlen(t)>strlen(l))
			strcpy(l,t);
		j=0;
	}
}
printf("\nshort :  %s\nlong  :  %s",s,l);
getch();
}