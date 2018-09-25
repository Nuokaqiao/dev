/*************************************************************************
	> File Name: pipe1.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月22日 星期三 10时18分39秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

#define BUF_SIZE 30

int main(int argc,char **argv)
{
	int fds[2];
	char str[] = "Who are you?";
	char buf[BUF_SIZE];
	pid_t pid;

	pipe(fds);
	pid = fork();
	if(pid == 0){
		write(fds[1],str,sizeof(str));
	} else {
		read(fds[0],buf,BUF_SIZE);
		puts(buf);
	}
	return 0;
}
