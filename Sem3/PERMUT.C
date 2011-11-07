#include<stdio.h>
#include<string.h>
void shift(char ch[],int n)
{
	int i;
	char c=ch[0];
	for(i=0;i<(n-1);i++)
		ch[i]=ch[i+1];
	ch[n-1]=c;
}
void permut(char s[],int n)
{
	int i;
	if(n==1)
	{
		printf("%s\n",s);
		return;
	}
	for(i=0;i<n;i++)
	{
		permut(s,n-1);
		shift(s,n);
	}
}
void main()
{
	char ch[20];
	printf("Enter the string : ");
	gets(ch);
	permut(ch,strlen(ch));
}