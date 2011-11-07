// Inter-process Communication

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

main()
{
	int id,sd=1,pd[2];
	char buf[20];
	pipe(pd);
	if ((id = fork())< 0)
	{ 
		printf("error !! cannot create child \n");
		exit(-1);
	}
	if(id==0)
	{
		printf("\nEnter ID0 message \n");
		scanf("%s",buf);
		write(pd[1],buf,20);
		sleep(1);
		lseek(pd[0],0,SEEK_SET);
		read(pd[0],buf,20);
		printf("\nID0 reads data  \n %s\n",buf);
	}
	else 
	{
		lseek(pd[0],0,SEEK_SET);
		read(pd[0],buf,20);
		printf("\nID1 reads data \n %s \n",buf);
		scanf("%s",buf);
		write(pd[1],buf,20);
	}
	return 0;
}

