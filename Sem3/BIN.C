#include <stdio.h>
#include<math.h>
int dec(long int n)
{
	int dec=0,k;
	for(k=0;n!=0;n/=10,k++)
		dec+=(n%10)*pow(2,k);
	return dec;
}
int oct(int n)
{
	int ret=0,k;
	for(k=0;n!=0;n/=1000,k++)
		ret+=dec(n%1000)*pow(10,k);
	return ret;
}
void hex(int n)
{
	int t,i;
	char a[5]="0000";
	for(i=4;(n!=0);i--,n/=10000)
	{
		t=dec(n%10000);
		if(t<10)
			a[i]=('0'+t);
		else
			a[i]=('A'+t-10);
	}
	a[5]=NULL;
	printf("%s",a);
}
int main()
{
	int n;
	printf("\n\nEnter the binary no: ");
	scanf("%d",&n);
	printf("\nDecimal = %d\n  ,  %d\n  , ",dec(n),oct(n));
	hex(n);
	return 0;
}
