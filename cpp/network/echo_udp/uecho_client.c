/*************************************************************************
	> File Name: eocho_con_client.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月18日 星期六 19时38分18秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc,char **argv)
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t adr_sz;

	struct sockaddr_in serv_adr;
	if(argc != 3){
		printf("Usage: %s <IP> <port>\n",argv[0]);
		exit(1);
	}

	sock = socket(PF_INET,SOCK_DGRAM,0);
	if(sock == -1){
		error_handling("socket() error");
	}
	memset(&serv_adr,0,sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	connect(sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr));

	while(1){
		fputs("Insert message(q to quit): ",stdout);
		fgets(message,sizeof(message),stdin);
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
			break;
		write(sock,message,strlen(message));
		str_len = read(sock,message,sizeof(message) - 1);

		message[str_len] = 0;
		printf("Message from server:%s",message);
	}
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
