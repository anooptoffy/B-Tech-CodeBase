#include <stdio.h>
#include <string.h>
#include <netdb.h>

int listento(int port)
{
	int s;
	struct sockaddr_in seraddr;
	bzero((char*)&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=INADDR_ANY;
	seraddr.sin_port=htons(port);
	s=socket(AF_INET,SOCK_STREAM,0);
	if(bind(s,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
	{
		printf("Error binding\n");
		return -1;
	}
	listen(s,5);
	return s;
}

main(int argc,char* argv[])
{
	int s1,s2,port,clen,i,p,w=5,MissVector[50]={0},MP=0,EarliestMiss=0,Sb,Sn;
	char buff[256],b[50][50];
	FILE* fp;
	struct sockaddr_in cliaddr;
	clen=sizeof(cliaddr);
	if(arc<2)
	{
		printf("Port? : ");
		scanf("%d",&port);
		gets(buff);
	}
	else
		port=atoi(argv[1]);
	printf("Selective repeat with window size %d \n",w);
	s1=listento(port);
	s2=accept(s1,(struct sockaddr*)&cliaddr,&clen);

	i=0;
	Sb=0;
	Sn=w-1;
	
	while(1)
	{
		bzero(&buff,256);
		if(read(s2,buff,255)<=0)
			break;
		printf("Packet %s received \n",buff);
		p=atoi(buff);
		MissVector[p]=1;
		if(EarliestMiss==p)
		{
			for(i=p;i<Sn+1;i++)
				if(MissVector[i]==0)
				{
					EarliestMiss=i;
					break;
				}
			if(EarliestMiss>Sn)
			{
				Sn=Sn+w;
				Sb=Sb+w;
				printf("Moving window forward \n");
			}
		}
		printf("Sending request for packet %d\n",EarliestMiss);
		sprintf(buff,"%d",EarliestMiss);
		write(s2,buff,strlen(buff));
	}
	close(s2);
	close(s1);
	printf("Server closed\n");
}
