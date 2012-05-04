#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

main()
{
	int sockfd,newsockfd,clilen,filedes,i=0,len,n;
	char buf[1024];
	struct sockaddr_in serv_addr,cli_addr;
	serv_addr.sin_family=PF_INET;
	serv_addr.sin_port=htons(6060);
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	sockfd=socket(PF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	printf("Server started..\n");
	listen(sockfd,5);
	clilen=sizeof(cli_addr);
	newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
	printf("client connected..%s\n",inet_ntoa(cli_addr.sin_addr));
	len=read(newsockfd,buf,1024);
	buf[len-1]='\0';
	filedes=open(buf,O_RDWR);
	printf("reading \n");
	n=read(filedes,buf,1024);
	write(newsockfd,buf,n);
	printf("Written..\n");
	close(newsockfd);
	close(sockfd);
}
