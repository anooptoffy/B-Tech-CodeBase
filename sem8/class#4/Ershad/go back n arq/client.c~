#include <stdio.h>
#include <string.h>
#include <netdb.h>

int connectto(char* ip,int port)
{
	int s;
	struct sockaddr_in seraddr;
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=inet_addr(ip);
	seraddr.sin_port=htons(port);

	s=socket(AF_INET,SOCK_STREAM,0);
	if(connect(s,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
	{
		printf("Connection Failed\n");
		return -1;
	}
	return s;
}

void sendpacket(int s1, int i, int r)
{
	int p;
	char buff[256];
	p=rand()%100;
	printf("Sending packet %d\n",i);
	sprintf(buff,"%d",i);
	if(p>=r)
		write(s1,buff,strlen(buff));
}

int waittoread(int s1)
{
	fd_set fds;
	struct timeval timeout;
	int rc,result;
	
	/* set time limit */
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	
	/* create a descriptor set containing out two sockets */
	FD_ZERO(&fds);
	FD_SET(s1, &fds);
	rc = select(sizeof(fds)*8,&fds,NULL,NULL,&timeout);
	if(rc==-1)
	{
		perror("select failed");
		return -1;
	}
	result = 0;
	if(rc>0)
		result=1;
	return result;
}

int main(int argc,char* argv[])
{
	int s1,port,i,n,r,w,Sb,Sn,Rn,flag;
	char buff[256];
	flag=0;
	
	if(argc<2)
	{
		printf("Port? : ");
		scanf("%d",&port);
		gets(buff);
	}
	else
		port=atoi(argv[1]);
	s1=connectto("127.0.0.1",port);
	
	printf("Enter the total number of packets to be sent : ");
	scanf("%d",&n);
	printf("Enter the percentage packet lose rate : ");
	scanf("%d",&r);
	printf("Enter the window size : ");
	scanf("%d",&w);
	Sb=0;Sn=w-1;
	
	while(1)
	{
		for(i=Sb;i<=Sn;i++)
		{
			if(i<n)
				sendpacket(s1,i,r);
			if(waittoread(s1)==1)
			{
				bzero(&buff,256);
				read(s1,buff,255);
				printf("Request for packet %s received \n",buff);
				Rn=atoi(buff);
				if(Rn>Sb)
				{
					if(Rn>=n)
					{
						flag = 1;
						break;		
					}
					printf("Moving window forward \n");
					Sn=Sn+(Rn-Sb);
					Sb=Rn;
				}
				break;
			}
		}
		if(flag)
			break;
	}
	
	close(s1);
	printf("Client closed \n");
}
