#include<stdio.h>
main()
{
int a,b=0,i;
scanf("%d",&a);
for(i=2;i<a;i++)
		if(a%i==0)
		{
			b=1;
			break;
		}
	if(b==0)
		printf("\n%d is a prime number!!",a);
	else
		printf("\n%d is NOT a prime number!!",a);
}
