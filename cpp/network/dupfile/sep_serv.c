/*************************************************************************
	> File Name: sep_serv.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月24日 星期五 10时43分00秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc,char **argv)
{
	int serv_sock,clnt_sock;
	FILE *readfp;
	FILE *writefp;

	struct sockaddr_in serv_adr,clnt_adr;
	socklen_t clnt_adr_sz;
	char buf[BUF_SIZE];

	serv_sock = socket(PF_INET,SOCK_STREAM,0);
    memset(&serv_adr,0,sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
	
    bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr)); 
	listen(serv_sock,5);

	clnt_adr_sz = sizeof(clnt_adr);
	if((clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&clnt_adr_sz)) == -1)
		printf("accept error \n");

	readfp = fdopen(clnt_sock,"r");
	writefp = fdopen(clnt_sock,"w");

	fputs("FROM SERVER: Hi client! \n",writefp);
	fputs("I Love all of the world \n",writefp);
	fputs("You are awesome! \n",writefp);
	fflush(writefp);

	fclose(writefp);
	fgets(buf,sizeof(buf),readfp);
	fputs(buf,stdout);
	fclose(readfp);
	return 0;
}
