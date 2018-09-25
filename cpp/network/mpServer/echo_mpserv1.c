/*************************************************************************
	> File Name: echo_mpserv.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月20日 星期一 12时46分25秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);
void read_childproc(int sig);

int main(int argc,char ** argv)
{
	int serv_sock,clnt_sock;
	struct sockaddr_in serv_adr,clnt_adr;

	pid_t pid;
	struct sigaction act;
	socklen_t adr_sz;
	int str_len,state;
	char buf[BUF_SIZE];
	if(argc != 2){
		printf("Usage: %s <port> \n",argv[0]);
		exit(1);
	}

	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD,&act,0);
	serv_sock = socket(PF_INET,SOCK_STREAM,0);
	memset(&serv_adr,0,sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if(listen(serv_sock,5) == -1)
		error_handling("listen() error");
	while(1){
		adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&adr_sz);
		if(clnt_sock == -1)
			continue;
		else 
			puts("new client connected..");
		pid = fork();

		if(pid == -1){
			close(clnt_sock);
			continue;
		}
		/*
if(pid == 0){ 
            close(serv_sock);
			int send_len = 0;
            while((str_len = read(clnt_sock,buf,BUF_SIZE)) != 0){ 
                printf("received %d size \n",str_len);
                int send_len = write(clnt_sock,buf,str_len);
                printf("sended %d size \n",send_len);
            }   
            close(clnt_sock);
            puts("client disconnecetd...");
            return 0;
}
*/
		if(pid == 0){
			close(serv_sock);
			int send_len = 0;
          //while((str_len = read(clnt_sock,buf,BUF_SIZE)) != 0){ 
			while((str_len = read(clnt_sock,buf,BUF_SIZE)) !=0){
				printf("receive length =: %d \n",str_len);
				if((send_len = write(clnt_sock,buf,str_len)) != str_len)
					error_handling("write() error");
				printf("send length =: %d \n",send_len);
			}

			close(clnt_sock);
			puts("client disconnected ...");
			return 0;
		}
		 else {
			close(clnt_sock);
		}
	}
	close(serv_sock);
	return 0;
}

void read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1,&status,WNOHANG);
	printf("removed proc: %d \n",pid);

}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\0',stderr);
	exit(1);
}
