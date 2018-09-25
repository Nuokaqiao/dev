/*************************************************************************
	> File Name: echo_server.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年07月27日 星期五 14时38分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void read_childproc(int sig);
void error_handling(char *message);

int main(int argc,char** argv)
{
	int serv_sock,clnt_sock;

	char message[BUF_SIZE];
	int str_len = 0,i,state;
	int	fds[2];

	pid_t pid;
	struct sockaddr_in serv_addr,clnt_addr;
	socklen_t clnt_adr_sz;

	struct sigaction act;
	if(argc != 2){
		printf("Usage: %s <port>\n",argv[0]);
		exit(1);
	}

	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD,&act,0);

	if((serv_sock = socket(PF_INET,SOCK_STREAM,0)) == -1){
		error_handling("socket() error!");
	}

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

	pipe(fds);
	pid = fork();
	if(pid == 0){
		FILE *fp = fopen("echomsg.txt","wt");
		char msgbuf[BUF_SIZE];
		int i,len;

		for(i = 0; i < 10; ++i){
			len = read(fds[0],msgbuf,BUF_SIZE);
			fwrite((void*)msgbuf,1,len,fp);
		}
		fclose(fp);
		return 0;
	}
	while(1){
		clnt_adr_sz = sizeof(clnt_addr);
		if((clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_adr_sz)) == -1){
			continue;
		}
		else 
			printf("Connected client ");
		pid = fork();
		if(pid == -1){
			close(clnt_sock);
			continue;
		}
		if(pid == 0){
			close(serv_sock);
			while((str_len = read(clnt_sock,message,BUF_SIZE)) != 0){
				write(clnt_sock,message,str_len);
				write(fds[1],message,str_len);
			}
			close(clnt_sock);
			puts("client disconnecetd...");
			return 0;
		} else 
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

void read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1,&status,WNOHANG);
	printf("removed proc: %d \n",pid);
}
