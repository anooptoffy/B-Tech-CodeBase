// To implement Banker's Algorithm

#include<stdio.h>

int main()
{
	int np,nr,i,j,k,check,pp[10],pn=0;	
	int avail[10],alloc[10][10],max[10][10],c[10];

	printf("Enter the process and resourses:");
	scanf("%d %d",&np,&nr);
	printf("Enter the instances for each resourses:");
	for(i=0;i<nr;i++)
 		scanf("%d",&c[i]);
 	
	printf("Enter the maximum permissible allocation:");
 	for(i=0;i<np;i++)
 		for(j=0;j<nr;j++)
   			scanf("%d",&max[i][j]);
 	printf("Enter the current allocation:");
	for(i=0;i<np;i++)
  		for(j=0;j<nr;j++)
 	  		scanf("%d",&alloc[i][j]);
 	while(1)
  	{
  		check=0;
   		for(i=0;i<np;i++)
    			for(j=0;j<nr;j++)
    	 		{
      				if(alloc[i][j]==0)
       					check++;
      				else
      	 				break;
     			}
   		if(check==(np*nr))
    		{
     			printf("The system is safe!!!!");
     			for(i=0;i<np;i++)
      				printf("\nAllocation no %d to process no %d ",i,pp[i]);
      			break;
    		}
    		for(i=0;i<nr;i++)
     		{
     		 	k=0;
      			for(j=0;j<np;j++)
       				k+=alloc[j][i];
       			avail[i]=c[i]-k;
      		}
     		for(i=0;i<np;i++)
      		{
       			check=0;
       			for(j=0;j<nr;j++)
        			if(alloc[i][j]==0)
         				check++;
        		if(check==nr)
         			continue;
      			for(j=0;j<nr;j++)
       				if((max[i][j]-alloc[i][j])>avail[j])
        		break;
       			if(j==nr)
        		{
         			pp[pn++]=i+1;
         			for(j=0;j<nr;j++)
        	 		 	alloc[i][j]=0;
         			break;
       			}
      			if(i==np)
       			{
        			printf("System is unsafe!!!");
        			break;
       			}
      		}
     	} 
}
