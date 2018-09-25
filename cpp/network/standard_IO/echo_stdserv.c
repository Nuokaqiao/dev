/*************************************************************************
	> File Name: echo_stdserv.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月23日 星期四 18时35分07秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc,char **argv)
{
	int serv_sock,clnt_sock;
	char message[BUF_SIZE];
	int str_len,i;

	struct sockaddr_in serv_adr;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_sz;
	FILE *readfp;
	FILE *writefp;
	if(argc != 2){
		printf("Usage: %s <port> \n",argv[1]);
		exit(1);
	}

	if((serv_sock = socket(PF_INET,SOCK_STREAM,0)) == -1)
		error_handling("socket() error");
	memset(&serv_adr,0,sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr)) == -1)
			error_handling("bind error");
	if(listen(serv_sock,5) == -1)
		error_handling("listen() error");

	clnt_sz = sizeof(clnt_adr);

	for(i = 0; i < 5; ++i){
		if((clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&clnt_sz)) == -1)
			error_handling("accept() error");
		else 
			printf("Connected client %d \n",i);
		readfp = fdopen(clnt_sock,"r");
		writefp = fdopen(clnt_sock,"w");
		while(readfp){
			fgets(message,BUF_SIZE,readfp);
			fputs(message,writefp);
			fflush(writefp);
		}
		fclose(readfp);
		fclose(writefp);
	}
	close(serv_sock);
	return 0;

}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
