#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc,char* argv[])
{
	int sockfd,newsockfd,portno,no,i;
	socklen_t clilen;
	char buffer[256],ch[256];
	FILE *fp;
	struct sockaddr_in serv_addr,cli_addr;
	int n;
	if(argc<2)
	{
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		error("ERROR opening socket");
	bzero((char*) &serv_addr,sizeof(serv_addr));
	portno=atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htnos(portno);
	
	if(bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
		error("ERROR on Binding");
	listen(sockfd,5);
	clilen= sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,&clilen);
	if(newsockfd<0)
		error("ERROR on accept");
	bzero(buffer,256);
	read(newsockfd,buffer,255);
	printf("Recieved Request for Procedure call .. \n");

	printf("entering Server stub .. \n");
	fp=fopen(buffer,"r");
	printf("Executed Procedure Locally ... \n");
	fgets(ch,256,fp);
	printf("sending the output ... \n");
	while(!feof(fp))
	{
		write(newsockfd,ch,strlen(ch));
		fgets(ch,256,fp);
	} 
	strcpy(buffer,"@");
	write(newsockfd,buffer,strlen(buffer));
	close(newsockfd);
	close(sockfd);
	return 0;	
}
