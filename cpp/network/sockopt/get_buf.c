/*************************************************************************
	> File Name: get_buf.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月19日 星期日 14时22分11秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc,char **argv)
{
	int sock;
	int snd_buf,rcv_buf,state;
	socklen_t len;

	sock = socket(PF_INET,SOCK_STREAM,0);
	len = sizeof(snd_buf);
	state = getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void*)&snd_buf,&len);
	if(state)
		error_handling("gethostopt() .. error");
	len = sizeof(rcv_buf);
	state = getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(void*)&rcv_buf,&len);
	if(state)
		error_handling("getsockopt() error");
	printf("Input buffer size: %d\n",rcv_buf);
	printf("Output buffer size: %d\n",snd_buf);
	return 0;
}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
