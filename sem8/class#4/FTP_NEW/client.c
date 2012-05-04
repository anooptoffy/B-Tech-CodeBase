#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>

void parse(char *a,char b[20][10])
{
	int i=0,j=0,k=0;
	while(a[i]!=0)
	{
		if(a[i]!=' ')
		{
			b[j][k]='\0';
			j++;
			k=0;
		}
		else
		{
			b[j][k]=a[i];
			k++;
		}
		i++;
	}
	b[j][k]='\0';
}

int connectto(char *name,int portno)
{
	int sockid,n=1,f;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	if((sockid=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("Error Creating socket \n");
		return;
	}
	server=gethostbyname(name);
	if(server==NULL)
	{
		printf("Host not found\n");
		return;
	}
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	bcopy((char *)server->h_addr,(char*)&serv_addr.sin_addr,server->h_length);

	serv_addr.sin_port=htons(portno);
	
	if(connect(sockid,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
		printf("Error Connecting\n");

	return sockid;
}

int main()
{
	int sockid,tsock,portno,n=1,f,fp,tport;
	char cline[30];
	char buffer[512],b[20][10]={0};

	printf("Enter the destination port\n");
	scanf("%d",&portno);
	
	gets(buffer);
	sockid=connectto("localhost",portno);
	
	while(1)
	{
		printf("$: ");
		bzero(cline,30);
		gets(cline);
		parse(cline,b);
		n=write(sockid,cline,strlen(cline));
		if(n<0)
			printf("error writing to the socket \n");
		
		if(strcmp(b[0],"put")==0)
		{
			memset(buffer,0,512);
			n=read(sockid,buffer,256);
			
			tport=atoi(buffer);
			tsock=connectto("localhost",tport);
			fp=open(b[1],O_RDONLY);
			
			while((f=read(fp,buffer,4))>0)
			{
				write(tsock,buffer,f);
			}
			close(tsock);
			close(fp);
		}
		else if(strcmp(b[0],"get")==0)
		{
			memset(buffer,0,512);
			n=read(sockid,buffer,256);
			tport=atoi(buffer);
			tsock=connectto("localhost",tport);

			fp=open(b[1],O_CREAT|O_WRONLY);

			while((f=read(tsock,buffer,4))>0)
				write(fp,buffer,f);
			close(tsock);
			fchmod(fp,0777);
			close(fp);
		}
		else if(strcmp(cline,"exit")==0)
			break;
		bzero(buffer,255);
		n=read(sockid,buffer,256);
		printf("%s",buffer);
	}
	close(sockid);
		
	if(shutdown(sockid,SHUT_RDWR)==0)
		printf("client has been terminated\n");
}

