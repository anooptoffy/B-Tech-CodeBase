#include<stdio.h>
#include<math.h>
#define PI 3.1415
int fact(int num)
{
	int f=0;
	if(num==1)
		return 1;
	else
		f=num*fact(num-1);
	return f;
}
float exp_x(int x,int n)
{
	int i=1;
	float ex=1;
	for(;i<n;i++)
		ex+=(float)pow(x,i)/fact(i);
	return ex;
}
double sin_x(int d,int n)
{
	int t,j;
	double v=0.0,r=(double)d*PI/180;
	for(t=1,j=2;t<n*2;t+=2,j++)
		v+=(double)pow(-1.0,j)*pow(r,t)/fact(t);
	return v;
}
double cos_x(int d,int n)
{
	int t,j;
	double v=1.0,r=(double)d*PI/180;
	for(t=2,j=1;t<=n;t+=2,j++)
		v+=(double)pow(-1.0,j)*pow(r,t)/fact(t);
	return v;
}
void main()
{
	int choice,x,n;
	do
	{
		printf("\nMenu\n1. e^x\n2. Sin(x)\n3. Cos(x)\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("e^x\nEnter x and n:\t");
			scanf("%d %d",&x,&n);
			printf("e^%d(%d) = %f\n",x,n,exp_x(x,n));
			break;
		case 2:
			printf("\nsin(x)\nEnter x and n:\t");
			scanf("%d %d",&x,&n);
			printf("\nSin(%d)(%d) = %f\n",x,n,sin_x(x,n));
			break;
		case 3:
			printf("\ncos(x)\nEnter x and n:\t");
			scanf("%d %d",&x,&n);
			printf("\nCos(%d)(%d) = %f\n",x,n,cos_x(x,n));
			break;
		case 4:
			break;
		default:
			printf("Wrong choice");
			break;
		}
	}while(choice!=4);
}