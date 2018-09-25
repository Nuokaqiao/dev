/*************************************************************************
	> File Name: uecho_client.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年07月28日 星期六 14时40分55秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc,char** argv)
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t adr_sz;
	struct sockaddr_in serv_adr,clnt_adr;
	if(argc != 3){
		printf("Usage: %s <IP> <port>\n",argv[0]);;
		exit(1);
	}

	if((sock = socket(PF_INET,SOCK_DGRAM,0)) == -1)
		error_handling("sock() error");
	memset(&serv_adr,0,sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	while(1){
		fputs("Insert message(q to QUIT): ",stdout);
		fgets(message,sizeof(message),stdin);
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
			break;
		sendto(sock,message,strlen(message),0,
				(struct sockaddr*)&serv_adr,sizeof(serv_adr));
		adr_sz = sizeof(from_adr);
		str_len = recvfrom(sock,message,BUF_SIZE,0,
				(struct sockaddr*)&from_adr,&adr_sz);
		message[str_len] = 0;
		printf("Message from server: %s\n",message);

	}
	close(sock);
	return 0;
}
void error_handling(char* message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
