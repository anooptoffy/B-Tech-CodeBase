#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,newsockfd,n,m,fd,clilen,len;    
	char buf[1024];
	struct sockaddr_in cli_addr;
	cli_addr.sin_family=PF_INET;
	cli_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	cli_addr.sin_port=htons(6060);

	sockfd=socket(PF_INET,SOCK_STREAM,0);
	printf("Client started..\n");
	connect(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
	printf("Connecting to Server..\n");
	printf("enter the file name/path.....\n");
	fflush(stdin);
	fflush(stdout);
	n=read(0,buf,1024);
	buf[n]='\0';
	fd=creat(buf,O_RDWR);
	write(sockfd,buf,n);
	printf("file name send to server \n ");
	m=read(sockfd,buf,1024);
	write(fd,buf,m);
	printf("contents of the file \n");
	write(1,buf,m);
	printf("over \n");
	close(sockfd);
}

