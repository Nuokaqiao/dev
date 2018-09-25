/*************************************************************************
	> File Name: echo_server.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年07月27日 星期五 14时38分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0
void error_handling(char *message);

int main(int argc,char** argv)
{
	int serv_sock,clnt_sock;
	char message[BUF_SIZE];
	int option;
	int str_len = 0,i;

	struct sockaddr_in serv_addr,clnt_addr;
	socklen_t clnt_adr_sz,optlen;

	if(argc != 2){
		printf("Usage: %s <port>\n",argv[0]);
		exit(1);
	}

	if((serv_sock = socket(PF_INET,SOCK_STREAM,0)) == -1){
		error_handling("socket() error!");
	}
	
	optlen = sizeof(option);
	option = TRUE;
	setsockopt(serv_sock,SOL_SOCKET,SO_REUSEADDR,(char*)&option,optlen);

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
		error_handling("bind() error!");
	}

	if(listen(serv_sock,5) == -1){
		error_handling("listen() error!");
	}

	clnt_adr_sz = sizeof(clnt_addr);
	for(i = 0; i < 5; ++i){
		if((clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_adr_sz)) == -1){
			error_handling("accept() error!");
		}
		else 
			printf("Connected client %d \n",i + 1);
		while((str_len = read(clnt_sock,message,BUF_SIZE)) != 0){
			write(clnt_sock,message,str_len);
		}
		close(clnt_sock);
	}
	close(serv_sock);
	return 0;

}

void error_handling(char* message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}