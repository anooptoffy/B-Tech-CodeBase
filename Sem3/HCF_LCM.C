#include <stdio.h>
int hcf_function(int m,int n)
{
	int temp,reminder;
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	while(1)
	{
		reminder=m%n;
		if(reminder==0)
			return n;
		else
			m=n;
		n=reminder;
	}
}
int lcm_function(int m,int n)
{
	int lcm;
	lcm=m*n/hcf_function(m,n);
	return lcm;
}
main()
{
	int array[20],n,i,choice,lcm,hcf;
	printf("Enter No of Elements (0 to exit) :");
	scanf("%d",&n);
	printf("Enter Elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	hcf=array[0];
	for(i=1;i<n;i++)
		hcf=hcf_function(hcf,array[i]);
	printf("\nHCF = %d",hcf);
	lcm=array[0];
	for(i=1;i<n;i++)
		lcm=lcm_function(lcm,array[i]);
	printf("\nLCM = %d\n\n",lcm);
}