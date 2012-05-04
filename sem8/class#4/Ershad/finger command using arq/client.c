#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

char buffer[256];

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

void finger(int sockfd,char* command)
{
	printf("Entered client stub ...\n");
	strcpy(buffer,command);
	printf("Executing Remote Finger command ... \n");
	write(sockfd,buffer,strlen(buffer));
	
	while(1)
	{
		bzero(buffer,256);	
		read(sockfd,buffer,255);
		if(buffer[0]=='@')
			break;
		printf("%s",buffer);
	}
	
}

int main(int argc,char* argv[])
{
	int sockfd,portno,n,valid=1;
	struct sockaddr_in serv_addr;
	char ky;
	char command[50];
	
	if(argc<3)
	{
		fprintf(stderr,"usage %s hostname port \n",argv[0]);
		exit(0);
	}
	
	portno=atoi(argv[2]);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		error("ERROR opening socket");
	bzero((char *) &serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(portno);
	
	if(connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
		error("ERROR connecting");
	printf("Enter the command : ");
	gets(command);
	printf("Press any Key to Execute Finger Utility using RPC ... \n");
	scanf("%c",&ky);
	printf("Calling Local Finger Command ... \n");
	finger(sockfd,command);
	printf("Executed successfully!!\n");
	
	close(sockfd);
	return 0;
}
