/*************************************************************************
	> File Name: uecho_server.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年07月28日 星期六 14时29分26秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char* message);

int main(int argc,char** argv)
{
	int serv_sock;
	char message[BUF_SIZE];
	int str_len,i;
	socklen_t adr_sz;
	struct sockaddr_in my_adr,your_adr;

	if(argc != 2){
		printf("Usage: %s <port>\n",argv[0]);
		exit(1);
	}

	if((serv_sock = socket(PF_INET,SOCK_DGRAM,0)) == -1){
		error_handling("socket() error!");
	}

	memset(&my_adr,0,sizeof(my_adr));
	my_adr.sin_family = AF_INET;
	my_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_adr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*)&my_adr,sizeof(my_adr)) == -1)
		error_handling("bind() error");
	for(i = 0; i < 3; ++i){
		sleep(5);
		adr_sz = sizeof(your_adr);
		str_len = recvfrom(serv_sock,message,BUF_SIZE,0
				,(struct sockaddr*)&your_adr,&adr_sz);
		printf("Message %d: %s\n",i + 1,message);
	}
	/*while(1){
		clnt_adr_sz = sizeof(clnt_adr_sz);;
		str_len = recvfrom(serv_sock,message,BUF_SIZE,0,
				(struct sockaddr*)&clnt_adr,&clnt_adr_sz);
		sendto(serv_sock,message,str_len,0,
				(struct sockaddr*)&clnt_adr,clnt_adr_sz);

	}
	*/
	close(serv_sock);
	return 0;

}

void error_handling(char* message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
